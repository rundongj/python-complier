CCC = clang++
LEX = flex
YACC = bison
CFLAGS = -g -std=c++11 -W -Wall -Wno-unused -Weffc++ -Wextra -pedantic -O0
LEXFLAGS = -Wno-unused -Wno-sign-compare -Wno-deprecated-register

#LEXDEBUG = -d
LEXDEBUG =
YACCDEBUG = -vtd

OBJS = literal.o ast.o  symbolTable.o poolOfNodes.o parse.tab.o lex.yy.o main.o SymTabManager.o

run: $(OBJS)
	$(CCC) $(CFLAGS) -o run $(OBJS)

main.o: main.cpp parse.y scan.l parse.tab.c lex.yy.c literal.h
	$(CCC) $(CFLAGS) -c main.cpp

parse.tab.c: parse.y literal.h ast.h
	$(YACC) $(YACCDEBUG) parse.y

parse.tab.o: parse.tab.c
	$(CCC) $(CFLAGS) -c parse.tab.c

lex.yy.c: scan.l parse.tab.o
	$(LEX) scan.l

lex.yy.o: lex.yy.c
	$(CCC) $(CFLAGS) $(LEXFLAGS) -c lex.yy.c

literal.o: literal.cpp literal.h
	$(CCC) $(CFLAGS) -c literal.cpp

SymTabManager.o: SymTabManager.cpp SymTabManager.h
	$(CCC) $(CFLAGS) -c SymTabManager.cpp

ast.o: ast.cpp ast.h literal.h SymTabManager.h
	$(CCC) $(CFLAGS) -c ast.cpp

symbolTable.o: symbolTable.cpp symbolTable.h
	$(CCC) $(CFLAGS) -c symbolTable.cpp

poolOfNodes.o:poolOfNodes.cpp poolOfNodes.h node.h
	$(CCC) $(CFLAGS) -c poolOfNodes.cpp
	
clean:
	rm -f run *.o parse.tab.c lex.yy.c
	rm -f parse.tab.h
	rm -f parse.output
