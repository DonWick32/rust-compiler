parse:
	flex parser-v2.l
	yacc parser-v2.y --warnings=none
	gcc y.tab.c -w
	./a.out new.rs

optimize:
	python3 code_optimizer.py icg.txt

clean:
	rm -f *.tab.c
	rm -f *.out
	rm -f *.yy.c