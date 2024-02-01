%{

/*  hello comment
*   
*   end comment
*/ 

%}

%%
[\t ]+  
[0-9]+ {printf("%s is a number \n" , yytext);}

if |
for |
fn |
main |
println! |
let |
i32 |
while {printf("%s is a keyword \n" , yytext);}

"()" |
"(" |
")" |
";" |
":" |
"=" |
"+" |
"-" |
"<" |
">" |
"<=" |
">=" |
"{" |
"}"   {printf("%s is a operator \n" , yytext);}

"//"[a-zA-Z| ]*   {printf("%s is a comment \n" , yytext);}

[a-zA-Z]+ {printf("%s is identifier \n" , yytext);}

(\")[^(\")]*(\")  {printf("%s is string \n" , yytext);}



.|\n { ECHO; /* normal default anyway */ }
%%

main()
{
	yylex() ;
}

