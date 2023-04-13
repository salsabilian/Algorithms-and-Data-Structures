//Shayan Salsabilian
//pa5
//ssalsabi
//FindComponents.c
#include <stdio.h>//include the libraries needed
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#define MAX_LEN 1000//make the max length of the lines as 1000
int main(int argc, char *argv[]){ 
	char input[MAX_LEN]="";//initialize an array to hold the lines
	FILE *in, *out;//initialize the files
	if(argc != 3){//make sure our argument length is exactly 3
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}
	in =fopen(argv[1], "r");//open and read the file
	out=fopen(argv[2], "w");//open and write to the file
	if(in==NULL){//make sure both files are there
		printf("Unable to open file %s for reading\n", argv[1]);
		exit(1);
	}
	if(out==NULL){
		printf("Unable to open file %s for writing\n", argv[2]);
		exit(1);
	}
	fgets(input, MAX_LEN, in);//get the first line
	int length=atoi(input);//convert the line to an int
	Graph G=newGraph(length);//then make a graph of that size
	fprintf(out, "Adjacency list representation of G:\n");
	while(fgets(input, MAX_LEN, in) != NULL){//get each line
		char *line=strtok(input, " ");//seperate whats gained with a space
		int vertex=atoi(line); //get the vertex each time
		line=strtok(NULL, " ");
		int adjacent=atoi(line);//then get the adjacent list
		if(adjacent==0 && vertex==0){//if we get a 0 0 were at the dummy point and should break
			break;
		}
		addArc(G, vertex, adjacent);//otherwise add the edge
	}
	printGraph(out, G);//then print the graph
	List A=newList();//make a list
	for(int i=1; i<=getOrder(G); i++){//append all the vertices to the list
		append(A, i);
	}
	DFS(G, A); //run DFS on the graph
	Graph L=transpose(G);//transpose it
	DFS(L, A);//run it again
	moveFront(A);//move to the front of the list
	int Components=0;//Start Components at 0
	while(index(A)!=-1){ //start at the front of the list
		int current=get(A);//get the item
		if(getParent(L,current)==NIL){//All the vertices of null parents are connected components
			Components++;
		}
		moveNext(A);
	}
	fprintf(out, "\nG contains %d strongly connected components:", Components);
	int mainArr[Components+1][getOrder(G)]; //make an array
	memset(mainArr, 0, sizeof(mainArr)); //set everything to 0
	moveFront(A);//start at the beginning of the list
	int i=0;//start the variables at 0
	int j=0;
	while(index(A)!=-1){ //while we havent fallen off the list
		int current=get(A);//get the current integer
		if(getParent(L, current)==NIL){//if we have a vertice with a null parent
			i++;//increment the component array
			j=0;//reset the vertice component of the array	
		}
		mainArr[i][j]=current;//add the item to the list
		j++;//increment the vertice
		moveNext(A);//move to the next item in the list
	}
	j=0; //reset j to get the vertices
	int counter=1;//start a variable counter to keep track of the connected components
	for(int i=Components; i>0; i--){//loop through
		fprintf(out, "\nComponent %d:", counter);//give the counter for connected components
		counter++; //increment the counter
		while(mainArr[i][j]!=0){ // until we run out of vertices 
			fprintf(out, " %d", mainArr[i][j]);//print the vertices in those positions
			j++;
		}
		j=0;//then reset j
	}
	clear(A);//empty the list
	freeList(&A);//free the lists and graphs to prevent memory leaks
	freeGraph(&G);
	freeGraph(&L);
	fclose(in);//and close both files
	fclose(out);
	return 1;
}
