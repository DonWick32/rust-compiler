%{    
     #include "y.tab.h"
     int line_no=0;
     char datatype[100] = "PROCEDURE";
%}

%option yylineno
%option noinput nounput
alphabet          [a-zA-Z]
digit          [0-9]

%%

"println!"		{ strcpy(yylval.nd_obj.name,(yytext)); return PRINTFF; }
"input"			{ strcpy(yylval.nd_obj.name,(yytext));  return SCANFF; }

"if"                    { strcpy(yylval.nd_obj.name,(yytext));  return IF; }
"else"		{ strcpy(yylval.nd_obj.name,(yytext));  return ELSE; }
"while"		{ strcpy(yylval.nd_obj.name,(yytext));  return WHILE; }
"return" 		{ strcpy(yylval.nd_obj.name,(yytext));  return RETURN; }

"let"	{ strcpy(yylval.nd_obj.name,(yytext));  return DECLARE; }
"+"		{ strcpy(yylval.nd_obj.name,(yytext));  return ADD; }
"-"		{ strcpy(yylval.nd_obj.name,(yytext));  return SUB; }
"*"		{ strcpy(yylval.nd_obj.name,(yytext));  return MULT; }
"/"		{ strcpy(yylval.nd_obj.name,(yytext));  return DIV; }
"log"		{ strcpy(yylval.nd_obj.name,(yytext));  return LOG; }
"exp"		{ strcpy(yylval.nd_obj.name,(yytext));  return POW; }


">="		{ strcpy(yylval.nd_obj.name,(yytext));  return GE; }
"<="		{ strcpy(yylval.nd_obj.name,(yytext));  return LE; }
">"		{ strcpy(yylval.nd_obj.name,(yytext));  return GT; }
"<"		{ strcpy(yylval.nd_obj.name,(yytext));  return LT; }
"=="		{ strcpy(yylval.nd_obj.name,(yytext));  return EQ; }
"!="		{ strcpy(yylval.nd_obj.name,(yytext));  return NE; }

"TRUE"		{ strcpy(yylval.nd_obj.name,(yytext)); return TRUE; }
"FALSE"		{ strcpy(yylval.nd_obj.name,(yytext)); return FALSE; }
"&&"		{ strcpy(yylval.nd_obj.name,(yytext));  return AND; }
"||"		{ strcpy(yylval.nd_obj.name,(yytext));  return OR; }


"i32"		{ strcpy(yylval.nd_obj.name,(yytext)); strcpy(datatype, "INT"); return INT; }
"f32"		{ strcpy(yylval.nd_obj.name,(yytext)); strcpy(datatype, "FLOAT"); return FLOAT; }
"char"		{ strcpy(yylval.nd_obj.name,(yytext)); strcpy(datatype, "CHAR"); return CHAR; }
"bool"		{ strcpy(yylval.nd_obj.name,(yytext)); strcpy(datatype, "BOOL"); return BOOL; }

\#.*			{ ; }
[ \t]*			{ ; }
[\n]			{ line_no++; }


[-]?{digit}+                		{ strcpy(yylval.nd_obj.name,(yytext));  return NUMBER; }
[-]?{digit}+\.{digit}{1,6}  		{ strcpy(yylval.nd_obj.name,(yytext));  return FLOAT_NUM; }
{alphabet}({alphabet}|{digit})*   	{ insertToHash(yytext,datatype,yylineno); strcpy(yylval.nd_obj.name,(yytext));  return ID; }

["].*["]                    { strcpy(yylval.nd_obj.name,(yytext));  return STR; }
['].[']                     { strcpy(yylval.nd_obj.name,(yytext));  return CHARACTER; }

";"|"="|","|"{"|"}"|"("|")"|"["|"]"|"*"|"+"|"-"|"/"|"?"|":"|"&"|"|"|"^"|"!"|"~"|"%"|"<"|">" { strcpy(yylval.nd_obj.name,(yytext));  return yytext[0];}


%%

int yywrap(void) {
   return 1;
}

struct nodeTable
{
	char token[100];
    	char attr[100];
    	//int line[100];
    	int line_count;
	struct nodeTable *next;
};

struct hash
{
	struct nodeTable *head;
	int hash_count;
};

struct hash hashTable[1000];
int eleCount = 1000;

struct nodeTable * createNode(char *token, char *attr, int l)
{
	struct nodeTable *newnodeTable;
	newnodeTable = (struct nodeTable *) malloc(sizeof(struct nodeTable));
	strcpy(newnodeTable->token, token);
	strcpy(newnodeTable->attr, attr);
	//newnodeTable->line[0] = l;
	newnodeTable->line_count = 1; 
	newnodeTable->next = NULL;
	return newnodeTable;
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
	struct nodeTable *newnodeTable = createNode(token, attr, l);
	/* head of list for the bucket with index "hashIndex" */
	if (hashTable[hi].head==NULL)
	{
		hashTable[hi].head = newnodeTable;
	        hashTable[hi].hash_count = 1;
	        return;
	}
	struct nodeTable *myNode;
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
		//adding new nodeTable to the list
		newnodeTable->next = (hashTable[hi].head);
		//update the head of the list and no of nodeTables in the current bucket
		hashTable[hi].head = newnodeTable;
		hashTable[hi].hash_count++;
	}
	return;
}

void displaySymbolTable()
{
    	struct nodeTable *myNode;
    	int i,j, k=1;
    	printf("\n-----------------------------------------Symbol Table---------------------------------------------\n");
    	printf("--------------------------------------------------------------------------------------------------");
    	printf("\nToken \t\t|\tToken Type \t\t\t\t\t \n");
        printf("--------------------------------------------------------------------------------------------------\n");
    	for (i = 0; i < eleCount; i++)
    	{
        	if (hashTable[i].hash_count == 0)
            		continue;
        	myNode = hashTable[i].head;
        	if (!myNode)
            		continue;
        	while (myNode != NULL)
        	{
            		//printf("%d\t\t", k++);
            		printf("%s\t\t\t", myNode->token);
            		printf("%s\t\t\t", myNode->attr);
            		/*for(j=0;j<(myNode->line_count);j++)
            			printf("%d  ",myNode->line[j]);*/
            		printf("\n");
            		myNode = myNode->next;
        	}
	}
	printf("--------------------------------------------------------------------------------------------------\n");
   	return;
}


