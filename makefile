fork:fork.c
	gcc -g -o $@ $^
.PHONY:clear
clear:
	rm -f fork
