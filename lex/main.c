#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "y.tab.h"

extern int lineno;
extern FILE *yyin;
extern char *yytext;
extern char *currentFileName;
int yylex();

int main()
{
    yyin = fopen("input.txt", "r");
    currentFileName = "input.txt";
    int token;

    // Define a map to store token-value to text mapping
    struct TokenMap
    {
        int key;
        const char *value;
    };

    struct TokenMap tokenMap[] = {
        {K_INT, "keyword: int"},
        {K_FLOAT, "keyword: float"},
        {K_CHAR, "keyword: char"},
        {K_STRING, "keyword: string"},
        {LET, "keyword: let"},
        {CONST, "keyword: const"},
        {FUNCTION, "keyword: function"},
        {MAIN, "keyword: main"},
        {PRINT, "keyword: print"},
        {FOR, "keyword: for"},
        {WHILE, "keyword: while"},
        {ELSE, "keyword: else"},
        {IF, "keyword: if"},
        {SWITCH, "keyword: switch"},
        {CASE, "keyword: case"},
        {RETURN, "keyword: return"},
        {CONTINUE, "keyword: continue"},
        {BREAK, "keyword: break"},
        {DEFAULT, "keyword: default"},
        {INTEGER, "integer"},
        {FLOAT, "float"},
        {CHARACTER, "character"},
        {STRING, "string"},
        {IDENTIFIER, "identifier"},
        {AND, "and"},
        {OR, "or"},
        {GE, "greater than or equal to"},
        {LE, "less than or equal to"},
        {EQ, "equal to"},
        {NE, "not equal to"},
        {EOF_TOKEN, "end of file"},
        {ERROR, "error"}};

    while ((token = yylex()) != EOF_TOKEN)
    {
        for (int i = 0; i < sizeof(tokenMap) / sizeof(tokenMap[0]); i++)
        {
            if (token == tokenMap[i].key)
            {
                printf("Token: %s : '%s'\n", tokenMap[i].value, yytext);
                break;
            }
        }
    }

    return 0;
}
