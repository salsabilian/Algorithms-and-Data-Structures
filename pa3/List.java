//Shayan Salsabilian
//ssalsabi
//pa3
//List.java
@SuppressWarnings("overrides")
public class List{
	private class Node{//the class node that will be consistently added to our list to add new data
		Object item;//data contained in the list
		Node prev;//will hold the previous item
		Node next;//will hold the next item since the list is doubly linked we need a previous and a next therefore making it bidirectional

		Node(Object x){//creates the node class with the items needed within it
			item=x;//insert the data into the item location
			prev=null;//set the previous and next Node in the list as null initially
			next=null;
		}
	}
	private Node front;//create a front and back so that we have an effective queue
	private Node back;
	private Node cursor;//temporary node that will point to the position in the list the client is currently "highlighting"
	private int index;//how you will move around the list
	private int numItems;//helps keep track of the number of items
	public List(){//The list class that will begin with a empty front and back node, an empty cursor node, numItems, and an undefined index (these values will change as nodes are added to the list) 
		front=null;//start the list as null with 0 items
		index=-1;//
		numItems=0;
		cursor=null;
		back=null;
	}
	int length(){//return the length of the list by returning numItems
		return numItems;

	}
	int index(){//will find where the cursor is currently pointing to by looping through the list and comparing nodes
		index=0;//start the index at 0
		for(Node N=front; N!=null; N=N.next){//run through the entire list 
			if((N)==(cursor)){//returning the index if the node on the list is the same as the cursor
				return index;
			}
			index++;//otherwise keep incrementing the counter
		}
		index=-1;
		return index;//if we go through the entire list and cant find the cursor that means the cursor is null and the user is not currently highlighting anything on the list therefore we should return -1 to show the index is undefined
	}
	Object front(){//returns the item at the front of the list
		if(numItems<=0){//if there is no items in the list throw an error message and exit
			System.err.println("List Error: front() called on empty List\n");
			System.exit(1);
		}
		return front.item;//otherwise return the item in front
	}
	Object back(){//returns the item at the back of the list
		if(numItems<=0){//if there is no items in the list return an error message and exit
			System.err.println("List Error: back() called on empty List\n");
			System.exit(1);
		}
		return back.item;//otherwise return the item at the back of the list
	}
	Object get(){//returns the item at the cursor
		if(numItems<=0){//if there is no items in the list throw an error message and exit
			System.err.println("List Error: get() called on empty List\n");
			System.exit(1);
		}
		if(index<0){//if the index is undefined then we cant get the item in the cursor so throw an error message and exit
			System.err.println("List Error: get() called on undefined index\n");
			System.exit(1);
		}
		return cursor.item;//otherwise return the item at the cursor
	}
	public boolean equals(Object x){//check if two lists are equal
		boolean eq=false;//start a boolean as false
		List A;
		if(x instanceof List){
			A=(List) x;
			Node N=this.front;//start at the front of the first list
			Node M=A.front;//start at the front of the second list
			eq=((this.length())==(A.length()));//check that there lengths are the same
			while(eq && N!=null){//until we reach the end of the list(since we already checked the lengths we only need to go till one of the lists are null) or until boolean is not true
				eq=((N.item)==(M.item));//check each item against each other
				N=N.next;//and move the lists forward
				M=M.next;
			}
		}
		return eq;//return the boolean
	}
	void clear(){//reset the list back to the empty state 
		numItems=0;//essentially returning everything back to what it was when we started the list
		index=-1;
		front=null;
		cursor=null;
		back=null;
	}
	void moveFront(){//move the cursor to the front of the list
		if(numItems!=0){//check if the list contains Nodes 
			cursor=front;//if it does have the cursor "highlight" front
			index=0;//and place the index at 0 implying cursor is at the front
		}
	}
	void moveBack(){//move the cursor to the back of the list
		if(numItems!=0){//check if the list contains Nodes
			cursor=back;//if it does then have the cursor "highlight" the back
			index=(numItems-1);//and change the index to numItems-1 implying the cursor is at the back
		}
	}

	void movePrev(){//move the cursor back 1
		if(index==0){//if were at the front of the list then we cant move back anymore
			index=-1;//so the index becomes undefined
			cursor=null;//and the cursor becomes null
		}else if(index!=-1){//if the cursor is  on the list, then we can move back (since we already checked if it was at the front
			index--;//decrement the index
			cursor=cursor.prev;//and move the cursor back 
		}
	}
	void moveNext(){//move the cursor forward 1
		if(index==(numItems-1)){//if were at the back of the list we cant move forward anymore
			cursor=null;//so set the cursor to null
			index=-1;//and make the index undefined
		}else if(index!=-1){//if the cursor is on the list, then we can move forward (since we already checked if it was at the front
			cursor=cursor.next;//move the cursor forward 1
			index++;//and increment the index
		}
	}
	void prepend(Object data){//insert to the front of the list
		if(numItems==0){//if theres nothing in the list you need to create a node in the front
			front=new Node(data);
			back=front;//then make the back=front because whens theres only one item in the list the back is also the front
		}else{//if there is items in the list
			front.prev=new Node(data);//you create a new node before the front
			front.prev.next=front;//connect it to the front
			front=front.prev;//then move the front back making the new node the new front
		}
		numItems++;//and no matter what you increment the number of items
	}
	void append(Object data){//insert to the back of the list
		if(numItems==0){//if theres nothing in the list create a new node in the back
			back=new Node(data);
			front=back;//then make front=back because when thers only one item in the list the front is also the back
		}else{//otherwise
			back.next=new Node(data);//create a new node after the back node
			back.next.prev=back;//connect it to the back
			back=back.next;//then move the back forward one making the new node the new back
		}
		numItems++;//and no matter what increment the number of items

	}
	void insertBefore(Object data){//insert a node before the cursor
		if(numItems<=0){//if we dont have any items in the list throw an error message and exit
			System.err.println("List Error: insertBefore() called on empty List\n");
			System.exit(1);
		}else if(index<0){//if our index is undefined throw an error message and exit
			System.err.println("List Error: insertBefore() called on invalid cursor\n");
			System.exit(1);
		}else if(index==0){//if we have only one node in the list
			Node P=front;//make node P equal the front
			front.prev=new Node(data);//create a new node before the front
			front.prev.next=P;//connect that node back to the front
			front=front.prev;//then move the front back to the new front
		}else{//if we have more than one item in the list
			Node P=cursor;//have Node P equal the cursor
			Node R=P.prev;//save the Node pointer right before it so we can reconnect it later
			P.prev=new Node(data);//create a new Node in the previous section of Node P
			P.prev.next=P;//connect it back to P
			R.next=P.prev;//connect the original P previous to the new P previous therefore reconnecting the list forwards
			P.prev.prev=R;//then connect the new node's (P.previous) previous to the old P.prev therefore reconnecting the new list backwards
			P=P.prev;//then move the pointer P back 1 so its now pointing at the changed Node P
		}
		numItems++;//increment the number of items no matter what
	}
	void insertAfter(Object data){//insert a node after the cursor 
		if(numItems<=0){//if we dont have any items in the list throw an error message and exit
			System.err.println("List Error: insertAfter() called on empty List\n");
			System.exit(1);
		}else if(index<0){//if the index is undefined we cant delete after so throw an error message and exit
			System.err.println("List Error: insertAfter() called on invalid cursor\n");
			System.exit(1);
		}else if(index==(numItems-1)){//if the index is at the back
			Node P=back;//put the back in a temp Node
			back.next=new Node(data);//create a new Node after the back
			back.next.prev=P;//have the new Nodes previous connect to the old back
			back=back.next;//then move the back forwards so that its at the new back
		}else{//otherwise
			Node P=cursor;//have P point to the cursor
			Node R=P.next;//save the next item after the cursor
			P.next=new Node(data);//produce a new item after the cursor
			P.next.prev=P;//connect that back to P so that new Node is connected to the list in the backwards directions
			R.prev=P.next;//connect the old next to the new node therefore reconnecting the list forwards
			P.next.next=R;//connect the new nodes next to R so that R and everything after R can go backwards as well
			P=P.next;//then move the list to the new node
		}	
		numItems++; //increment the number of items no matter what
	}
	void deleteFront(){//deletes the first item in the list
		if(numItems<=0){//if we have no items in the list throw an error message and exit
			System.err.println("List Error: deleteFront() called on empty List\n");
			System.exit(1);
		}else{//otherwise proceed
			if(front.next==null){//if the list is only one item
				front=null;//just empty the front
				back=front;//then make the back null
			}else{//otherwise
				front=front.next;//move the front forward
				front.prev=null;//and make everything behind it null
			}
			numItems--;//no matter what decrement the number of items
		}
	}
	void deleteBack(){//delete the last item in the list
		if(numItems<=0){//if we have no items in the list throw an error message and exit
			System.err.println("List Error: deleteBack() called on empty List\n");
			System.exit(1);
		}else{//otherwise
			if(back.prev==null){//if the list is only one item
				back=null;//just make the back null
				front=back;//then make the front null
			}else{//otherwise
				back=back.prev;//move the back backwards
				back.next=null;//and make the item after it null
			}
			numItems--;//no matter what decrement the number of items
		}
	}
	void delete(){//delete the item at the cursor
		if(numItems<=0){//if there is no items in the list throw an error message and exit
			System.err.println("List Error: delete() called on empty List\n");
			System.exit(1);
		}else if(index<0){//if the index is undefined we cant ver well delete it so throw an error message and exit
			System.err.println("List Error: delete() called on invalid index\n");
			System.exit(1);
		}else{//otherwise
			Node P=cursor;//make a temporary node point to ht ecursor
			if(P.prev==null && P.next==null){//only one item in the list
				P=null;//just set the item to null
			}else if(P.prev==null){//at the start of the list
				front=front.next;//move the front forward
				front.prev.next=null;//disconnect the item from the list
				front.prev=null;//disconnect the list from the item
			}else if(P.next==null){//at the end of the list
				back=back.prev;//move the back backwards one
				back.next.prev=null;//disconnect the item from the list
				back.next=null;//disconnect the list from the item
			}else{ //middle of the list
				P.prev.next=P.next;//connect the items previous next to its next skipping over it going forwards
				P.next.prev=P.prev;//connect the items next prev to its previous skipping over it backwards
				P.next=null;//then set the nodes next and prev to null disconnecting it from the list
				P.prev=null;
			}
			cursor=null;//and no matter what decrement the number of items, set the cursor to null, and make the index undefined since we have deleted the cursor
			numItems--;
			index=-1;
		}
	}
	public String toString(){//prints out the list in a clean way so we can see whats going on
		StringBuffer sb=new StringBuffer();//make a string buffer
		Node N=front;//point a node at the front
		while(N!=null){//while that node n is not null
			sb.append(N.item).append(" ");//add its item and a space
			N=N.next;//then move the node forward
		}
		return new String(sb);//at the end return the string
	}
}

