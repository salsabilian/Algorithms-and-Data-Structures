//Shayan Salsabilian
//pa3
//ssalsabi
//Sparse.java
import java.io.*;
import java.util.Scanner;
public class Sparse{
	public static void main(String[] args)throws IOException{
		Scanner in=null;//make a scanner and filewriter
		PrintWriter out=null;
		if(args.length !=2){//if we dont have exactly two arguments throw an error
			System.err.println("Usage: Sparse infile outfile");
			System.exit(1);
		}
		in=new Scanner(new File(args[0]));//otherwise the in is the file in args 0
		out = new PrintWriter(new FileWriter(args[1]));//the out is the file in args 1
		String token=null;//create a token string to hold whats passed in
		token=in.next();//grab the first item in the file the size of the matrix
		int i=Integer.parseInt(token);//parse it
		Matrix A=new Matrix(i);//make to matrix's of the size that was parsed
		Matrix B=new Matrix(i);
		token=in.next();//move to the next item
		int sizeA=Integer.parseInt(token);//parse it, this will be how many lines will make Matrix A
		token=in.next();//move to the next item
		int sizeB=Integer.parseInt(token);//parse it, this will be how many lines will make Matrix B
		token=in.nextLine();//move two lines forward to deal with the empty lines
		token=in.nextLine();
		for(i=1; i<=sizeA; i++){//loop through for all the lines that make up matrix A
			token=in.next();//grab the row
			int row=Integer.parseInt(token);//parse it
			token=in.next();//grab the column
			int column=Integer.parseInt(token);//parse it
			token=in.next();//grab the value
			double value=Double.parseDouble(token);//parse it
			A.changeEntry(row, column, value);//put it in the Matrix
		}
		token=in.nextLine();//move two lines forward to deal with the empty lines
		token=in.nextLine();
		for(i=1; i<=sizeB; i++){//loop through for all the lines that make up Matrix B
			token=in.next();//grab the row
			int row=Integer.parseInt(token);//parse it
			token=in.next();//grab the column
			int column=Integer.parseInt(token);//parse it
			token=in.next();//grab the value
			double value=Double.parseDouble(token);//parse it
			B.changeEntry(row, column, value);//put it into the matrix
		}
		int nonzeros=A.getNNZ();//get and print the nonzero value
		out.println("A has "+nonzeros+" non-zero entries:");
		out.println(A);	//print the matrix to file
		nonzeros=B.getNNZ();//get and print the nonzero value
		out.println("B has "+nonzeros+" non-zero entries:");
		out.println(B);//print the matrix to file
		out.println("(1.5)*A =");
		Matrix C=A.scalarMult(1.5);//scalar multiply the matrix by 1.5
		out.println(C);//print the matrix to file
		out.println("A+B =");
		C=A.add(B);//add Matrix A to Matrix B then put it into Matrix C
		out.println(C);//print that matrix to file
		out.println("A+A =");
		C=A.add(A);//add Matrix A to Matrix A then put it into Matrix C
		out.println(C);//print that matrix to file
		out.println("B-A =");
		C=B.sub(A);//subtract Matrix B from Matrix A then put it into Matrix C
		out.println(C);//print that matrix to file
		out.println("A-A =");
		C=A.sub(A);//subtract Matrix A from Matrix A then put it into Matrix C
		out.println(C);//print that matrix to file
		C=A.transpose();//transpose Matrix A and put it into Matrix C
		out.println("Transpose(A) =");
		out.println(C);//print that matrix to file
		out.println("A*B =");
		C=A.mult(B);//Multiply matrix A by Matrix B and put it into Matrix C
		out.println(C);//print that matrix to file
		out.println("B*B =");
		C=B.mult(B);//Multiply Matrix B by Matrix B and put it into Matrix C
		out.println(C);//print that matrix to file
		in.close();//then close both files
		out.close();
	}
}
