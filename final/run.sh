#!/bin/bash

./rust_tokenizer input.txt

cat semantic.txt

cat syntax.txt

flex parser-v2.l
yacc parser-v2.y --warnings=none
gcc y.tab.c -w
./a.out new.rs

cat last.txt

python3 code_optimizer.py