%{
	int yylineno;
	char data_type[200];

	struct treeNode* mktreeNode(struct treeNode *left, struct treeNode *right, char *token);
    void printBT(struct treeNode*);

	struct treeNode *head;
    struct treeNode { 
        struct treeNode *left; 
        struct treeNode *right; 
        char *token; 
    };
%}

%expect 8

%nonassoc  NO_ELSE
%nonassoc  ELSE 
%left  '+' '-' '*' '/' 
%left '<' '>' '=' GE_OP LE_OP EQ_OP NE_OP 

%union{
	char str[1000];
	struct info{
		struct treeNode* nd;
	} obj;
}

%token <obj>  IDENTIFIER CONSTANT STRING_LITERAL
%token <obj>  INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token <obj>  AND_OP OR_OP ADD_ASSIGN SUB_ASSIGN
%token <obj>  FN LET CONST STATIC
%token <obj>  IF ELSE LOOP WHILE FOR IN RANGE ITER CONTINUE BREAK RETURN
%type  <obj>  begin body statements statement assignment ifCondition whileCondition forCondition 
%type  <obj>  arguments_list argument dataType rangeExpression function

%%
begin : function;

function
	: FN IDENTIFIER '(' arguments_list ')' '{' body '}' 
	;

body : 	statements;
statements: statements statement ';' | ';' | ;
statement : assignment | ifCondition | whileCondition | forCondition | RETURN | CONTINUE | BREAK ;
arguments_list:	arguments_list ',' argument | ;
argument : dataType IDENTIFIER;
dataType : LET ;

ifCondition : IF  expression  '{' statements '}' ELSE '{' statements '}';
whileCondition : WHILE expression  '{' statements '}';
forCondition : FOR IDENTIFIER IN rangeExpression '{' statements '}';

rangeExpression : CONSTANT '.' '.' CONSTANT;

assignment: dataType IDENTIFIER '=' expression;

expression : stringExpression | numericExpression | ;
expression : expression comparisonOperator expression;

comparisonOperator: '<' | '>' | '='  | GE_OP | LE_OP | EQ_OP | NE_OP;

stringExpression : stringExpression '+' stringExpression | STRING_LITERAL | IDENTIFIER;

numericExpression : numericExpression '+' numericExpression
           | numericExpression '-' numericExpression
           | numericExpression '*' numericExpression
           | numericExpression '/' numericExpression
           | '(' numericExpression ')'
           | CONSTANT
		   | IDENTIFIER
           ;

%%

#include "lex.yy.c"
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	if(!yyparse())
		printf("\nParsing complete\n");
	else
		printf("\nParsing failed\n");

	fclose(yyin);
	display();
	disp();

	printf("\n\n");
    printf("PARSE TREE");
    printf("\n\n");
	printBT(head);
    printf("\n\n");
	return 0;
}
//extern int lineno;
extern char *yytext;
yyerror(char *s) {
	printf("\nLine %d : %s\n", (yylineno), s);
}         


void printBTHelper(char* prefix, struct treeNode* ptr, int isLeft) {
    if( ptr != NULL ) {
        printf("%s",prefix);
        if(isLeft) { printf("├──"); } 
		else { printf("└──"); }
        printf("%s",ptr->token);
		printf("\n");
		char* addon = isLeft ? "│   " : "    ";
    	int len2 = strlen(addon);
    	int len1 = strlen(prefix);
    	char* result = (char*)malloc(len1 + len2 + 1);
    	strcpy(result, prefix);
    	strcpy(result + len1, addon);
		printBTHelper(result, ptr->left, 1);
		printBTHelper(result, ptr->right, 0);
    	free(result);
    }
}

void printBT(struct treeNode* ptr) {
	printf("\n");
    printBTHelper("", ptr, 0);    
}

struct treeNode* mktreeNode(struct treeNode *left, struct treeNode *right, char *token) {	
	struct treeNode *newtreeNode = (struct treeNode *)malloc(sizeof(struct treeNode));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newtreeNode->left = left;
	newtreeNode->right = right;
	newtreeNode->token = newstr;
	return(newtreeNode);
}
