//Shayan Salsabilian
//ssalsabi
//pa5
//Graph.c
#include<stdio.h> //libraries needed
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "Graph.h"


typedef struct GraphObj{ //structure for our graph
	List *vertex; 
	int *color;
	int *parent;
	int *discover;
	int size;
	int order;
	int *finish;
}GraphObj;

Graph newGraph(int n){ //creates a new graph of size n
	Graph S=malloc(sizeof(GraphObj)); //memory allocated our graph
	assert(S!=NULL); //make sure we have enough space
	S->order=n; //set the number of vertices of the graph
	S->size=0; //set the length of the graph starting at 0
	S->vertex=calloc((n+1), sizeof(List)); //memory allocate for the list
	assert(S->vertex!=NULL); //make sure we have enough space
	S->color=calloc((n+1), sizeof(int)); //allocated for the color array
	S->parent=calloc((n+1), sizeof(int));//allocate for the parent array
	S->discover=calloc((n+1), sizeof(int));//allocate for discover array
	S->finish=calloc((n+1), sizeof(int));//allocate for finish array
	assert(S->color!=NULL);//make sure we have enough space
	assert(S->parent!=NULL);
	assert(S->discover!=NULL);
	assert(S->finish!=NULL);
	for(int i=1; i<=n; i++){ //initialize all the lists and set all the values of the parents, discover, and finish values to there initial values
		S->vertex[i]=newList();
		S->parent[i]=NIL;
		S->discover[i]=UNDEF;
		S->finish[i]=UNDEF;
	}
	return (S); //then return the Graph
}
void freeGraph(Graph* pG){ //free the graph
	if(pG!=NULL && *pG!=NULL){//make sure both the address and the value are not NULL
		if(getSize(*pG)!=0){//if the Graph is not empty, empty it
			for(int i=1; i<=((*pG)->order); i++){
				clear((*pG)->vertex[i]);
			}
		}
		for(int i=1; i<=(*pG)->order;i++){//loop through and free each individual list
			free((*pG)->vertex[i]);
		}					
		free((*pG)->vertex);//free all the individual arrays
		free((*pG)->color);
		free((*pG)->parent);
		free((*pG)->discover);
		free((*pG)->finish);
		free(*pG);//free the graph
		*pG=NULL;//set the pointer to null
	}
}


int getOrder(Graph G){//returns the number of vertices in the graph
	if(G==NULL){//check to make sure the graph is initialized
		printf("Graph Error: calling getOrder() on NULL graph reference\n");
		exit(1);
	}
	return G->order;//return the order
}

int getSize(Graph G){//returns the length of the graph
	if(G==NULL){//check to make sure the graph is initialized
		printf("Graph Error: calling getSize() on NULL graph reference\n");
		exit(1);
	}
	return G->size;//return the size
}

int getDiscover(Graph G, int u){//returns the discover time used by u in DFS
	if(G==NULL){//checks to make sure the graph is initialized
		printf("Graph Error: calling getDiscover() on NULL graph reference\n");
		exit(1);
	}
	return G->discover[u];//returns the discover time of u
}

int getParent(Graph G, int u){//returns the parent of vertex u
	if(G==NULL){//make sure the graph is not null
		printf("Graph Error: calling getParent() on NULL graph reference\n");
		exit(1);
	}
	return G->parent[u];//returns the parent of u
}

int getFinish(Graph G, int u){//returns the finish time of vertex u from the last DFS
	if(G==NULL){ //make sure the graph is not null
		printf("Graph Error: calling getFinish() on NULL graph reference\n");
		exit(1);
	}
	return G->finish[u];//return the finish from  vertex u
}
void addEdge(Graph G, int u, int v){//add an edge to the graph
	if(G==NULL){//make sure graph is not null
		printf("Graph Error: calling addEdge() on NULL graph reference\n");
		exit(1);
	}
	if(u>getOrder(G) || u<1){//make sure u is within the grpah
		printf("u not in range of Graph\n");
		exit(1);
	}
	if(v>getOrder(G) || v<1){//make sure v is within the graph
		printf("v not in range of Graph\n");
		exit(1);
	}
	moveFront(G->vertex[u]);//move the front of both graphs
	moveFront(G->vertex[v]);
	while(index(G->vertex[u])!=-1){//while we havent reached the end of the graph
		int current=get(G->vertex[u]);//get the current indexes value
		if(current>v){//if its bigger than v
			break;//then break
		}
		moveNext(G->vertex[u]);//otherwise keep moving in the list
	}
	if(index(G->vertex[u])==-1){//if we reah the end of the list
		append(G->vertex[u], v);//just append
	}else{
		insertBefore(G->vertex[u], v);//otherwise insert from the index we broke from
	}
	while(index(G->vertex[v])!=-1){//while we havent reached the end of the graph
		int current=get(G->vertex[v]); //get the current indexes value 
		if(current>u){ //if its bigger than u
			break;//then break
		}
		moveNext(G->vertex[v]);//otherwise keep moving in the list
	}
	if(index(G->vertex[v])==-1){//if were at the end of the list
		append(G->vertex[v], u);//just append
	}else{
		insertBefore(G->vertex[v], u);//otherwise insert before
	}
	G->size++;//increment the size
}

void addArc(Graph G, int u, int v){ //add an arc to the graph
	if(G==NULL){//make sure the graph is not null
		printf("Graph Error: calling addArc() on NULL graph reference\n");
		exit(1);
	}
	if(u>getOrder(G) || u<1){//make sure u is in the graph
		printf("u not in range of Graph\n");
		exit(1);
	}
	if(v>getOrder(G) || v<1){//make sure v is in the graph
		printf("v not in range of Graph\n");
		exit(1);
	}
	moveFront(G->vertex[u]);//move the cursor to the front of the list
	while(index(G->vertex[u])!=-1){//while we havent fallen off the list
		int current=get(G->vertex[u]);//get the current value
		if(current>v){//if its greater than the value we have for v
			break;//break
		}
		moveNext(G->vertex[u]);//otherwise move forward in the list
	}
	if(index(G->vertex[u])==-1){//if we fell off the list just append
		append(G->vertex[u], v);
	}else{
		insertBefore(G->vertex[u], v);//otherwise insert before the cursor
	}
	G->size++;//and always increment the size
}
static void Visit(Graph G, List S, int x, int *time){
	G->discover[x]=(++*time);//increment the time pointer
	G->color[x]=1;//change the color to gray showing we have discovered
	moveFront(G->vertex[x]);//move to the front of the Graph vertex
	while(index(G->vertex[x])!=-1){//when you fall off the list leave
		int y=get(G->vertex[x]);//get the item at the cursor
		if(G->color[y]==0){//have we seen it before
			G->parent[y]=x;//if not then make the parent the vertex of the adjacency list
			Visit(G, S, y, time);//then recursively call for the adjacency vertex 
		}
		moveNext(G->vertex[x]);//then move the cursor
	}
	G->color[x]=2;//after we have finished turn it in black
	G->finish[x]=(++*time);//and since we finished we have the finish time
	prepend(S, x);//then add it back on by order of finish time
}

void DFS(Graph G, List S){
	  if(G==NULL){//check to make sure the graph is initialized
                printf("Graph Error: calling DFS() on NULL graph reference\n");
                exit(1);
        }
	if(length(S)!=getOrder(G)){//make sure List S has all the vertices
		printf("length S does not equal n\n");
		exit(1);
	}
	for(int i=1; i<=getOrder(G); i++){//reset all the initial values
		G->color[i]=0;
		G->parent[i]=NIL;
	}
	int length1=length(S);//get the length originially for deleting later
	int time=0;//start the time at 0
	moveFront(S);//move to the front of the list that were running DFS on
	while(index(S)!=-1){//while we havent fallen off the list
		int i=get(S);//get the integer at the cursor
		if(G->color[i]==0){//if the color is white
			Visit(G, S, i,&time); //call vist to get discover and finish
		}
		moveNext(S);//move to the next item
	}

	for(int i=1; i<=length1; i++){//delete the original list s
		deleteBack(S);
	}
}
Graph transpose(Graph G){
	  if(G==NULL){//check to make sure the graph is initialized
                printf("Graph Error: calling Transpose() on NULL graph reference\n");
                exit(1);
        }
	Graph A=newGraph((getOrder(G)));//make a new graph
	A->size=G->size; //match up the size
	for(int i=1; i<=getOrder(G); i++){//go to the start of each list
		moveFront(G->vertex[i]);//go to the front of it 
		while(index(G->vertex[i])!=-1){//add it into the new graph switching the vertex, adjacency, and move forward
			int current=get(G->vertex[i]);
			A->discover[current]=G->discover[i];
			A->finish[current]=G->finish[i];
			A->color[current]=G->color[i];
			A->parent[current]=G->parent[i];
			append(A->vertex[current], i);
			moveNext(G->vertex[i]);
		}
	}
	return A;//then return the transpose graph
}

Graph copyGraph(Graph G){
	  if(G==NULL){//check to make sure the graph is initialized
                printf("Graph Error: calling copyGraph() on NULL graph reference\n");
                exit(1);
        }
	Graph A=newGraph(getOrder(G));//make a new Graph A
	A->size=G->size; //make it the same size
	for(int i=1; i<=getOrder(G); i++){//loop through it
		moveFront(G->vertex[i]);//go to the front of the list
		while(index(G->vertex[i])!=-1){ //until we fall off the list
			int current=get(G->vertex[i]); //get the current of item at the cursor
			append(A->vertex[i], current);//append it to the list therefore copying it
			A->discover[i]=G->discover[i];//make all the attributes the same
			A->finish[i]=G->finish[i];
			A->color[i]=G->color[i];
			A->parent[i]=G->parent[i];
			moveNext(G->vertex[i]);//move to the next item
		}
	}
	return A;//return the graph
}
void printGraph(FILE* out, Graph G){ //print the graph
	if(G==NULL){//make sure the graph is not null
		printf("Graph Error: calling printGraph() on NULL graph reference\n");
		exit(1);
	}
	int n=getOrder(G);//get the size of the graph
	for(int i=1; i<=n; i++){//loop through all the lists
		fprintf(out, "%d: ", i);//prints the vertex the graph
		printList(out, G->vertex[i]); //then print the list
		fprintf(out, "\n");//then move to a new line
	}
}
