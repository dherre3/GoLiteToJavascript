CC = gcc

CFLAGS = -Wall

main: y.tab.o lex.yy.o main.o tree.h tree.o memory.h memory.o typed_ast.o typed_ast.h file.o file.h weed.o weed.h symbol.o symbol.h type.o type.h symboldump.o symboldump.h error.o error.h utils.o utils.h jsutils.h codeJavascript.h codeJavascript.o
	$(CC) lex.yy.o y.tab.o tree.o main.o memory.o typed_ast.o file.o weed.o symbol.o type.o symboldump.o error.o utils.o codeJavascript.o -o goliteJS -L/usr/local/opt/flex/lib -lfl 

y.tab.c y.tab.h: golite.y
	bison --yacc --defines golite.y

lex.yy.c: golite.l y.tab.h
	flex golite.l
check:
	./check
clean:
	rm -f y.tab.* lex.yy.* *.o golitec *.pptype.go *.symtab;

default: golite.l golite.y
	bison -yacc golite.y
	flex golite.l
	$(CC) -o compiler golite.tab.c lex.yy.c -lfl
