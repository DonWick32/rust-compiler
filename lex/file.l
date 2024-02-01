%{

/*  hello comment
*   
*   keywords: 
*
*
*
*
*
*
*
*
*   
*   end comment
*/ 

%}

%%
[\t]+  
if |
for |
while {printf("%s is a keyword \n" , yytext);}

[a-zA-Z]+ {printf("%s is identifier \n" , yytext);}



.|\n { ECHO; /* normal default anyway */ }
%%

main()
{
	yylex() ;
}
