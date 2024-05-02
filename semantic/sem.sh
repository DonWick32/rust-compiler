#!/bin/bash

#syntax and symantic
lex sem.l
yacc -v -d sem.y
gcc y.tab.c -w
./a.out < input1.txt

# touch temp.txt
# cp test3.rs temp.txt
# sed -i '/return/d' temp.txt
# cat temp.txt
# ./a.out < input1.txt
# rm temp.txt

# sed -i 's/i32/int/g' test4.rs

# #ICG
# flex parser-v2.l
# yacc parser-v2.y --warnings=none
# gcc y.tab.c -w
# ./a.out ./test3.rs

# sed -i 's/\bint\b/i32/g' test4.rs

