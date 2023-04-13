//Shayan Salsabilian
//ssalsabi
//pa1
//Lex.java

import java.io.*;
import java.util.Scanner;

public class Lex{
	public static void main(String[] args) throws IOException{
		Scanner in = null;//create two scanners of the infile
		Scanner in1=null;
		PrintWriter out=null;//create writer to the ut file
		String line=null;//create an empty string that will contain each line as we go
		String[] token=null;//array to hold the splitting up of the lines
		String[] mainArray=null;//to hold the final finished array that was entered
		int i=0, lineNumber=0;//lineNumber to create the size of the main array and counter to count to it
		if(args.length!=2){//makes sure we have 2 and only 2 arguments if not print error message and exit
			System.err.println("Usage: Lex <infile> <outfile>");
			System.exit(1);
		}
		in=new Scanner(new File(args[0]));//make the scanners equal the file in args0
		in1=new Scanner(new File(args[0]));
		out= new PrintWriter(new FileWriter(args[1]));//makes the writer equal the file in args 1
		while(in.hasNextLine()==true){//will count the lineNumbers as long as there is a next line
			lineNumber++;
			line=in.nextLine();
		}
		mainArray=new String[lineNumber];//makes the array the size of the lineNumbers
		while(in1.hasNextLine()==true){//puts the lines in the array as long as there is a next line
			line=in1.nextLine()+" ";//get the next line each time
			token=line.split("\n");//split it aroung the new line character
			mainArray[i]=token[0];//place that line in the main array
			i++;//increment the counter for the main array
		}
		i=1;//start the counter at 1 cause 0 will already be prepended
		List A=new List();//make a new list
		A.prepend(0);//place the first indice in the list
		while(i<lineNumber){//go until the counter equals line number meaning all the indices were placed in the list
			A.moveFront();//start at the front of the list each time
			while(mainArray[i].compareTo((mainArray[A.get()]))>=0){//while the current indice is greater than the cursor increment the cursor
				A.moveNext();
				if(A.index()==-1){//if we reach the end of the list
					A.append(i);//just append to the back of the list and break out
					break;
				}
			}

			if(((A.index())!=-1)&&mainArray[i].compareTo(mainArray[A.get()])<0){//otherwise insert before the cursor
				A.insertBefore(i);
			}
			i++;//increment to go to the next indice
		}
		A.moveFront();//move to the front of the now completed list
		for( i=0; i<lineNumber; i++){//print out the main array indices in the order gathered from the list to the out file
			
			out.println(mainArray[A.get()]);//A.get will get the item at the cursor which will be the indice needed for it to be in order
			A.moveNext();//then cursor will be moved forward
		}
		in.close();//then close both files
		out.close();
	}
}
