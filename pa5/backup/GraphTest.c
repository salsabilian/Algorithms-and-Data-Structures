//Shayan Salsabilian
//ssalsabi
//pa5
//GraphTest.c
#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include "List.h"
int main(){
	Graph A=newGraph(100);//make a new Graph 
	addArc(A, 64, 4);//add some arcs
        addArc(A, 64, 3);
        addArc(A, 42, 2);
        addArc(A, 2, 64);
        addArc(A, 4, 2);
        addArc(A, 3, 42);
	printf("Beginning getOrder Test:\n");
	if(getOrder(A)==30){//check the order
	printf("	Passed\n");
	}else{
	printf("	Failed\n");
	}
	printf("Beginning getSize Test:\n");
	if(getSize(A)==6){//check the size
	printf("	Passed\n");
	}
	printf("Beginning getDiscover Test:\n");
	List L=newList();//make a new list
        for (int i = 1; i <= 100; i++) {//put al the vertices in it
          prepend(L, i);
        }
	DFS(A, L);//run DFS on it therefore testing it
	if(getDiscover(A, 23)==161){//check the start time
	printf("	Passed\n");
	}else{
	printf("	Failed\n");
       }
	printf("Beginning getFinish Test:\n");
	if(getFinish(A,23)==162){//check the finish time
	printf("	Passed\n");
	}else{
	printf("	Failed\n");
	}
	  printf("Beginning getParent Test:\n");
        if(getParent(A,23)==NIL){//check to see it has parents. Unfortunately, sad orphan :(
        printf("        Passed\n");
        }else{
        printf("        Failed\n");
        }
	printf("Beginning addEdge/Arc/printGraph Test:\n");
	Graph B=newGraph(5);//make a new Graph
	printf("The following test should produce a Graph with 1 and 4 in vertex 1 and 1 in vertex 4\n");
	addArc(B,1,1);//add an arc and edge
 	addEdge(B,1,4);
	printGraph(stdout, B);//print it out
	printf("Beginning copyGraph/printGraph Test:\n");
	Graph C=copyGraph(B);//copy it
	printf("The following Graph should match the one above\n");
	printGraph(stdout, C);//print it out
	printf("Beginning transposeGraph/printGraph Test:\n");
	printf("The following Graph should be the transpose of the one above\n");
	Graph D=transpose(B);//transpose it
	printGraph(stdout, D);//print it out
	freeGraph(&A);//free and empty everything to prevent memory leaks
	freeGraph(&B);
	freeGraph(&C);
	freeGraph(&D);
	clear(L);
	freeList(&L);
}
