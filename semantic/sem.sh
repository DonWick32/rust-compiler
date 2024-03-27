#!/bin/bash

lex sem.l

yacc -v -d sem.y
gcc y.tab.c -ll -w

./a.out < input1.txt