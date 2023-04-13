
public class ListTest{
public static void main(String[] args){
List A = new List();
        A.prepend(5);
        A.prepend(65);
        A.prepend(43);
        A.prepend(2);
        A.prepend(8);
        A.prepend(1);
	if(A.length()==A.index()){
	System.out.println("Passed\n");
	}else{
	System.out.println(A.index()+" "+A.length());
	}
        A.moveBack();
	if(A.length()==A.index()){
	System.out.println("Passed\n");
	}else{
	System.out.println(A.index()+"");
	}
        A.deleteBack();
	System.out.println(A.index());
	List B=new List();
	List C=new List();
	B.append(1);
	C.append(1);
	B.append(2);
	C.append(2);
	System.out.println(B);
	System.out.println(C);
	System.out.println(B.equals(C));
	List D = new List();
        D.append(1);
        D.append(2);
	D.append(4);
	D.append(5);
        D.moveFront();
	System.out.println("List1:"+D);
	System.out.println("index1:"+D.index());
	System.out.println("get:"+D.get());
        D.delete();
	System.out.println("List:"+D);
	System.out.println("index"+D.index());
        D.append(3);
        D.append(5);
        D.moveFront();
	System.out.println(D);
	System.out.println(D.index());
        D.insertAfter(12);
        D.delete();
	System.out.println(D);
	List E=new List();
	E.append(1);
	E.append(2);
	E.append(3);
	E.moveFront();
	E.insertBefore(6);
	E.get();
	if((E.index())==1){
	System.out.println("hurrah");
	}
	E.moveNext();
	E.deleteFront();
	E.get();
	if(E.index()==1){
	System.out.println("Hurrah Again!");
	}
	 E = new List();
        E.prepend(1);
        E.prepend(1);
        E.prepend(1);
        E.moveFront();
        E.prepend(1);
        E.prepend(1);
        E.prepend(1);
        E.prepend(1);
        E.prepend(1);
        if ((E.index()) == 5){
 System.out.println("did it work?");
}
}
}
