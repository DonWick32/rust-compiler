#!/bin/bash

lex lex.l

yacc -v -d -g -t --report=states,itemsets parser.y
#sudo apt install graphviz
dot y.dot -T png -o y.png
gcc y.tab.c -ll -w

./a.out<input.txt