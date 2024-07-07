all: compiler

syntaxAnalyzer.tab.c syntaxAnalyzer.tab.h: syntaxAnalyzer.y
	bison -v -d syntaxAnalyzer.y

lex.yy.c: lexicalAnalyzer.l syntaxAnalyzer.tab.h
	flex lexicalAnalyzer.l

compiler: lex.yy.c syntaxAnalyzer.tab.c syntaxAnalyzer.tab.h hashtbl.o
	gcc -o bison syntaxAnalyzer.tab.c lex.yy.c hashtbl.o -lm

hashtbl.o: hashtbl.c hashtbl.h
	gcc -o hashtbl.o -c hashtbl.c
clean:
	rm bison syntaxAnalyzer.tab.c lex.yy.c syntaxAnalyzer.tab.h hashtbl.o 
	rm syntaxAnalyzer.output
