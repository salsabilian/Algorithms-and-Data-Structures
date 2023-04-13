//Shayan Salsabilian
//pa3
//ssalsabi
//ListTest.java
public class ListTest{
	public static void main(String [] args){
		List A= new List();//create a new list
		System.out.println("Beginning Length test:");
		int check=A.length();//check the length of an empty list
		System.out.println("	Does Length produce the right output for an empty list?");
		if(check==0){//make sure the return is 0
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		A.prepend("What");//insert multiple items of different types in the list
		A.append("Is");
		A.moveFront();
		A.insertBefore(8);
		check=A.length();//check the length
		System.out.println("	Does Length produce the right output for multiple items in the list?"); 
		if(check==3){//make sure the length is 3
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning Index test:");
		A.moveFront();//move to the front of the list
		System.out.println("	Does Index produce the right output if were at the front of the list");
		if(A.index()==0){//make sure the index is at 0
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		A.moveNext();//move into the middle of the list
		A.moveNext();
		System.out.println("	Does Index produce the right output if were in the middle of the list");
		if(A.index()==2){//make sure the index is still accurate in the middle of the list
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");	
		}
		System.out.println("Beginning Front() test:");
		int start= (int) A.front();//get the value of the front of the list
		System.out.println("	Does front() return the right value");
		if(start==8){//make sure we get the right value
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning Back() test:");
		String back= (String) A.back();//get the value at the back of the list
		System.out.println("	Does back return the right value?");
		if(back.compareTo("Is")==0){//make sure we get the right string
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning Get() Test:");
		A.movePrev();//move somewhere else in the list
		System.out.println("	Does get() return the right value of the cursor?");
		if(((String)(A.get())).compareTo("What")==0){//make sure our cursor returns the right string
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning Equals() Test:");
		List B=new List();//make a new list
		B.prepend("What");//add the stuff thts in List A to it
		B.append("Is");
		B.moveFront();
		System.out.println("	Does Equal() produce the right value if the lists are equal?");
		B.insertBefore(8);
		if((A.equals(B))==true){//check if our equals is working, since the lists are now identical
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		B.clear();//empty list b
		System.out.println("		Does Equals() produce the right value if the lists are not equal?");
		if((A.equals(B))==false){//make sure the list is no longer equal	
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning Clear() Test:");
		System.out.println("	Does Clear() make the list length 0?");
		if(B.length()==0){//check that the length is now 0 because our list is empty
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning moveFront() Test:");
		A.moveFront();//move to the front of the list
		System.out.println("	Does moveFront() have the right index?");
		if(A.index()==0){//make sure the index is in the right place after moveFront()
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning moveBack() Test:");
		A.moveBack();//move to the back of the list
		System.out.println("	Does moveBack() have the right index?");
		if(A.index()==2){//check to make sure the index is at the back
			System.out.println("		Passed");
		} else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning movePrev() Test:");
		A.movePrev();//move one back
		System.out.println("	Does movePrev() have the right index?");
		if(A.index()==1){//make sure the index is correct
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning moveNext() Test:");
		A.moveNext();//move one forward
		System.out.println("	Does moveNext() have the right index?");
		if(A.index()==2){//make sure the index is correct
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning prepend() Test:");
		System.out.println("	Does prepend() add to the front of the list correctly?");
		A.prepend(7);//add something to the front of the list
		if((int)(A.front())==7){//see if the value in the front is that value
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning append() Test:");
		System.out.println("	Does append() add to the back of the list correctly?");
		A.append("Life");//add something to the back of the list
		if(((String) A.back()).compareTo("Life")==0){//see if the back is that string
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning insertBefore() Test:");
		A.insertBefore("Test");//insert before the cursor
		A.movePrev();//move the cursor there
		System.out.println("	Does insertBefore() add behind the current index correctly?");
		String check2= (String) A.get();//grab the item at the cursor
		if(check2.compareTo("Test")==0){//make sure its what we passed in
			System.out.println("		Passed");
		}else{
			System.out.println("		Failed");
		}
		System.out.println("Beginning insertAfter() Test:");
		A.insertAfter(3.14);//insert after the cursor
		A.moveNext();//move the cursor there
		double check28=(double) A.get();//grab the item at the cursor
		System.out.println("	Does insertAfter() add in front of the current index correctly?");
		if(check28==3.14){//make sure its what we passed in
		System.out.println("		Passed");
		}else{
		System.out.println("		Failed");
		}
		System.out.println("Beginning deleteFront() Test:");
		A.deleteFront();//delete the item at the front of the list
		System.out.println("	Does deleteFront() work correctly?");
		if((int) A.front()!= 7){//check to make sure its not there anymore
		System.out.println("		Passed");
		}else{
		System.out.println("		Failed");
		}
		System.out.println("Beginning deleteBack() Test:");
		A.deleteBack();//delete the item at the back of the list
		System.out.println("	Does deleteBack() work correctly?");
		if(((String) A.back()).compareTo("Life")!=0){//check to make sure its not there anymore
		System.out.println("		Passed");
		}else{
		System.out.println("		Failed");
		}
		System.out.println("Beginning delete() Test:");
		System.out.println("	Does delete() work correctly?");
		A.delete();//delete the item at the cursor
		if(A.index()==-1){//make sure the index is now off the list
		System.out.println("		Passed");
		}else{
		System.out.println("		Failed");
		}
		System.out.println("Beginning toString() Test:");
		System.out.println("	The following Test should print: 8 What Test is");
		System.out.print("		");
		System.out.println(A);//print out the list
	}	
}
