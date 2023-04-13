//Shayan Salsabilian
//pa4
//ssalsabi
//GraphTest.c
#include <stdio.h> //include the libraries
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
int main(){
	Graph A = newGraph(10); //create a graph
	printf("Beginning getOrder Test\n");
	int n = getOrder(A);//get the order of the graph
	printf("	Does getOrder return the right value?\n");
	if(n==10) {//make sure it matches 
		printf("		Passed\n");
	}else{
		printf("		Failed\n");
	}
	printf("Beginning getSize Test\n");
	printf("	Does getSize return the right size for an empty graph?\n");
	if(getSize(A)==0){//make sure the size of the graph is 0
		printf("		Passed\n");
	}else{
		printf("		Failed\n");
	}
	for(int x=1; x<=10; x++){//loop through add 10 edges from 1 to 10 into the graph
		addEdge(A, x, x);
	}
	printf("	Does getSize return the right size for a regular graph?\n");
	if(getSize(A)==10){//make sure the graph is size 10
		printf("		Passed\n");
	}else{
		printf("		Failed\n");
	}
	BFS(A, 3);//run BFS on 3
	printf("Beginning getSource Test\n");
	printf("	Does getSource return the correct output?\n");
	if(getSource(A)==3){//see if its the right source
	printf("		Passed\n");
	}else{
	printf("		Failed\n");
	}
	printf("Beginning getParent Test\n");
	printf("	Does getParent return the right value?\n");
	if(getParent(A, 2)==NIL){//see if there is no parent for 2	
	printf("		Passed\n");
	}else{
	printf("		Failed\n");
	}
	printf("Beginning getDist Test\n");
	printf("	Does getDist return the right value?\n");
	if(getDist(A, 3)==0){//see if the distance from the source to itself is 0
	printf("		Passed\n");
	}else{
	printf("		Failed\n");
	}
	printf("Beginning makeNull Test\n");
	printf("	Does makeNull have the right size after?\n");
	makeNull(A);//empty the graph
	if(getSize(A)==0){//make sure the size is 0
	printf("		Passed\n");
	}else{
	printf("		Failed\n");
	}
	printf("Beginning addEdge/printGraph Test\n");
	printf("	Does addEdge correctly add to a graph?\n");
	printf("The following test should print a Graph with vertices 1 to 10 with each vertice having itself as its adjacency list twice\n");
	for(int x=1; x<=10; x++){//loop through the graph adding edges
		addEdge(A,x,x);
	}
	printGraph(stdout,A);//print that graph
	makeNull(A);//empty the graph
	printf("Beginning addArc/printGraph Test\n");
	printf("	Does addArc correctly add to a graph?\n");
	printf("The following test should print a graph with vertices 1 to 10 with each vertice having itself as its adjacency list once\n");
	for(int x=1; x<=10; x++){//loop through the graph adding arcs
	addArc(A,x,x);
	}
	printGraph(stdout, A);//print the graph
	makeNull(A); //empty the graph
	int j=10;
	for(int x=1; x<=10; x++){//loop through the graph adding edges connecting the end to the front
	addEdge(A,x,j);
	j--;
	}
	printf("Beginning BFS Test\n");
	BFS(A, 1);//run BFS on 1
	printf("	Does BFS correctly return the right distance from the source?\n");
	if(getDist(A,10)==1){// check that there is a distance 1 from 1 to 10
	printf("	Passed\n");
	}else{
	printf("	Failed\n");
	}
	printf("Beginning getPath Test\n");
	List B=newList();//create a list to hold the path from 1 to 10
	getPath(B, A, 10);//run getPath
	printf("	The following test should print 1 10:\n");
	printList(stdout,B);//print the path
	printf("\n");
	freeGraph(&A);//free the graph and list to prevent memory leaks
	freeList(&B);
	return 1;

}
