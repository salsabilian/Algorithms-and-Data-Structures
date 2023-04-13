#Shayan Salsabilian
#ssalsabi
#pa3
#Makefile
#------------------------------------------------------------------------------
#
#  Makefile for CMPS 101 pa1 
#  Compiles all .java files in the current directory and creates an executable
#  jar file called Lex.  See the following for a short description of makefiles
#
#       https://classes.soe.ucsc.edu/cmps012b/Summer18/lab1.pdf
#
#------------------------------------------------------------------------------ 

MAINCLASS  = Sparse
JAVAC      = javac 
JAVASRC    = $(wildcard *.java)
SOURCES    = $(JAVASRC) makefile README
CLASSES    = $(patsubst %.java, %.class, $(JAVASRC))
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES))
JARFILE    = $(MAINCLASS) 

all: $(JARFILE)
	
$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(JARCLASSES)
	chmod +x $(JARFILE)
	rm Manifest

%.class: %.java
	$(JAVAC) $<

clean:
	rm -f *.class $(JARFILE)
submit:
	submit cmps101-pt.s19 pa3 Makefile README List.java Matrix.java Sparse.java ListTest.java MatrixTest.java
check:
	ls  /afs/cats.ucsc.edu/class/cmps101-pt.s19/pa3/ssalsabi
