#!/bin/bash

lex lex.l

yacc -v -d parser.y
gcc y.tab.c -ll -w

./a.out<input.txt