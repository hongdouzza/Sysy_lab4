%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ast.h"

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int yylineno;
extern char *yytext;

int line_num = 1;
ASTNode *root = NULL;
void yyerror(const char *s);

%}

%union {
    int ival;
    double fval;
    char *sval;
    ASTNode *node;
    ASTNode **node_list;
    int *int_list;
    struct {
        ASTNode **nodes;
        int count;
    } node_list_with_count;
}

%token <ival> INTEGER
%token <sval> IDENTIFIER FLOAT_CONST
%token INT FLOAT VOID CONST
%token IF ELSE WHILE BREAK CONTINUE RETURN
%token ADD SUB MUL DIV MOD
%token EQ NE LT LE GT GE AND OR NOT
%token ASSIGN SEMICOLON COMMA
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE

%type <node> program comp_unit decl func_def func_param
%type <node> var_decl var_def array_decl
%type <node> stmt block_stmt expr_stmt if_stmt while_stmt return_stmt
%type <node> expr unary_expr postfix_expr primary_expr
%type <node> lval assign_expr
%type <node_list_with_count> func_params stmt_list expr_list

%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left ADD SUB
%left MUL DIV MOD
%right NOT
%right UMINUS

%start program

%%

program:
    comp_unit {
        root = $1;
        $$ = $1;
    }
    ;

comp_unit:
    comp_unit decl {
        ASTNode **new_decls = (ASTNode**)malloc(sizeof(ASTNode*) * ($1->u.program.decl_count + 1));
        for (int i = 0; i < $1->u.program.decl_count; i++) {
            new_decls[i] = $1->u.program.decls[i];
        }
        new_decls[$1->u.program.decl_count] = $2;
        $$ = create_program(new_decls, $1->u.program.decl_count + 1);
        root = $$;
        free($1->u.program.decls);
        free($1);
    }
    | decl {
        ASTNode **decls = (ASTNode**)malloc(sizeof(ASTNode*));
        decls[0] = $1;
        $$ = create_program(decls, 1);
        root = $$;
    }
    ;

decl:
    func_def { $$ = $1; }
    | var_decl SEMICOLON { $$ = $1; }
    | array_decl SEMICOLON { $$ = $1; }
    ;

func_def:
    INT IDENTIFIER LPAREN func_params RPAREN block_stmt {
        $$ = create_func_def($2, $4.nodes, $4.count, $6);
        free($4.nodes);
    }
    | VOID IDENTIFIER LPAREN func_params RPAREN block_stmt {
        $$ = create_func_def($2, $4.nodes, $4.count, $6);
        free($4.nodes);
    }
    | INT IDENTIFIER LPAREN RPAREN block_stmt {
        $$ = create_func_def($2, NULL, 0, $5);
    }
    | VOID IDENTIFIER LPAREN RPAREN block_stmt {
        $$ = create_func_def($2, NULL, 0, $5);
    }
    ;

func_params:
    func_params COMMA func_param {
        ASTNode **new_params = (ASTNode**)malloc(sizeof(ASTNode*) * ($1.count + 1));
        for (int i = 0; i < $1.count; i++) {
            new_params[i] = $1.nodes[i];
        }
        new_params[$1.count] = $3;
        free($1.nodes);
        $$.nodes = new_params;
        $$.count = $1.count + 1;
    }
    | func_param {
        ASTNode **params = (ASTNode**)malloc(sizeof(ASTNode*));
        params[0] = $1;
        $$.nodes = params;
        $$.count = 1;
    }
    ;

func_param:
    INT IDENTIFIER {
        $$ = create_var_decl($2, 0, NULL);
    }
    | INT IDENTIFIER LBRACKET RBRACKET {
        int dims[] = {0};
        $$ = create_array_decl($2, dims, 1, 0);
    }
    ;

var_decl:
    INT var_def {
        $$ = $2;
    }
    | CONST INT var_def {
        $$ = $3;
        $$->u.var_decl.is_const = 1;
    }
    ;

var_def:
    IDENTIFIER {
        $$ = create_var_decl($1, 0, NULL);
    }
    | IDENTIFIER ASSIGN expr {
        $$ = create_var_decl($1, 0, $3);
    }
    ;

array_decl:
    INT IDENTIFIER LBRACKET INTEGER RBRACKET {
        int *dims = (int*)malloc(sizeof(int));
        dims[0] = $4;
        $$ = create_array_decl($2, dims, 1, 0);
    }
    | CONST INT IDENTIFIER LBRACKET INTEGER RBRACKET {
        int *dims = (int*)malloc(sizeof(int));
        dims[0] = $5;
        $$ = create_array_decl($3, dims, 1, 1);
    }
    ;

block_stmt:
    LBRACE stmt_list RBRACE {
        $$ = create_block($2.nodes, $2.count);
        // 不要释放$2.nodes，因为create_block只是保存了指针
        // free($2.nodes);  // 这会导致悬空指针
    }
    | LBRACE RBRACE {
        $$ = create_block(NULL, 0);
    }
    ;

stmt_list:
    stmt_list stmt {
        ASTNode **new_stmts = (ASTNode**)malloc(sizeof(ASTNode*) * ($1.count + 1));
        for (int i = 0; i < $1.count; i++) {
            new_stmts[i] = $1.nodes[i];
        }
        new_stmts[$1.count] = $2;
        free($1.nodes);
        $$.nodes = new_stmts;
        $$.count = $1.count + 1;
    }
    | stmt {
        ASTNode **stmts = (ASTNode**)malloc(sizeof(ASTNode*));
        stmts[0] = $1;
        $$.nodes = stmts;
        $$.count = 1;
    }
    ;

stmt:
    expr_stmt { $$ = $1; }
    | block_stmt { $$ = $1; }
    | if_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | return_stmt { $$ = $1; }
    | var_decl SEMICOLON { $$ = $1; }
    | array_decl SEMICOLON { $$ = $1; }
    | BREAK SEMICOLON { $$ = NULL; }  // TODO: 实现break
    | CONTINUE SEMICOLON { $$ = NULL; }  // TODO: 实现continue
    ;

expr_stmt:
    expr SEMICOLON {
        $$ = create_expr_stmt($1);
    }
    | SEMICOLON {
        $$ = NULL;
    }
    ;

if_stmt:
    IF LPAREN expr RPAREN stmt {
        $$ = create_if($3, $5, NULL);
    }
    | IF LPAREN expr RPAREN stmt ELSE stmt {
        $$ = create_if($3, $5, $7);
    }
    ;

while_stmt:
    WHILE LPAREN expr RPAREN stmt {
        $$ = create_while($3, $5);
    }
    ;

return_stmt:
    RETURN SEMICOLON {
        $$ = create_return(NULL);
    }
    | RETURN expr SEMICOLON {
        $$ = create_return($2);
    }
    ;

expr:
    assign_expr { $$ = $1; }
    | expr OR expr { $$ = create_binary_op(OP_OR, $1, $3); }
    | expr AND expr { $$ = create_binary_op(OP_AND, $1, $3); }
    | expr EQ expr { $$ = create_binary_op(OP_EQ, $1, $3); }
    | expr NE expr { $$ = create_binary_op(OP_NE, $1, $3); }
    | expr LT expr { $$ = create_binary_op(OP_LT, $1, $3); }
    | expr LE expr { $$ = create_binary_op(OP_LE, $1, $3); }
    | expr GT expr { $$ = create_binary_op(OP_GT, $1, $3); }
    | expr GE expr { $$ = create_binary_op(OP_GE, $1, $3); }
    | expr ADD expr { $$ = create_binary_op(OP_ADD, $1, $3); }
    | expr SUB expr { $$ = create_binary_op(OP_SUB, $1, $3); }
    | expr MUL expr { $$ = create_binary_op(OP_MUL, $1, $3); }
    | expr DIV expr { $$ = create_binary_op(OP_DIV, $1, $3); }
    | expr MOD expr { $$ = create_binary_op(OP_MOD, $1, $3); }
    ;

assign_expr:
    unary_expr { $$ = $1; }
    | lval ASSIGN assign_expr {
        $$ = create_assign($1, $3);
    }
    ;

unary_expr:
    postfix_expr { $$ = $1; }
    | ADD unary_expr { $$ = $2; }
    | SUB unary_expr { $$ = create_unary_op(OP_NEG, $2); }
    | NOT unary_expr { $$ = create_unary_op(OP_NOT, $2); }
    ;

postfix_expr:
    primary_expr { $$ = $1; }
    | IDENTIFIER LPAREN expr_list RPAREN {
        $$ = create_func_call($1, $3.nodes, $3.count);
        free($3.nodes);
    }
    | IDENTIFIER LPAREN RPAREN {
        $$ = create_func_call($1, NULL, 0);
    }
    | lval { $$ = $1; }
    ;

primary_expr:
    INTEGER { $$ = create_integer($1); }
    | FLOAT_CONST {
        double val = atof((char*)$1);
        $$ = create_float(val);
        free((char*)$1);
    }
    | LPAREN expr RPAREN { $$ = $2; }
    ;

lval:
    IDENTIFIER {
        $$ = create_identifier($1);
    }
    | IDENTIFIER LBRACKET expr RBRACKET {
        ASTNode **indices = (ASTNode**)malloc(sizeof(ASTNode*));
        indices[0] = $3;
        $$ = create_array_access($1, indices, 1);
    }
    ;

expr_list:
    expr_list COMMA expr {
        ASTNode **new_args = (ASTNode**)malloc(sizeof(ASTNode*) * ($1.count + 1));
        for (int i = 0; i < $1.count; i++) {
            new_args[i] = $1.nodes[i];
        }
        new_args[$1.count] = $3;
        free($1.nodes);
        $$.nodes = new_args;
        $$.count = $1.count + 1;
    }
    | expr {
        ASTNode **args = (ASTNode**)malloc(sizeof(ASTNode*));
        args[0] = $1;
        $$.nodes = args;
        $$.count = 1;
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Near: %s\n", yytext);
}

int main(int argc, char **argv) {
    FILE *input;
    
    if (argc > 1) {
        input = fopen(argv[1], "r");
        if (!input) {
            fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = input;
    } else {
        yyin = stdin;
    }
    
    root = NULL;
    if (yyparse() == 0) {
        printf("Parse successful!\n");
        if (root) {
            printf("\n=== AST ===\n");
            print_ast(root, 0);
            printf("\n");
            free_ast(root);
        }
    } else {
        fprintf(stderr, "Parse failed!\n");
        return 1;
    }
    
    if (input) fclose(input);
    return 0;
}

