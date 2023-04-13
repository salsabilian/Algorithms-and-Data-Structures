//Shayan Salsabilian
//ssalsabi
//pa4
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
	int *distance;
	int size;
	int order;
	int source;
}GraphObj;

Graph newGraph(int n){ //creates a new graph of size n
	Graph S=malloc(sizeof(GraphObj)); //memory allocated our graph
	assert(S!=NULL); //make sure we have enough space
	S->order=n; //set the number of vertices of the graph
	S->size=0; //set the length of the graph starting at 0
	S->source=NIL;// start the source at NIL since we dont have a source yet
	S->vertex=calloc((n+1), sizeof(List)); //memory allocate for the list
	assert(S->vertex!=NULL); //make sure we have enough space
	S->color=calloc((n+1), sizeof(int)); //allocated for the color array
	S->parent=calloc((n+1), sizeof(int));//allocate for the parent array
	S->distance=calloc((n+1), sizeof(int));//allocate for distance array
	assert(S->color!=NULL);//make sure we have enough space
	assert(S->parent!=NULL);
	assert(S->distance!=NULL);
	for(int i=1; i<=n; i++){ //initialize all the lists and set all the values of the parents and distances to there initial values
		S->vertex[i]=newList();
		S->parent[i]=NIL;
		S->distance[i]=INF;
	}
	return (S); //then return the Graph
}
void freeGraph(Graph* pG){ //free the graph
	if(pG!=NULL && *pG!=NULL){//make sure both the address and the value are not NULL
		if(getOrder(*pG)!=0){//if the Graph is not empty, empty it
			makeNull(*pG);
		}
		for(int i=1; i<=(*pG)->order;i++){//loop through and free each individual list
			free((*pG)->vertex[i]);
		}					
		free((*pG)->vertex);//free all the individual arrays
		free((*pG)->color);
		free((*pG)->parent);
		free((*pG)->distance);
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

int getSource(Graph G){//returns the last source used in BFS
	if(G==NULL){//checks to make sure the graph is initialized
		printf("Graph Error: calling getSource() on NULL graph reference\n");
		exit(1);
	}
	return G->source;//returns the source
}

int getParent(Graph G, int u){//returns the parent of vertex u
	if(G==NULL){//make sure the graph is not null
		printf("Graph Error: calling getParent() on NULL graph reference\n");
		exit(1);
	}
	return G->parent[u];//returns the parent of u
}

int getDist(Graph G, int u){//returns the distance of vertex u from the source of the last BFS
	if(G==NULL){ //make sure the graph is not null
		printf("Graph Error: calling getDist() on NULL graph reference\n");
		exit(1);
	}
	return G->distance[u];//return the distance from the source to vertex u
}

void makeNull(Graph G){//empty the graph
	if(G==NULL){
		printf("Graph Error: calling makeNull() on NULL graph reference\n");
		exit(1);
	}
	for(int i=1; i<=(getOrder(G)); i++){//clear the graphs and reset all the values to what they initially were
		clear(G->vertex[i]);
		G->distance[i]=INF;
		G->parent[i]=NIL;
		G->color[i]=0;
	}
	G->size=0;
	G->source=NIL;
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

void BFS(Graph G, int s){ //breadth first search to find the shortest distance from the source to all the other vertexes
	if(G==NULL){//make sure the graph is not null
		printf("Graph Error: calling BFS() on NULL graph reference\n");
		exit(1);
	}
	for(int i=1; i<=G->order; i++){//start everything at there initial value
		G->color[i]=0;
		G->distance[i]=INF;
		G->parent[i]=NIL;
	}
	G->source=s;//start at the source given
	G->color[s]=1;//set its color to gray showing we've already viewed it
	G->distance[s]=0; //set its distance to 0, since its the source
	List A=newList();//create a new list to be the queue
	append(A, s);//append the source to the list
	while(length(A)!=0){//while the length is not empty
		moveFront(A);//go to the front of the list
		int x=get(A);//get the value
		deleteFront(A);//then delete the front of the list
		moveFront(G->vertex[x]);//move to the front of the Graphs vertex
		while(index(G->vertex[x])!=-1){//while we havent fallen off the vertexs adjacency list
			int y=get(G->vertex[x]);//get the value
			if(G->color[y]==0){//if its white
				G->color[y]=1;//make it gray
				G->distance[y]=G->distance[x]+1;//make its distance the vertex distance +1
				G->parent[y]=x;//make its parent the vertex
				append(A, y);//and append it to the queue
			}
			moveNext(G->vertex[x]);//then move to the next vertex in the adjacency list
		}
		G->color[x]=2;//when were done make that vertex black
	}
	freeList(&A);//then free the list
}

void getPath(List L, Graph G, int u){//print the distance from the source to u
	if(G==NULL){//make sure the graph is not null
		printf("Graph Error: calling getPath() on NULL graph reference\n");
		exit(1);
	}
	if(G->source==u){//if u is the source
		append(L,u);//append u to the List
	}else if(G->parent[u]==NIL){//if u has no source
		append(L, NIL);//append NIL to the List
	}else{
		getPath(L, G, G->parent[u]);//otherwise run get path on the parent of u
		append(L, u);//then append u to the graph
	}
}
