
alpha 			[A-Za-z_]
fl			    (f|F)
digit 			[0-9]
exp			    [Ee][+-]?{digit}+

%{
//int yylineno = 1;
char datatype[100] = "dummy";
int tl;
char next;
#include <stdio.h>
#include <string.h> 
%}

%%	
\n            { yylineno++; }
"/*"					{ multicomment(); }
"//"					{ singlecomment(); }

"use std::io;" {}

{digit}+    				              { printf("Constant : %s, line no:%d \n",yytext,yylineno); return CONSTANT; }
({digit}+)\.({digit}+) 			      { printf("Constant : %s, line no:%d \n",yytext,yylineno); return CONSTANT; }

'(\\.|[^\\'])+'				            {return CONSTANT; }

{digit}+{exp}{fl}?			          { printf("Expession : %s ,at line %d\n",yytext,yylineno) ; return CONSTANT; }
{digit}*"."{digit}+({exp})?{fl}?	{ printf("Expession : %s ,at line %d\n",yytext,yylineno); return CONSTANT; }

{alpha}?\"(\\.|[^\\"])*\"		      { printf("String literal : %s, at line %d\n",yytext,yylineno); return STRING_LITERAL; } 

"++"			    { printf("Operator : %s, at line %d\n",yytext,yylineno); return INC_OP; }
"--"			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return DEC_OP; }
"<<"			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return LEFT_OP; }
">>"			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return RIGHT_OP; }
"<="			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return LE_OP; }
">="			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return GE_OP; }
"=="			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return EQ_OP; }
"!="			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return NE_OP; }
"&&"			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return AND_OP; }
"||"			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return OR_OP; }
"+="			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return ADD_ASSIGN; }
"-="			    { printf("Operator : %s, at line %d\n",yytext,yylineno);return SUB_ASSIGN; }
".."|"..="    { printf("Operator : %s, at line %d\n",yytext,yylineno);return RANGE; }

"let"         { printf("Datatype : %s, at line %d\n",yytext,yylineno);strcpy(datatype, "Variable"); tl = yylineno; return LET; }
"const"			  { printf("Datatype : %s, at line %d\n",yytext,yylineno);strcpy(datatype, "Variable (Const)"); tl = yylineno; return CONST; }
"static"      { printf("Datatype : %s, at line %d\n",yytext,yylineno);strcpy(datatype, "Variable (Static)"); tl = yylineno; return STATIC; }

"fn"          { printf("Function : %s, at line %d\n",yytext,yylineno);return FN; }
"return"		  { printf("Keyword : %s, at line %d\n",yytext,yylineno);return RETURN; }

"if"			    { printf("Keyword : %s, at line %d\n",yytext,yylineno);return IF; }
"else"			  { printf("Keyword : %s, at line %d\n",yytext,yylineno);return ELSE; }
"loop"        { printf("Keyword : %s, at line %d\n",yytext,yylineno);return LOOP; }
"while"			  { printf("Keyword : %s, at line %d\n",yytext,yylineno);return WHILE; }
"for"			    { printf("Keyword : %s, at line %d\n",yytext,yylineno);strcpy(datatype, "Variable"); tl = yylineno; return FOR; }
"in"          { printf("Keyword : %s, at line %d\n",yytext,yylineno);return IN; }
".iter()"     { printf("Keyword : %s, at line %d\n",yytext,yylineno);return ITER; }
"break"			  { printf("Keyword : %s, at line %d\n",yytext,yylineno);return BREAK; }
"continue"	  { printf("Keyword : %s, at line %d\n",yytext,yylineno);return CONTINUE; }


";"			      {  strcpy(datatype, "dummy"); return(';'); }
("{"|"<%")		{  return('{'); }
("}"|"%>")		{  return('}'); }
","			      {  return(','); }
":"			      {  printf("Operator : %s, at line %d\n",yytext,yylineno);return(':'); }
"="			      {  printf("Operator : %s, at line %d\n",yytext,yylineno);return('='); }
"("			      {  return('('); }
")"			      {  return(')'); }
"&"			      {  printf("Operator : %s, at line %d\n",yytext,yylineno);return('&'); }
"!"			      {  printf("Operator : %s, at line %d\n",yytext,yylineno);return('!'); }
"-"			      {  printf("Operator : %s, at line %d\n",yytext,yylineno);return('-'); }
"+"			      {  printf("Operator : %s, at line %d\n",yytext,yylineno);return('+'); }
"*"			      {  printf("Operator : %s, at line %d\n",yytext,yylineno);return('*'); }
"/"			      {  printf("Operator : %s, at line %d\n",yytext,yylineno);return('/'); }
"<"			      {  printf("Operator : %s, at line %d\n",yytext,yylineno);return('<'); }
">"			      {  printf("Operator : %s, at line %d\n",yytext,yylineno);return('>'); }


"print!"|"println!"|"io::stdin().read_line"	   { return IDENTIFIER; }
"main" 			                                   {  return IDENTIFIER; }


{alpha}({alpha}|{digit})*    		{  printf("Identifier : %s, at line %d\n",yytext,yylineno);
                                  if(strcmp(datatype, "dummy")==0)
                                    return IDENTIFIER;
                                  else 
                                  {
                                    return IDENTIFIER; 
                                  }
                                }

[ \t\v\n\f]		{  }
.			{ yyerror("Lexical Error"); /* bad characters */ }


%%

struct cnode
{
	char num[50];
	char type[20];
};
struct cnode ctable[100];
int ccount = 0;

struct node
{
	char token[100];
    char attr[100];
    int line_count;
	struct node *next;
};

struct hash
{
	struct node *head;
	int hash_count;
};

struct hash hashTable[1000];
int eleCount = 1000;

struct node * createNode(char *token, char *attr, int l)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	strcpy(newnode->token, token);
	strcpy(newnode->attr, attr);
	newnode->line_count = 1; 
	newnode->next = NULL;
	return newnode;
}

int hashIndex(char *token)
{
	int hi=0;
	int l,i;
	for(i=0;token[i]!='\0';i++)
	{
		hi = hi + (int)token[i];
	}
	hi = hi%eleCount;
	return hi;
}

void insertToHash(char *token, char *attr, int l)
{
	int flag=0;
	int hi;
	hi = hashIndex(token);
	struct node *newnode = createNode(token, attr, l);
	/* head of list for the bucket with index "hashIndex" */
	if (hashTable[hi].head==NULL)
	{
		hashTable[hi].head = newnode;
	        hashTable[hi].hash_count = 1;
	        return;
	}
	struct node *myNode;
    	myNode = hashTable[hi].head;
	while (myNode != NULL)
    	{
        	if (strcmp(myNode->token, token)==0)
        	{
            		flag = 1;
            		//myNode->line[(myNode->line_count)++] = l;
            		if(strcmp(myNode->attr, attr)!=0)
            		{
            			strcpy(myNode->attr, attr);
            		}
            		break;
        	}
        	myNode = myNode->next;
    	}
	if(!flag)
	{
		//adding new node to the list
		newnode->next = (hashTable[hi].head);
		//update the head of the list and no of nodes in the current bucket
		hashTable[hi].head = newnode;
		hashTable[hi].hash_count++;
	}
	return;
}

yywrap()
{
	return(1);
}
multicomment()
{
	char c, c1;
	while ((c = input()) != '*' && c != 0);
	c1=input();
	if(c=='*' && c1=='/')
	{
		c=0;
	}
	if (c != 0)
		putchar(c1);
}
singlecomment()
{
	char c;
	while(c=input()!='\n');
	if(c=='\n')
		c=0;
	if(c!=0)
		putchar(c);
}
