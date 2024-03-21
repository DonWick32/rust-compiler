%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    int yyerror(const char *s);
    int yylex(void);
    int yywrap();
    

    // void printtree(struct node*);
    // void printInorder(struct node *);
    struct node* mknode(struct node *left, struct node *right, char *token);
    void printBT(struct node*);

    // int success = 1;
    struct node *head;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
    };
%}


%union { 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} nd_obj; 


		struct var_name2 { 
			char name[100]; 
			struct node* nd;
			char type[5];
		} nd_obj2; 
}

%token <nd_obj> DECLARE CHARACTER PRINTFF SCANFF INT BOOL FLOAT CHAR WHILE IF ELSE TRUE FALSE NUMBER FLOAT_NUM ID LE GE EQ NE GT LT AND OR STR ADD MULT DIV SUB RETURN LOG POW 

%type <nd_obj> program entry datatype body block else condition statement term factor base exponent mulops addops relop return 


%type <nd_obj2> init value expression

/* %define parse.error verbose */
%%

program: entry '(' ')' '{' body return '}' { 
    struct node *main = mknode($5.nd, $6.nd, "MAIN"); 
    $$.nd = mknode($1.nd, main, "PROGRAM"); 
    head = $$.nd; 
    } 
;

// entry: datatype ID
// ;
entry: ID ID
;

datatype: INT 
| FLOAT 
| CHAR
;

body: block body {$$.nd = mknode($1.nd, $2.nd, "BODY");}
| { $$.nd = NULL; }
;

block: WHILE '(' condition ')' '{' body '}' { $$.nd = mknode($3.nd, $6.nd, $1.name); }
| IF '(' condition ')' '{' body '}' else { struct node *iff = mknode($3.nd, $6.nd, $1.name); 	$$.nd = mknode(iff, $8.nd, "IF-ELSE"); }
| statement ';' { $$.nd = $1.nd; }
| PRINTFF '(' STR ')' ';' { $$.nd = mknode(NULL, NULL, "PRINT"); }
| SCANFF '(' STR ',' '&' ID ')' ';' { $$.nd = mknode(NULL, NULL, "SCAN"); }
;

else: ELSE '{' body '}' { $$.nd = mknode(NULL, $3.nd, $1.name); }
| { $$.nd = NULL; }
;

condition: value relop value { $$.nd = mknode($1.nd, $3.nd, $2.name);}
| TRUE {$$.nd = NULL; }
| FALSE {$$.nd = NULL; }
;

statement: DECLARE ID ':' datatype init {$2.nd = mknode(NULL, NULL, $2.name); $1.nd = mknode($2.nd, $4.nd, $1.name); $$.nd = mknode($1.nd, $5.nd, "DECLARE");} //
| ID '=' expression { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $3.nd, "="); }
| ID relop expression { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $3.nd, $2.name ); }
;

init: '=' value { $$.nd = $2.nd;}
| { $$.nd = NULL; }
;


expression : expression addops term { $$.nd = mknode($1.nd, $3.nd, $2.name); }
| term { $$.nd = $1.nd;}
;

term : term mulops factor { $$.nd = mknode($1.nd, $3.nd, $2.name); }
| factor {$$.nd = $1.nd;}
; 

factor : base exponent base { $$.nd = mknode($1.nd, $3.nd, $2.name); }
| LOG '(' value ',' value ')' {$$.nd = mknode($3.nd, $5.nd, $1.name); }
| base {$$.nd = $1.nd;}
;

base : value {$$.nd = $1.nd;}
| '(' expression ')' {$$.nd = $2.nd;}
;


exponent: POW
;

mulops: MULT
| DIV
;

addops: ADD 
| SUB 
;

relop: LT
| GT
| LE
| GE
| EQ
| NE
;

value: NUMBER {$$.nd = mknode(NULL, NULL, $1.name);}
| FLOAT_NUM {$$.nd = mknode(NULL, NULL, $1.name);}
| CHARACTER {$$.nd = mknode(NULL, NULL, $1.name);}
| ID {$$.nd = mknode(NULL, NULL, $1.name);}
;

return: RETURN value ';'  { $1.nd = mknode(NULL, NULL, "RETURN"); $$.nd = mknode($1.nd, $2.nd, "RETURN"); }
| { $$.nd = NULL; } 
;

%%


int main() {
    extern FILE *yyin, *yyout;
    // yydebug = 1; // This is needed to show the trace of the parser having action, state and token
    int p = -1;
    p = yyparse();
    /* if(success)
        printf("Parsing Successful\n"); */
    if(!p){
        displaySymbolTable();

        printf("Parsing Successful\n");

        printf("\n\n");
        printf("PARSE TREE");
        printf("\n\n");
        printBT(head);
        printf("\n\n");
    }
}

int yyerror(const char *msg)
{
    extern int yylineno;
    printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
    /* success = 0; */
    return 0;
}

void printBTHelper(char* prefix, struct node* ptr, int isLeft) {
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

void printBT(struct node* ptr) {
	printf("\n");
    printBTHelper("", ptr, 0);    
}

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}
