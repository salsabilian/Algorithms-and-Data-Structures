//Shayan Salsabilian
//pa3
//ssalsabi
//MatrixTest.java
public class MatrixTest{
	public static void main(String[] args){
		Matrix A= new Matrix(100);//make to Matrices of size 100
		Matrix B= new Matrix(100);
		System.out.println("Beginning getSize() Tests:");
		System.out.println("	Does getSize() return the right size?");
		if(A.getSize()==100){//make sure the size is 100
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning getNNZ() Test:");
		System.out.println("	Does getNNZ() return the right size?");
		A.changeEntry(1, 3, 6);//add some things to the list
		A.changeEntry(1,2, 5);
		A.changeEntry(1,1,1);
		A.changeEntry(1,1,0);
		if(A.getNNZ()==2){//check how many nonzero entries we have
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning Equals Test:");
		B.changeEntry(1,3,6);//match whats in the other matrices
		B.changeEntry(1,2,5);
		System.out.println("	Does equals work correctly when the matrix matches?");
		if(A.equals(B)==true){//compare them
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		B.makeZero();//emptry the matrix
		System.out.println("	Does equals work correctly when the matrix doesn't match");
		if(A.equals(B)==false){//compare them again
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning makeZero() Test:");
		System.out.println("	Does makeZero() have the right amount of nonzero entries when done?");
		if(B.getNNZ()==0){//check that there is nothing in B after we called makeZero earlier
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning copy() Test:");
		System.out.println("	Does copy() work correclt?");
		A.changeEntry(1, 1, 1);
		Matrix C= A.copy();//make a copy of A
		if(A.equals(C)==true){//check to make sure its equal
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning toString() Test:");
		System.out.println("The following test should print: 1:(1, 1.0) (2,5.0) (3,6.0)");
		System.out.print("		"+A); 
		System.out.println("Beginning changeEntry Test:");
		System.out.println("The following test should print:");
		System.out.println("		1:(1, 1.0) (2, 5.0) (3, 6.0)");
		System.out.println("		2:(1, 4.0) (2, 7.0) (3, 8.0)");
		System.out.println("		67:(4, 8.0)"); 
		A.changeEntry(2, 1, 4);//add a bunch of entries
		A.changeEntry(2,2,6);
		A.changeEntry(2, 2, 7);
		A.changeEntry(2, 3, 8);
		A.changeEntry(67, 4, 8);
		System.out.println(A);//printout the matrix
		System.out.println("Beginning scalarMult() Test:");
		C=A.scalarMult(2);//multiply by two
		System.out.println("The following test should print:");
		System.out.println("            1:(1, 2.0) (2, 10.0) (3, 12.0)");
		System.out.println("            2:(1, 8.0) (2, 14.0) (3, 16.0)");
		System.out.println("            67:(4, 16.0)");
		System.out.println(C);//print out the list
		System.out.println("Beginning add() Test:");
		A=A.add(A);//add by itself
		System.out.println("	Does add() work correctly?");
		if(A.equals(C)){//check to see if adding by 2 is equal to adding by itself
		System.out.println("		Passed");
		}else{
		System.out.println("		Failed");
		}
		System.out.println("Beginning subtract() Test:");
		C=C.sub(A);//subtract by the same values
		System.out.println("	The following test should print nothing");
		System.out.println(C);//should be empty
		System.out.println("Beginning Transpose() Test:");
		A=A.transpose();//transpose the matrix
		  System.out.println("	The following test should print:");
                System.out.println("            1:(1, 2.0) (2, 8.0)");
                System.out.println("            2:(1, 10.0) (2, 14.0)");
		System.out.println("	    3:(1, 12.0) (2, 16.0)");
		System.out.println("	    4:(67, 16.0)");
		System.out.println(A);//print out the now transposed matrix
		System.out.println("Beginning mult() Test:");
		C=A.mult(A);//multiply the matrix by itself
		System.out.println("	The following test should print:");
		System.out.println("		1: (1,84.0) (2, 128.0)");
		System.out.println("		2: (1, 160.0) (2, 276.0)");
		System.out.println("		3: (1, 184.0) (2, 320.0)");
		System.out.println(C);	//print out the results
	}
}
