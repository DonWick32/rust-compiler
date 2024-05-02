%{
#include <stdio.h>
#include <string.h>
%}

%option noyywrap

%%
"fn"                    { printf("Token: keyword: function : 'fn'\n"); }
"main"                  { printf("Token: keyword: main : 'main'\n"); }
"let"                   { printf("Token: keyword: let : 'let'\n"); }
"int"                   { printf("Token: keyword: int : 'i32'\n"); }
"+"                   { printf("Token: keyword: operator : '+'\n"); }
"-"                   { printf("Token: keyword: operator : '-'\n"); }
"<"                   { printf("Token: keyword: operator : '<'\n"); }
[0-9]+                  { printf("Token: integer : '%s'\n", yytext); }
\"[^\"]*\"              { printf("Token: string : \"%s\"\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("Token: identifier : '%s'\n", yytext); }
[ \t\n]                 ; // Ignore whitespace and newline characters
.                       ; // Ignore any other character

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file;
    yylex();

    fclose(file);
    return 0;
}
