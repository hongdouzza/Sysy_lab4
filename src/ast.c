#include "../include/ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 创建程序节点
ASTNode* create_program(ASTNode **decls, int count) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_PROGRAM;
    node->line_no = 0;
    node->u.program.decls = decls;
    node->u.program.decl_count = count;
    return node;
}

// 创建函数定义节点
ASTNode* create_func_def(char *name, ASTNode **params, int param_count, ASTNode *body) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_FUNC_DEF;
    node->line_no = 0;
    node->u.func_def.name = strdup(name);
    node->u.func_def.params = params;
    node->u.func_def.param_count = param_count;
    node->u.func_def.body = body;
    return node;
}

// 创建变量声明节点
ASTNode* create_var_decl(char *name, int is_const, ASTNode *init_value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_VAR_DECL;
    node->line_no = 0;
    node->u.var_decl.name = strdup(name);
    node->u.var_decl.is_const = is_const;
    node->u.var_decl.init_value = init_value;
    return node;
}

// 创建数组声明节点
ASTNode* create_array_decl(char *name, int *dims, int dim_count, int is_const) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_ARRAY_DECL;
    node->line_no = 0;
    node->u.array_decl.name = strdup(name);
    node->u.array_decl.dimensions = dims;
    node->u.array_decl.dim_count = dim_count;
    node->u.array_decl.is_const = is_const;
    return node;
}

// 创建赋值节点
ASTNode* create_assign(ASTNode *lvalue, ASTNode *rvalue) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_ASSIGN;
    node->line_no = 0;
    node->u.assign.lvalue = lvalue;
    node->u.assign.rvalue = rvalue;
    return node;
}

// 创建if语句节点
ASTNode* create_if(ASTNode *condition, ASTNode *then_stmt, ASTNode *else_stmt) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_IF;
    node->line_no = 0;
    node->u.if_stmt.condition = condition;
    node->u.if_stmt.then_stmt = then_stmt;
    node->u.if_stmt.else_stmt = else_stmt;
    return node;
}

// 创建while循环节点
ASTNode* create_while(ASTNode *condition, ASTNode *body) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_WHILE;
    node->line_no = 0;
    node->u.while_stmt.condition = condition;
    node->u.while_stmt.body = body;
    return node;
}

// 创建return语句节点
ASTNode* create_return(ASTNode *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_RETURN;
    node->line_no = 0;
    node->u.return_stmt.value = value;
    return node;
}

// 创建语句块节点
ASTNode* create_block(ASTNode **stmts, int count) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_BLOCK;
    node->line_no = 0;
    node->u.block.stmts = stmts;
    node->u.block.stmt_count = count;
    return node;
}

// 创建二元运算节点
ASTNode* create_binary_op(BinaryOpType op, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_BINARY_OP;
    node->line_no = 0;
    node->u.binary_op.op = op;
    node->u.binary_op.left = left;
    node->u.binary_op.right = right;
    return node;
}

// 创建一元运算节点
ASTNode* create_unary_op(UnaryOpType op, ASTNode *operand) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_UNARY_OP;
    node->line_no = 0;
    node->u.unary_op.op = op;
    node->u.unary_op.operand = operand;
    return node;
}

// 创建标识符节点
ASTNode* create_identifier(char *name) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_IDENTIFIER;
    node->line_no = 0;
    node->u.identifier.name = strdup(name);
    return node;
}

// 创建整数常量节点
ASTNode* create_integer(int value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_INTEGER;
    node->line_no = 0;
    node->u.integer.value = value;
    return node;
}

// 创建浮点数常量节点
ASTNode* create_float(double value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_FLOAT;
    node->line_no = 0;
    node->u.float_val.value = value;
    return node;
}

// 创建函数调用节点
ASTNode* create_func_call(char *name, ASTNode **args, int arg_count) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_FUNC_CALL;
    node->line_no = 0;
    node->u.func_call.name = strdup(name);
    node->u.func_call.args = args;
    node->u.func_call.arg_count = arg_count;
    return node;
}

// 创建数组访问节点
ASTNode* create_array_access(char *name, ASTNode **indices, int index_count) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_ARRAY_ACCESS;
    node->line_no = 0;
    node->u.array_access.name = strdup(name);
    node->u.array_access.indices = indices;
    node->u.array_access.index_count = index_count;
    return node;
}

// 创建表达式语句节点
ASTNode* create_expr_stmt(ASTNode *expr) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_EXPR_STMT;
    node->line_no = 0;
    node->u.binary_op.left = expr;  // 复用结构
    return node;
}

// 打印AST（用于调试）
void print_ast(ASTNode *node, int indent) {
    if (!node) {
        printf("(null)\n");
        return;
    }
    
    for (int i = 0; i < indent; i++) printf("  ");
    
    switch (node->type) {
        case AST_PROGRAM:
            printf("Program (%d decls)\n", node->u.program.decl_count);
            if (node->u.program.decls) {
                for (int i = 0; i < node->u.program.decl_count; i++) {
                    if (node->u.program.decls[i]) {
                        print_ast(node->u.program.decls[i], indent + 1);
                    }
                }
            }
            break;
        case AST_FUNC_DEF:
            printf("FuncDef: %s\n", node->u.func_def.name ? node->u.func_def.name : "(null)");
            if (node->u.func_def.body) {
                print_ast(node->u.func_def.body, indent + 1);
            }
            break;
        case AST_VAR_DECL:
            printf("VarDecl: %s%s\n", 
                   node->u.var_decl.is_const ? "const " : "",
                   node->u.var_decl.name);
            if (node->u.var_decl.init_value) {
                print_ast(node->u.var_decl.init_value, indent + 1);
            }
            break;
        case AST_ARRAY_DECL:
            printf("ArrayDecl: %s%s[", 
                   node->u.array_decl.is_const ? "const " : "",
                   node->u.array_decl.name);
            if (node->u.array_decl.dimensions) {
                for (int i = 0; i < node->u.array_decl.dim_count; i++) {
                    if (i > 0) printf("][");
                    printf("%d", node->u.array_decl.dimensions[i]);
                }
            }
            printf("]\n");
            break;
        case AST_ASSIGN:
            printf("Assign\n");
            print_ast(node->u.assign.lvalue, indent + 1);
            print_ast(node->u.assign.rvalue, indent + 1);
            break;
        case AST_IF:
            printf("If\n");
            print_ast(node->u.if_stmt.condition, indent + 1);
            print_ast(node->u.if_stmt.then_stmt, indent + 1);
            if (node->u.if_stmt.else_stmt) {
                print_ast(node->u.if_stmt.else_stmt, indent + 1);
            }
            break;
        case AST_WHILE:
            printf("While\n");
            print_ast(node->u.while_stmt.condition, indent + 1);
            print_ast(node->u.while_stmt.body, indent + 1);
            break;
        case AST_RETURN:
            printf("Return\n");
            if (node->u.return_stmt.value) {
                print_ast(node->u.return_stmt.value, indent + 1);
            }
            break;
        case AST_BLOCK:
            printf("Block (%d stmts)\n", node->u.block.stmt_count);
            if (node->u.block.stmts) {
                for (int i = 0; i < node->u.block.stmt_count; i++) {
                    if (node->u.block.stmts[i]) {
                        print_ast(node->u.block.stmts[i], indent + 1);
                    }
                }
            }
            break;
        case AST_BINARY_OP: {
            const char *ops[] = {"+", "-", "*", "/", "%", "==", "!=", 
                                "<", "<=", ">", ">=", "&&", "||"};
            printf("BinaryOp: %s\n", ops[node->u.binary_op.op]);
            print_ast(node->u.binary_op.left, indent + 1);
            print_ast(node->u.binary_op.right, indent + 1);
            break;
        }
        case AST_UNARY_OP: {
            const char *ops[] = {"-", "!"};
            printf("UnaryOp: %s\n", ops[node->u.unary_op.op]);
            print_ast(node->u.unary_op.operand, indent + 1);
            break;
        }
        case AST_IDENTIFIER:
            printf("Identifier: %s\n", node->u.identifier.name ? node->u.identifier.name : "(null)");
            break;
        case AST_INTEGER:
            printf("Integer: %d\n", node->u.integer.value);
            break;
        case AST_FLOAT:
            printf("Float: %f\n", node->u.float_val.value);
            break;
        case AST_FUNC_CALL:
            printf("FuncCall: %s (%d args)\n", 
                   node->u.func_call.name ? node->u.func_call.name : "(null)", 
                   node->u.func_call.arg_count);
            if (node->u.func_call.args) {
                for (int i = 0; i < node->u.func_call.arg_count; i++) {
                    if (node->u.func_call.args[i]) {
                        print_ast(node->u.func_call.args[i], indent + 1);
                    }
                }
            }
            break;
        case AST_ARRAY_ACCESS:
            printf("ArrayAccess: %s", node->u.array_access.name ? node->u.array_access.name : "(null)");
            if (node->u.array_access.indices) {
                for (int i = 0; i < node->u.array_access.index_count; i++) {
                    printf("[");
                    if (node->u.array_access.indices[i]) {
                        // 打印索引表达式（简化版，不换行）
                        if (node->u.array_access.indices[i]->type == AST_IDENTIFIER) {
                            printf("%s", node->u.array_access.indices[i]->u.identifier.name);
                        } else if (node->u.array_access.indices[i]->type == AST_INTEGER) {
                            printf("%d", node->u.array_access.indices[i]->u.integer.value);
                        } else {
                            print_ast(node->u.array_access.indices[i], indent + 1);
                        }
                    }
                    printf("]");
                }
            }
            printf("\n");
            break;
        case AST_EXPR_STMT:
            printf("ExprStmt\n");
            if (node->u.binary_op.left) {
                print_ast(node->u.binary_op.left, indent + 1);
            }
            break;
        default:
            printf("Unknown AST node type: %d\n", node->type);
    }
}

// 释放AST节点
void free_ast(ASTNode *node) {
    if (!node) return;
    
    switch (node->type) {
        case AST_PROGRAM:
            for (int i = 0; i < node->u.program.decl_count; i++) {
                free_ast(node->u.program.decls[i]);
            }
            free(node->u.program.decls);
            break;
        case AST_FUNC_DEF:
            free(node->u.func_def.name);
            for (int i = 0; i < node->u.func_def.param_count; i++) {
                free_ast(node->u.func_def.params[i]);
            }
            if (node->u.func_def.params) free(node->u.func_def.params);
            free_ast(node->u.func_def.body);
            break;
        case AST_VAR_DECL:
            free(node->u.var_decl.name);
            free_ast(node->u.var_decl.init_value);
            break;
        case AST_ARRAY_DECL:
            free(node->u.array_decl.name);
            if (node->u.array_decl.dimensions) free(node->u.array_decl.dimensions);
            break;
        case AST_ASSIGN:
            free_ast(node->u.assign.lvalue);
            free_ast(node->u.assign.rvalue);
            break;
        case AST_IF:
            free_ast(node->u.if_stmt.condition);
            free_ast(node->u.if_stmt.then_stmt);
            free_ast(node->u.if_stmt.else_stmt);
            break;
        case AST_WHILE:
            free_ast(node->u.while_stmt.condition);
            free_ast(node->u.while_stmt.body);
            break;
        case AST_RETURN:
            free_ast(node->u.return_stmt.value);
            break;
        case AST_BLOCK:
            for (int i = 0; i < node->u.block.stmt_count; i++) {
                free_ast(node->u.block.stmts[i]);
            }
            free(node->u.block.stmts);
            break;
        case AST_BINARY_OP:
            free_ast(node->u.binary_op.left);
            free_ast(node->u.binary_op.right);
            break;
        case AST_UNARY_OP:
            free_ast(node->u.unary_op.operand);
            break;
        case AST_IDENTIFIER:
            free(node->u.identifier.name);
            break;
        case AST_FUNC_CALL:
            free(node->u.func_call.name);
            for (int i = 0; i < node->u.func_call.arg_count; i++) {
                free_ast(node->u.func_call.args[i]);
            }
            if (node->u.func_call.args) free(node->u.func_call.args);
            break;
        case AST_ARRAY_ACCESS:
            free(node->u.array_access.name);
            for (int i = 0; i < node->u.array_access.index_count; i++) {
                free_ast(node->u.array_access.indices[i]);
            }
            if (node->u.array_access.indices) free(node->u.array_access.indices);
            break;
        case AST_EXPR_STMT:
            // AST_EXPR_STMT的expr存储在binary_op.left中（临时复用）
            if (node->u.binary_op.left) {
                free_ast(node->u.binary_op.left);
            }
            break;
        default:
            break;
    }
    
    free(node);
}

