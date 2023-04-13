//Shayan Salsabilian
//ssalsabi
//pa4
//List.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "List.h"

//structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{//will make the node class have a prev, an item, and a next make it a doubly linked list
	struct NodeObj *prev;
	int item;
	struct NodeObj *next;
} NodeObj;

// private Node type
typedef NodeObj* Node;//change the pointer to a Node so we dont have to refer to it as a pointer each time

typedef struct ListObj{//create a List class
	Node front;//that will have a front, back node, numItems, index, and a cursor Node
	Node back;
	int numItems;
	int index;
	Node cursor;
} ListObj;


// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private.
Node newNode(int data){//make a new node with an item in it
	Node N = malloc(sizeof(NodeObj));//malloc the node to heap memory
	assert(N!=NULL);
	N->prev=NULL;//start the next and previous as null
	N->item = data;//and put the data into the item position of the Node
	N->next = NULL;
	return N;//return the Node
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
// Private.
void freeNode(Node* pN){//free the node
	if( pN!=NULL && *pN!=NULL ){//make sure both the pointer and the address are not null
		free(*pN);//if theyre not free the node
		*pN = NULL;//set the pointer to null so we can't access that memory again
	}
}
// Returns reference to new empty Queue object.
List newList(void){//make a new list
	List S = malloc(sizeof(ListObj));//malloc the size of the list pointer
	assert(S!=NULL);
	S->front = NULL;//initialize everything to the correct starting conditions
	S->back=NULL;
	S->numItems=0;
	S->cursor=NULL;
	S->index=-1;
	return S;//then return the list
}

// Frees all heap memory associated with Queue *pQ, and sets *pQ to NULL.S
void freeList(List* pQ){
	if(pQ!=NULL && *pQ!=NULL) { //make sure the pointer and the address are not null
		while( (*pQ)->numItems!=0 ) { //while the list is not empty
			deleteFront(*pQ); //empty it
		}
		free(*pQ);//then free the null
		*pQ = NULL;//set the pointer to null
	}
}
int length(List L){//return the length of the list by returning numItems
	if(L==NULL){//check if the List is initialized
		printf("List Error: length() called on NULL List reference\n");
		exit(1);
	}
	return L->numItems;//then return the length
}
int index(List L){//will find where the cursor is currently pointing to by looping through the list and comparing nodes
	if(L==NULL){//check if the list is initialized
		printf("List Error: index() called on NULL List reference\n");
		exit(1);
	}
	L->index=0;//start the index at 0
	for(Node N=L->front; N!=NULL; N=N->next){//run through the entire list
		if((N)==(L->cursor)){//returning the index if the node on the list is the same as the cursor
			return L->index;
		}
		L->index++;//otherwise keep incrementing the counter
	}
	L->index=-1;
	return L->index;//if we go through the entire list and cant find the cursor that means the cursor is null and the user is not currently highlighting anything on the list therefore we should return -1 to show the index is undefined
}
int front(List L){//returns the item at the front of the list
	if(L==NULL){//check if the list is initialized
		printf("List Error: front() called on NULL List reference\n");
		exit(1);
	}
	if(L->numItems<=0){//if there is no items in the list throw an error message and exit
		printf("List Error: front() called on empty List\n");
		exit(1);
	}
	return L->front->item;//otherwise return the item in front
}
int back(List L){//returns the item at the back of the list
	if(L==NULL){//check if the list is initialized
		printf("List Error: back() called on NULL List reference\n");
		exit(1);
	}
	if(L->numItems<=0){//if there is no items in the list return an error message and exit
		printf("List Error: back() called on empty List\n");
		exit(1);
	}
	return L->back->item;//otherwise return the item at the back of the list
}
int get(List L){//returns the item at the cursor
	if(L==NULL){//check if the list is initialized
		printf("List Error: get() called on NULL List reference\n");
		exit(1);
	}

	if(L->numItems<=0){//if there is no items in the list throw an error message and exit
		printf("List Error: get() called on empty List\n");
		exit(1);
	}
	if(L->index<0){//if the index is undefined then we cant get the item in the cursor so throw an error message and exit
		printf("List Error: get() called on undefined index\n");
		exit(1);
	}
	return L->cursor->item;//otherwise return the item at the cursor
}
int equals(List A, List B){//check if two lists are equal
	if(A==NULL||B==NULL){//check if both lists are initialized
		printf("List Error: equals() called on NULL List reference\n");
		exit(1);
	}

	int eq=0;//start a boolean as false
	Node N=A->front;//start at the front of the first list
	Node M=B->front;//start at the front of the second list
	if((length(A))==(length(B))){//check that there lengths are the same
		eq=1;//make the boolean true if they are
	}
	while(eq==1 && N!=NULL){//until we reach the end of the list(since we already checked the lengths we only need to go till one of the lists are null) or until boolean is not true
		if((N->item)==(M->item)){//check each item against each other
			eq=1;//make the booleans true each time if they are
		}else{//if any of them are not make the boolean false and exit the loop
			eq=0;
		}
		N=N->next;
		M=M->next;//then move both lists forward
	}
	return eq;//return the boolean
}
void clear(List L){//reset the list back to the empty state
	if(L==NULL){//check if the list is initialized
		printf("List Error: clear() called on NULL List reference\n");
		exit(1);
	}

	Node N=L->front;//start the node at the front
	while(N!=NULL){//loop through the entire list deleting everything
		N=N->next;//move forward then delete the front, so that we dont double free a node
		deleteFront(L);
	}
	L->numItems=0;//essentially returning everything back to what it was when we started the list
	L->index=-1;
	L->front=NULL;
	L->cursor=NULL;
	L->back=NULL;
}

void moveFront(List L){//move the cursor to the front of the list
	if(L==NULL){//check if the list is initialized
		printf("List Error: moveFront() called on NULL List reference\n");
		exit(1);
	}

	if(L->numItems!=0){//check if the list contains Nodes
		L->cursor=L->front;//if it does have the cursor "highlight" front
		L->index=0;//and place the index at 0 implying cursor is at the front
	}
}
void moveBack(List L){//move the cursor to the back of the list
	if(L==NULL){//check if the list is initialized
		printf("List Error: moveBack() called on NULL List reference\n");
		exit(1);
	}

	if(L->numItems!=0){//check if the list contains Nodes
		L->cursor=L->back;//if it does then have the cursor "highlight" the back
		L->index=(L->numItems-1);//and change the index to numItems-1 implying the cursor is at the back
	}
}

void movePrev(List L){//move the cursor back 1
	if(L==NULL){//check if the list is initialized
		printf("List Error: movePrev() called on NULL List reference\n");
		exit(1);
	}

	if(L->index==0){//if were at the front of the list then we cant move back anymore
		L->index=-1;//so the index becomes undefined
		L->cursor=NULL;//and the cursor becomes null
	}else if(L->index!=-1){//if the cursor is  on the list, then we can move back (since we already checked if it was at the front
		L->index--;//decrement the index
		L->cursor=L->cursor->prev;//and move the cursor back
	}
}
void moveNext(List L){//move the cursor forward 1
	if(L==NULL){//check if the list is initialized
		printf("List Error: moveNext() called on NULL List reference\n");
		exit(1);
	}
	if(L->index==(L->numItems-1)){//if were at the back of the list we cant move forward anymore
		L->cursor=NULL;//so set the cursor to null
		L->index=-1;//and make the index undefined
	}else if(L->index!=-1){//if the cursor is on the list, then we can move forward (since we already checked if it was at the front
		L->cursor=L->cursor->next;//move the cursor forward 1
		L->index++;//and increment the index
	}
}
void prepend(List L, int data){//insert to the front of the list
	if(L==NULL){//check if the list is initialized
		printf("List Error: prepend() called on NULL List reference\n");
		exit(1);
	}
	if(L->numItems==0){//if theres nothing in the list you need to create a node in the front
		L->front=newNode(data);
		L->back=L->front;//then make the back=front because whens theres only one item in the list the back is also the front
	}else{//if there is items in the list
		L->front->prev=newNode(data);//you create a new node before the front
		L->front->prev->next=L->front;//connect it to the front
		L->front=L->front->prev;//then move the front back making the new node the new front
	}
	L->numItems++;//and no matter what you increment the number of items
}
void append(List L, int data){//insert to the back of the list
	if(L==NULL){//check if the list is initialized
		printf("List Error: append() called on NULL List reference\n");
		exit(1);
	}
	if(L->numItems==0){//if theres nothing in the list create a new node in the back
		L->back=newNode(data);
		L->front=L->back;//then make front=back because when thers only one item in the list the front is also the back
	}else{//otherwise
		L->back->next=newNode(data);//create a new node after the back node
		L->back->next->prev=L->back;//connect it to the back
		L->back=L->back->next;//then move the back forward one making the new node the new back
	}
	L->numItems++;//and no matter what increment the number of items

}
void insertBefore(List L, int data){//insert a node before the cursor

	if(L==NULL){//check if the list is initialized
		printf("List Error: insertBefore() called on NULL List reference\n");
		exit(1);
	}
	if(L->numItems<=0){//if we dont have any items in the list throw an error message and exit
		printf("List Error: insertBefore() called on empty List\n");
		exit(1);
	}else if(L->index<0){//if our index is undefined throw an error message and exit
		printf("List Error: insertBefore() called on invalid cursor\n");
		exit(1);
	}else if(L->index==0){//if we have only one node in the list
		Node P=L->front;//make node P equal the front
		L->front->prev=newNode(data);//create a new node before the front
		L->front->prev->next=P;//connect that node back to the front
		L->front=L->front->prev;//then move the front back to the new front
	}else{//if we have more than one item in the list
		Node P=L->cursor;//have Node P equal the cursor
		Node R=P->prev;//save the Node pointer right before it so we can reconnect it later
		P->prev=newNode(data);//create a new Node in the previous section of Node P
		P->prev->next=P;//connect it back to P
		R->next=P->prev;//connect the original P previous to the new P previous therefore reconnecting the list forwards
		P->prev->prev=R;//then connect the new node's (P.previous) previous to the old P.prev therefore reconnecting the new list backwards
		P=P->prev;//then move the pointer P back 1 so its now pointing at the changed Node P
	}
	L->numItems++;//increment the number of items no matter what
}
void insertAfter(List L, int data){//insert a node after the cursor
	if(L==NULL){//check if the list is initialized
		printf("List Error: insertAfter() called on NULL List reference\n");
		exit(1);
	}
	if(L->numItems<=0){//if we dont have any items in the list throw an error message and exit
		printf("List Error: insertAfter() called on empty List\n");
		exit(1);
	}else if(L->index<0){//if the index is undefined we cant delete after so throw an error message and exit
		printf("List Error: insertAfter() called on invalid cursor\n");
		exit(1);
	}else if(L->index==(L->numItems-1)){//if the index is at the back
		Node P=L->back;//put the back in a temp Node
		L->back->next=newNode(data);//create a new Node after the back
		L->back->next->prev=P;//have the new Nodes previous connect to the old back
		L->back=L->back->next;//then move the back forwards so that its at the new back
	}else{//otherwise
		Node P=L->cursor;//have P point to the cursor
		Node R=P->next;//save the next item after the cursor
		P->next=newNode(data);//produce a new item after the cursor
		P->next->prev=P;//connect that back to P so that new Node is connected to the list in the backwards directions
		R->prev=P->next;//connect the old next to the new node therefore reconnecting the list forwards
		P->next->next=R;//connect the new nodes next to R so that R and everything after R can go backwards as well
		P=P->next;//then move the list to the new node
	}
	L->numItems++; //increment the number of items no matter what
}
void deleteFront(List L){//deletes the first item in the list
	if(L==NULL){//check if the list is initialized
		printf("List Error: deleteFront() called on NULL List reference\n");
		exit(1);
	}
	if(L->numItems<=0){//if we have no items in the list throw an error message and exit
		printf("List Error: deleteFront() called on empty List\n");
		exit(1);
	}else{//otherwise proceed
		Node R=L->front;
		if(L->front->next==NULL){//if the list is only one item
			L->front=NULL;//just empty the front
			L->back=L->front;//then make the back null
		}else{//otherwise
			L->front=L->front->next;//move the front forward
			L->front->prev=NULL;//and make everything behind it null
		}
		freeNode(&R);//free the node representing the old front to prevent memory leaks
		L->numItems--;//no matter what decrement the number of items
	}
}

void deleteBack(List L){//delete the last item in the list
	if(L==NULL){//check if the list is initialized
		printf("List Error: deleteBack() called on NULL List reference\n");
		exit(1);
	}

	if(L->numItems<=0){//if we have no items in the list throw an error message and exit
		printf("List Error: deleteBack() called on empty List\n");
		exit(1);
	}else{//otherwise
		Node R=L->back;
		if(L->back->prev==NULL){//if the list is only one item
			L->back=NULL;//just make the back null
			L->front=L->back;//then make the front null
		}else{//otherwise
			L->back=L->back->prev;//move the back backwards
			L->back->next=NULL;//and make the item after it null
		}
		freeNode(&R);//free the node representing the old back to prevent memory leaks
		L->numItems--;//no matter what decrement the number of items
	}
}
void delete(List L){//delete the item at the cursor
	if(L==NULL){//check if the list is initialized
		printf("List Error: delete() called on NULL List reference\n");
		exit(1);
	}
	if(L->numItems<=0){//if there is no items in the list throw an error message and exit
		printf("List Error: delete() called on empty List\n");
		exit(1);
	}else if(L->index<0){//if the index is undefined we cant ver well delete it so throw an error message and exit
		printf("List Error: delete() called on invalid index\n");
		exit(1);
	}else{//otherwise
		Node R=L->cursor;
		Node P=L->cursor;//make a temporary node point to ht ecursor
		if(P->prev==NULL && P->next==NULL){//only one item in the list
			P=NULL;//just set the item to null
		}else if(P->prev==NULL){//at the start of the list
			L->front=L->front->next;//move the front forward
			L->front->prev->next=NULL;//disconnect the item from the list
			L->front->prev=NULL;//disconnect the list from the item
		}else if(P->next==NULL){//at the end of the list
			L->back=L->back->prev;//move the back backwards one
			L->back->next->prev=NULL;//disconnect the item from the list
			L->back->next=NULL;//disconnect the list from the item
		}else{ //middle of the list
			P->prev->next=P->next;//connect the items previous next to its next skipping over it going forwards
			P->next->prev=P->prev;//connect the items next prev to its previous skipping over it backwards
			P->next=NULL;//then set the nodes next and prev to null disconnecting it from the list
			P->prev=NULL;
		}
		freeNode(&R);//and no matter what decrement the number of items, set the cursor to null, make the index undefined, and free the node, since we have deleted the cursor
		L->numItems--;
		L->index=-1;
	}
}
List copyList(List L){//copies the list over to a new list that is then returned
	  if(L==NULL){//check if the list is initialized
                printf("List Error: printList() called on NULL List reference\n");
                exit(1);
        }
	List A=newList();//make a new lsit
	Node N=L->front;//point a node at the front of the old list
	while(N!=NULL){//while the old list is not empty
		append(A,N->item);//add the item to the back of the new list
		N=N->next;//and move the old list forwards
	}
	return A;//then return the list
}

void printList(FILE *out, List L){//prints out the list to a file
	if(L==NULL){//check if the list is initialized
		printf("List Error: printList() called on NULL List reference\n");
		exit(1);
	}
	for(Node N=L->front; N!=NULL; N=N->next){//loop through the entire list starting at the front
		fprintf(out,"%d ", N->item);//printing the item with a space
	}
}


