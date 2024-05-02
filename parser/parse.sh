#!/bin/bash

lex lex.l

yacc -v -d parser.y
#sudo apt install graphviz
#dot y.dot -T png -o y.png
gcc y.tab.c -w

./a.out<pls.txt