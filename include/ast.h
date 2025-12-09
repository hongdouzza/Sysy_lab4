#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AST节点类型
typedef enum {
    AST_PROGRAM,
    AST_FUNC_DEF,
    AST_FUNC_DECL,
    AST_VAR_DECL,
    AST_VAR_DEF,
    AST_ARRAY_DECL,
    AST_ARRAY_DEF,
    AST_ASSIGN,
    AST_IF,
    AST_WHILE,
    AST_RETURN,
    AST_BLOCK,
    AST_BINARY_OP,
    AST_UNARY_OP,
    AST_IDENTIFIER,
    AST_INTEGER,
    AST_FLOAT,
    AST_FUNC_CALL,
    AST_ARRAY_ACCESS,
    AST_EXPR_STMT
} ASTNodeType;

// 二元运算符类型
typedef enum {
    OP_ADD,      // +
    OP_SUB,      // -
    OP_MUL,      // *
    OP_DIV,      // /
    OP_MOD,      // %
    OP_EQ,       // ==
    OP_NE,       // !=
    OP_LT,       // <
    OP_LE,       // <=
    OP_GT,       // >
    OP_GE,       // >=
    OP_AND,      // &&
    OP_OR        // ||
} BinaryOpType;

// 一元运算符类型
typedef enum {
    OP_NEG,      // -
    OP_NOT       // !
} UnaryOpType;

// AST节点结构
typedef struct ASTNode {
    ASTNodeType type;
    int line_no;
    union {
        // 标识符
        struct {
            char *name;
        } identifier;
        
        // 整数常量
        struct {
            int value;
        } integer;
        
        // 浮点数常量
        struct {
            double value;
        } float_val;
        
        // 二元运算
        struct {
            BinaryOpType op;
            struct ASTNode *left;
            struct ASTNode *right;
        } binary_op;
        
        // 一元运算
        struct {
            UnaryOpType op;
            struct ASTNode *operand;
        } unary_op;
        
        // 变量声明
        struct {
            char *name;
            int is_const;
            struct ASTNode *init_value;
        } var_decl;
        
        // 数组声明
        struct {
            char *name;
            int *dimensions;
            int dim_count;
            int is_const;
        } array_decl;
        
        // 赋值
        struct {
            struct ASTNode *lvalue;
            struct ASTNode *rvalue;
        } assign;
        
        // if语句
        struct {
            struct ASTNode *condition;
            struct ASTNode *then_stmt;
            struct ASTNode *else_stmt;
        } if_stmt;
        
        // while循环
        struct {
            struct ASTNode *condition;
            struct ASTNode *body;
        } while_stmt;
        
        // return语句
        struct {
            struct ASTNode *value;
        } return_stmt;
        
        // 函数定义
        struct {
            char *name;
            struct ASTNode **params;
            int param_count;
            struct ASTNode *body;
        } func_def;
        
        // 函数调用
        struct {
            char *name;
            struct ASTNode **args;
            int arg_count;
        } func_call;
        
        // 数组访问
        struct {
            char *name;
            struct ASTNode **indices;
            int index_count;
        } array_access;
        
        // 语句块
        struct {
            struct ASTNode **stmts;
            int stmt_count;
        } block;
        
        // 程序
        struct {
            struct ASTNode **decls;
            int decl_count;
        } program;
    } u;
} ASTNode;

// 函数声明
ASTNode* create_program(ASTNode **decls, int count);
ASTNode* create_func_def(char *name, ASTNode **params, int param_count, ASTNode *body);
ASTNode* create_var_decl(char *name, int is_const, ASTNode *init_value);
ASTNode* create_array_decl(char *name, int *dims, int dim_count, int is_const);
ASTNode* create_assign(ASTNode *lvalue, ASTNode *rvalue);
ASTNode* create_if(ASTNode *condition, ASTNode *then_stmt, ASTNode *else_stmt);
ASTNode* create_while(ASTNode *condition, ASTNode *body);
ASTNode* create_return(ASTNode *value);
ASTNode* create_block(ASTNode **stmts, int count);
ASTNode* create_binary_op(BinaryOpType op, ASTNode *left, ASTNode *right);
ASTNode* create_unary_op(UnaryOpType op, ASTNode *operand);
ASTNode* create_identifier(char *name);
ASTNode* create_integer(int value);
ASTNode* create_float(double value);
ASTNode* create_func_call(char *name, ASTNode **args, int arg_count);
ASTNode* create_array_access(char *name, ASTNode **indices, int index_count);
ASTNode* create_expr_stmt(ASTNode *expr);

void print_ast(ASTNode *node, int indent);
void free_ast(ASTNode *node);

#endif // AST_H

