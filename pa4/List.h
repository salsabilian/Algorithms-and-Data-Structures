//Shayan Salsabilian
//ssalsabi
//List.h
//pa4
#ifndef _LIST_H_INCLUDE_//if List.h is included include these prototypes
#define _LIST_H_INCLUDE_

typedef struct ListObj* List;//make the list a pointer in the main file so we dont have to use the pointer each time

//function prototypes that we will be using in List.c

// Constructors-Destructors ---------------------------------------------------
List newList(void);
void freeList(List* pL);
 // Access functions -----------------------------------------------------------
 int length(List L);
 int index(List L);
 int front(List L);
 int back(List L);
 int get(List L);
 int equals(List A, List B);
// Manipulation procedures ----------------------------------------------------
 void clear(List L);
 void moveFront(List L);
 void moveBack(List L);
 void movePrev(List L);
 void moveNext(List L);
 void prepend(List L, int data);
 void append(List L, int data);
 void insertBefore(List L, int data);
 void insertAfter(List L, int data);
 void deleteFront(List L);
 void deleteBack(List L);
 void delete(List L);
// Other operations -----------------------------------------------------------
 void printList(FILE* out, List L);
 List copyList(List L);

#endif//ends the file
