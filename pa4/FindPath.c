//Shayan Salsabilian
//pa4
//ssalsabi
//FindPath.c
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
	while(fgets(input, MAX_LEN, in) != NULL){//get each line
		char *line=strtok(input, " ");//seperate whats gained with a space
		int vertex=atoi(line); //get the vertex each time
		line=strtok(NULL, " ");
		int adjacent=atoi(line);//then get the adjacent list
		if(adjacent==0 && vertex==0){//if we get a 0 0 were at the dummy point and should break
			break;
		}
		addEdge(G, vertex, adjacent);//otherwise add the edge
	}
	printGraph(out, G);//then print the graph
	List A=newList();//make a list
	while(fgets(input, MAX_LEN, in) !=NULL){//get each line starting where we stopped
		fprintf(out, "\n");
		char *line=strtok(input, " ");
		int source=atoi(line);//get the source
		line=strtok(NULL, " ");
		int dist=atoi(line);//then get the dist
		if(dist==0 && source==0){//if we get 0 0 were at the dummy point and should break
			break;
		}
		BFS(G, source);//run BFS on the source
		int INFcheck=getDist(G,dist);//check if were at infinity
		if(INFcheck==-1){//if we are print infinity
			fprintf(out, "The distance from %d to %d is infinity\n", source, dist);
		}else{//otherwise print the normal distance
			fprintf(out, "The distance from %d to %d is %d\n", source, dist, INFcheck);
		}
		getPath(A,G, dist);//then get the path
		if(back(A)==NIL){//if the list item in the list is NIL then no path exists
			fprintf(out, "No %d-%d path exists", source, dist);
		}else{//otherwise print the path
			fprintf(out, "A shortest %d-%d path is: ", source, dist);
			printList(out, A);
		}
		fprintf(out, "\n");
		clear(A);//then clear the list
	}
	freeList(&A);//free the list and graph to prevent memory leaks
	freeGraph(&G);
	fclose(in);//and close both files
	fclose(out);
	return(1);
}
