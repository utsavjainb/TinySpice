CC = g++
CCC = g++
CFLAGS = -c -g -I /usr/local/include/eigen-eigen-323c052e1731
CCFLAGS = $(CFLAGS)
LDFLAGS = -g

O = declare.tab.o scanner.o main.o symtab.o

parser: $O
	$(CCC) $(LDFLAGS) $O -o parser

scanner.o: scanner.l
	flex -it scanner.l > scanner.cc
	g++ $(CCFLAGS) scanner.cc

declare.tab.o: declare.y
	bison -d declare.y; /bin/mv declare.tab.c declare.tab.cc
	g++ $(CCFLAGS) declare.tab.cc

clean:
	/bin/rm -f parser scanner.cc declare.tab.cc declare.tab.h $O
