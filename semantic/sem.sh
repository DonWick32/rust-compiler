#!/bin/bash

lex sem.l

yacc -v -d sem.y
gcc y.tab.c -ll -w

./a.out < sem.in