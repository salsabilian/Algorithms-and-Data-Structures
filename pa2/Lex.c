//Shayan Salsabilian
//pa2
//Lex.c
//ssalsabi
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"

#define MAX_LEN 160

int main(int argc, char * argv[]){

	int count=0;//creating a counter to determine the size of the array
	FILE *in, *out, *in1;//make three files two for input files one for output files
	char line[MAX_LEN];//holds each line passed in
	int i=0;//start the counter at 0 
	//char tokenlist[MAX_LEN];
	// check command line for correct number of arguments
	if( argc != 3 ){//makes sure there is exactly three arguments
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}

	// open files for reading and writing 
	in = fopen(argv[1], "r");//read to infiles
	in1=fopen(argv[1], "r");
	out = fopen(argv[2], "w");//and write to one outfiles
	if( in==NULL ){//if any of the files are not there print an error message
		printf("Unable to open file %s for reading\n", argv[1]);
		exit(1);
	}
	if( in1==NULL ){
		printf("Unable to open file %s for reading\n", argv[1]);
		exit(1);
	}

	if( out==NULL ){
		printf("Unable to open file %s for writing\n", argv[2]);
		exit(1);
	}

	/* read each line of input file, then count and print tokens */
	while( fgets(line, MAX_LEN, in) != NULL)  {//run until we have no more lines to grab
		count++;//get the size of the array
	}

	char *mainArray[count];//create an array of the size we got from the last while loop
	char *token;//holds the string of each line each time
	char tokenlist[count][MAX_LEN];//will hold all the lines getting them from tokenlist
	while(fgets(line, MAX_LEN, in1) !=NULL){//runs until there are no more lines in the file
		strcpy(tokenlist[i], "");//initialize array position i so that it wont have random memory information in it
		token = strtok(line, "\n");//tokenize the current line
			strcat(tokenlist[i], token);//put that token into position i of the tokenlist array
			token = strtok(NULL, "\n");//null the token
		mainArray[i]=tokenlist[i];//put the tokenlist position i into main array position i
		i++;//increment i
	

	i=1;//reset i to 1
	List A=newList();//create a new list to hold the indices of the array
	prepend(A,0);//put the first indice in the array
	while(i<count){//loop through until all the indicies are organized correctly
		moveFront(A);//start at the front of the list
		while(strcmp(mainArray[i], mainArray[get(A)])>=0){//compare the current array value to the value at the indice where the cursor is 
			moveNext(A);//move to the next cursor element
			if(index(A)==-1){//if we fall off the list
				append(A,i);//append the item to the back of the list
				break;//and break out of the loop
			}
		}
		if(((index(A))!=-1) && (strcmp(mainArray[i], mainArray[get(A)])<0)){//if we haven't already appended to the end of the list and the current index value of the main array is less than the value at the index of the cursor
			insertBefore(A,i);//then insert before
		}
		i++;//then move on to the next indice
	}
	moveFront(A);
	for(i=0; i<count; i++){//print the entire list to the file out
	fprintf(out,"%s\n", mainArray[get(A)]);
	moveNext(A);
	}
	clear(A);//free the heap memory associated with the list
	freeList(&A);
	
	/* close files */
	fclose(in);
	fclose(in1);
	fclose(out);
}
