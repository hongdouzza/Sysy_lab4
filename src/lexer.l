%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ast.h"
#include "parser.tab.h"

extern YYSTYPE yylval;
extern int line_num;

%}

%option noyywrap
%option yylineno

%%

"int"           { return INT; }
"float"         { return FLOAT; }
"void"          { return VOID; }
"const"         { return CONST; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"return"        { return RETURN; }

"+"             { return ADD; }
"-"             { return SUB; }
"*"             { return MUL; }
"/"             { return DIV; }
"%"             { return MOD; }
"=="            { return EQ; }
"!="            { return NE; }
"<"             { return LT; }
"<="            { return LE; }
">"             { return GT; }
">="            { return GE; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }

"="             { return ASSIGN; }
";"             { return SEMICOLON; }
","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.sval = strdup(yytext);
    return IDENTIFIER;
}

[0-9]+ {
    yylval.ival = atoi(yytext);
    return INTEGER;
}

[0-9]+\.[0-9]+ {
    yylval.sval = strdup(yytext);
    return FLOAT_CONST;
}

[ \t]+          { /* 忽略空白字符 */ }
\n              { line_num++; }
"//".*          { /* 忽略单行注释 */ }
"/*"([^*]|"*"[^/])*"*/" { /* 忽略多行注释 */ }

.               { 
    fprintf(stderr, "Error: Unknown character '%c' at line %d\n", yytext[0], yylineno);
    return yytext[0];
}

%%

