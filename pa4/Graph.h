//Shayan Salsabilian
//ssalsabi
//Graph.h
//pa4
#include "List.h" //include the library List.h
#ifndef _MATRIX_H_INCLUDE_
#define _MATRIX_H_INCLUDE_

typedef struct GraphObj* Graph; //change GraphObj to Graph

#define INF -1 //then define NIL and INF
#define NIL -100

/*** Constructors-Destructors ***/
Graph newGraph(int n);
void freeGraph(Graph* pG);
/*** Access functions ***/
int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);
/*** Manipulation procedures ***/
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);
/*** Other operations ***/
void printGraph(FILE* out, Graph G);
#endif
