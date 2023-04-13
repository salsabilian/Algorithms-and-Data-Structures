#Shayan Salsabilian
#ssalsabi
#pa2
#Makefile

Lex : Lex.o List.o
	gcc -o Lex Lex.o List.o

Lex.o : Lex.c List.h
	gcc -c -std=c99 -Wall Lex.c

ListClient: ListClient.o List.o
	gcc -o ListClient ListClient.o List.o

ListClient.o : ListClient.c List.h
	gcc -c -std=c99 -Wall ListClient.c

List.o : List.c List.h
	gcc -c -std=c99 -Wall List.c

clean :
	rm -f Lex ListClient Lex.o ListClient.o List.o
submit :
	submit cmps101-pt.s19 pa2 Lex.c List.c List.h README Makefile ListClient.c
check :
	ls  /afs/cats.ucsc.edu/class/cmps101-pt.s19/pa2/ssalsabi
