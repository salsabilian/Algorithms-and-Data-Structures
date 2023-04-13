//Shayan Salsabilian
//ssalsabi
//pa3
//Matrix.java
@SuppressWarnings("overrides")//stops the warning messages from showing up
public class Matrix{
	private int length=0;//holds the length for accessing later
	private int nonzeros=0;//holds all the nonzero entries
	private List[] M;//so we can access each of the lists in matrices
	private class Entry{//a private class that will be each entry in the Matrix
		private int column=0;//has a column and value
		private double value=0;
		Entry(int x, double y){//so we can put the column and value in
			column=x;
			value=y;
		}

	}
	Matrix(int n){//constructor for the Matrix
		if(n<1){//if the user attempts to make a matrix with a negative size throw an error
			System.err.println("Matrix Error: Matrix size is too small to produce a Matrix\n");
			System.exit(1);
		}else{//otherwise
			length=n;//save the length for the getSize function
			M=new List[n+1];//make an array of list to represent the matrix
			for(int i=0; i<=n; i++){
				M[i]=new List();//initialize all those lists
			}

		}
		nonzeros=0;//set the value of nonzeros to 0

	}
	int getSize(){
		return length;	//return the length we saved from the contructor
	}
	int getNNZ(){
		return nonzeros;//return the nonzeros which we declared above and will change in change entry
	}
	public boolean equals(Object x){//compares to matrices checks if theyre equal or not returning true or false
		boolean eq=false;//start the boolean as false
		if(x instanceof Matrix){//make sure whats passed in is an instance of matrix
			Matrix S=((Matrix) x);//cast the Matrix
			eq=(this.getSize()==S.getSize());//boolean the size first
			if(eq){//if the size matches
				int i=1;
				while(i<=getSize() && eq){//run through each list
					List A=  S.M[i];//cast each list
					List B=  this.M[i];
					A.moveFront();//move to the front of the list
					B.moveFront();
					eq=(this.M[i].length()==S.M[i].length());//check the size of each list
					if(eq==false){//if any of the sizes dont match in length break and return
					break;
					}
					while((eq==true) && ( A.index()!=-1)){//otherwise check each item in each list
						Entry a=((Entry) A.get());//get the items at the cursor each time
						Entry b=((Entry) B.get());
						eq =((a.column == b.column)&&(a.value == b.value));//compare the items at the cursor each time
						A.moveNext();//move both cursors forward
						B.moveNext();
					}
					i++;//increment the counter
				}
			}
		}
		return eq;//return the boolean
	}
	void makeZero(){//empties the matrices
		for(int i=1; i<=this.getSize(); i++){
			this.M[i].clear();//clear each individual list in a loop
		}
		nonzeros=0;//wipe the nonzero entries
	}
	Matrix copy(){//copy one matrix to another
		Matrix S=new Matrix(this.getSize());//make a new contructor the size of the matrix passed in
		for(int i=1; i<=this.getSize(); i++){//loop through every list in the matrix
			this.M[i].moveFront();//move to the front of each list
			while(this.M[i].index()!=-1){//while we havent fallen off the list
				Entry target=(Entry) this.M[i].get();//get the item at the target
				S.changeEntry(i, target.column, target.value);//place it in our new list
				this.M[i].moveNext();//move the cursor forward to get the next item on the list
			}
		}
		return S;//return the Matrix
	}
	public String toString(){//print out the matrix correctly
		StringBuffer sb=new StringBuffer();//make a stringbuffer so that we can add a bunch of stuff to the list
		for(int i=1; i<=this.getSize(); i++){//loop through every list
			if(this.M[i].length()!=0){//if we dont have an empty row
				this.M[i].moveFront();//move to the front of each row
				sb.append((i)).append(": ");//print out that row number followed by a colon
				while(this.M[i].index()!=-1){//loop through each item in each row
					Entry x=((Entry) this.M[i].get());//get this specific entry
					sb.append("(").append(x.column).append(", ").append(x.value).append(") ");//print it out
					this.M[i].moveNext();//move the cursor forward
				}
				sb.append("\n");//after were done add a new line after
			}
		}
		return new String(sb);//return the string that holds the matrix
	}
	void changeEntry(int i, int j, double x){//adds and changes items in the list
		if((i<1) || i>this.getSize()){//if were outside of the Matrix in row throw an error
			System.err.println("Matrix Error: row is outside of the Matrice");
			System.exit(1);
		}else if(j<1||j>this.getSize()){//if were outside of the matrix in columns throw an error
			System.err.println("Matrix Error: column is outside of the Matrice");
			System.exit(1);
		}
		Entry Target=new Entry(0,0);//make an emptry target
		this.M[i].moveFront();//move to the front of the row needed
		while(this.M[i].index()!=-1){//while we havent fallen off the list
			Target= (Entry) this.M[i].get();//grab the entry
			if(Target.column==j){//check if the columns match, if they do break
				break;
			}
			this.M[i].moveNext();//if we havent found the column or fallen off the list move forward
		}
		if(this.M[i].index()==-1){//if out index is -1
			Target=new Entry(0,0);//make the target be empty, because it hasn't existed yet
		}
		if((Target.value!=0) && (x!=0)){//if both parts are not empty
			Entry test=(Entry) this.M[i].get();//just swap the value to the value we need
			test.value=x;
		}else if((Target.value==0) && (x!=0)){//if were adding something new to the list
			this.M[i].moveFront();//move to the front of the list
			Entry sort=new Entry(0,0);//start as an empty item
			while(this.M[i].index()!=-1){//go through the list
				sort= (Entry) this.M[i].get();//grabbing each entry
				if(sort.column>j){//if the next column entry is larger than the one we want
					break;//break
				}
				this.M[i].moveNext();//move to the next cursor item
			}
			Entry insert=new Entry(j, x);//make the entry we need
			if(this.M[i].index()==-1){//if were outside the list
				this.M[i].append(insert);//just append
			}else{
				this.M[i].insertBefore(insert);//otherwise insert before
			}
			nonzeros++;//increment the nonzero items
		}else if(Target.value!=0 && x==0){//if there is something in the entry, but we want nothing
			this.M[i].delete();//just delete 
			nonzeros--;//and decrement nonzeros
		}	

	}
	Matrix scalarMult(double x){//multiply each item in the list by a value
		Matrix A=new Matrix(this.getSize());//make a new matrix the same size as the contructor
		for(int i=1; i<=this.getSize(); i++){//for every list in the matrix
			this.M[i].moveFront();//move to the front of the list
			while(this.M[i].index()!=-1){//while we havent fallen off the list
				Entry original= (Entry) this.M[i].get();//get the item
				double newvalue=(original.value*x);//times it by x
				A.changeEntry(i, original.column, newvalue);//pass it back in
				this.M[i].moveNext();//and move to the next entry
			}
		}

		return A;//then return the matrix
	}
	Matrix add(Matrix M){//add to matrices together
		if(this.getSize()!=M.getSize()){//make sure each matrice is the same size
			System.err.println("Matrix Error: attempting to add two different size Matrices");
			System.exit(1);
		}
		Matrix N=M.copy();//copy one of the matrices to ensure the indices dont get messed up when we pass in the same list twice
		Matrix A=new Matrix(this.getSize());//make a new matrix  of the size of the other matrices
		for(int i=1; i<=this.getSize();i++){//add each item in the row together using addsubrows
			addsubrows(this.M[i], N.M[i], A, i, true);
		}
		return A;//then return the matrix
	}
	private void addsubrows(List A, List B, Matrix M, int row, boolean add){//adds/subtracts each item in the lists of the matrices together
		A.moveFront();//move to the front of each list
		B.moveFront();
		while(A.index()!=-1 || B.index()!=-1){//as long as we haven't fallen off each list
			if(A.index()==-1){//if one list ends before the other
				Entry copy= (Entry) B.get();//get the item in the list that hasn't fallen off
				if(add==true){//if its add then just put that item in
					M.changeEntry(row, copy.column, copy.value);
				}else{//otherwise times by -1 to deal with the fact that it is A-B
					M.changeEntry(row, copy.column, (-1*copy.value));
				}
				B.moveNext();//then move forward
			}else if(B.index()==-1){//if the other list has run out
				Entry copy1=(Entry) A.get();//do essentially the same thing except you dont have to account for A-B since its essentially the same as A-0
				M.changeEntry(row, copy1.column, copy1.value);
				A.moveNext();
			}else{//otherwise
				Entry Aaddsub=(Entry) A.get();//get each item
				Entry Baddsub=(Entry) B.get();
				if(Aaddsub.column==Baddsub.column){//if the columns match
					if(add==true){//add or subtract them together and pass them in
						M.changeEntry(row, Aaddsub.column, (Aaddsub.value+Baddsub.value));
					}else{
						M.changeEntry(row, Aaddsub.column, ((Aaddsub.value)-(Baddsub.value)));
					}
					A.moveNext();//then move each list forward
					B.moveNext();
				}else if(Aaddsub.column>Baddsub.column){//if one column is larger than the other
					if(add==true){//then add/subtract the column behind
						M.changeEntry(row, Baddsub.column,Baddsub.value);
					}else{//since A-B times by -1
						M.changeEntry(row, Baddsub.column, (-1*Baddsub.value));
					}
					B.moveNext();//then move the B list forward
				}else if(Baddsub.column>Aaddsub.column){//if the other column is larger
					M.changeEntry(row, Aaddsub.column, Aaddsub.value);//then add the column behind, dont have to account for A-B, since this is essentially the same as A-0
					A.moveNext();//then move the cursor forward
				}
			}
		}
	}
	Matrix sub(Matrix M){//subtracting one matrix from another
		if(this.getSize()!=M.getSize()){//make sure the sizes are the same
			System.err.println("Matrix Error: attempting to subtract two different size Matrices\n");
			System.exit(1);
		}
		Matrix N=M.copy();//make a copy to account for the chance that the same matrix is passed in twice
		Matrix A= new Matrix(this.getSize());//make a new matrix the size of the other ones
		for(int i=1; i<=this.getSize(); i++){//loop through each row in the matrix
			addsubrows(this.M[i], N.M[i], A, i, false);//subtracting each row
		}
		return A;//then return the Matrix
	}
	Matrix transpose(){//transpose the matrix passed in
		Matrix A=new Matrix(this.getSize());//make a new matrix of the size needed
		for(int i=1; i<=this.getSize(); i++){//loop through each row in the list
			this.M[i].moveFront();//move to the front of the cursor
			while(this.M[i].index()!=-1){//while we havent fallen off the end of the list
				Entry B=(Entry) this.M[i].get();//get the item at the cursor
				A.changeEntry(B.column, i, B.value);//switch the column and value and pass it in
				this.M[i].moveNext();//then move forward
			}
		}
		return A;//return the matrices
	}
	private static double dot(List P, List L){//dot product two lists
		P.moveFront();//move to the front of each list
		L.moveFront();
		double total=0;//start the value at 0
		while(P.index()!=-1 && L.index()!=-1){//if we have fallen off either of the lists we can stop, since it would be the same as timesing by 0 for every one after
			Entry Lmult=(Entry) L.get();//get entries at the cursor for both lists
			Entry Pmult=(Entry) P.get();
			if(Lmult.column==Pmult.column){//if the columns match
				total=total+((Lmult.value)*(Pmult.value));//multiply the values of each entry and add it to the running total
				P.moveNext();//move both lists forward
				L.moveNext();
			}else if(Lmult.column>Pmult.column){//otherwise move which ever list column is behind forward
				P.moveNext();//dont need to multiply, since the column doesn't match it would just be 0
			}else if(Pmult.column>Lmult.column){//same as before but with the other list
				L.moveNext();
			}
		}
		return total;//then return the total 
	} 
	Matrix mult(Matrix M){//multiply two matrixes together
		if(this.getSize()!=M.getSize()){//make sure the matrices are the same size
			System.err.println("Martix Error: attempting to multiply two different size Matrices\n");
			System.exit(1);
		}
		Matrix N=M.copy();//to deal with the edge case where the same matrix is passed in twice
		Matrix L=new Matrix(this.getSize());//make a new matrix the size of the constructor
		Matrix T=N.transpose();//transpose the second matrix
		for(int p=1; p<=this.getSize(); p++){//loop through each row of the first matrix
			for(int j=1; j<=this.getSize(); j++){//loop through each row of the second matrix
				double value=dot(this.M[p], T.M[j]);//run the dot product of each list
				L.changeEntry(p, j, value);//and then pass it into the matrix
			}
		}
		return L;//return the matrix
	}
}
