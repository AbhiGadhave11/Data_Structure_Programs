import java.lang.*;
import java.util.*;

class Node
{
	public int data;
	public Node next;
	public Node prev;
}

class DoublyLL
{
	private Node first;
	private int size;

	public DoublyLL()
	{
		first = null;
		size = 0;
	}

	void InsertFirst(int no)
	{
		Node newn = null;
		newn = new Node();

		newn.data = no;
		newn.next = null;
		newn.prev = null;

		if(first == null)
		{
			first = newn;
		}
		else
		{
			newn.next = first;
			first.prev = newn;
			first = newn;
		}

		size++;
	}

	void InsertLast(int no)
	{
		Node newn = null;
		newn = new Node();

		newn.data = no;
		newn.next = null;
		newn.prev = null;

		if(first == null)
		{
			first = newn;
		}
		else
		{
			Node temp = first;
			while(temp.next != null)
			{
				temp = temp.next;
			}
			temp.next = newn;
			newn.prev = temp;

		}

		size++;
	}

	void DeleteFirst()
	{
		if(first == null)
		{
			return;
		}
		if(first.next == null)
		{
			first = null;
		}
		else
		{
			first = first.next;
			first.prev = null;
		}
		size--;
	}

	void DeleteLast()
	{
		if(first == null)
		{
			return;
		}
		if(first.next == null)
		{
			first = null;
		}
		else
		{
			Node temp = first;
			while(temp.next.next!=null)
			{
				temp = temp.next;
			}
			temp.next.prev = null;
			temp.next = null;
		}
		size--;
	}

	void InsertAtPos(int no,int iPos)
	{
		if((iPos<1)||(iPos>size+1))
		{
			return;
		}
		if(iPos == 1)
		{
			InsertFirst(no);
		}
		else if(iPos == size+1)
		{
			InsertLast(no);
		}
		else
		{
			Node newn = null;
			Node temp = first;
			newn = new Node();

			newn.data = no;
			newn.next = null;
			newn.prev = null;

			for(int i=1;i<(iPos-1);i++)
			{
				temp = temp.next;
			}
            newn.next = temp.next;
            temp.next.prev = newn;
            newn.prev = temp; 
			temp.next = newn;
			size++;
		}

	}

     void DeleteAtPos(int iPos)
     {
     	if((iPos<1)||(iPos>size+1))
		{
			return;
		}
		if(iPos == 1)
		{
			DeleteFirst();
		}
		else if(iPos == size+1)
		{
			DeleteLast();
		}
		else
		{

			Node temp = first;
			for(int i=1;i<(iPos-1);i++)
			{
				temp = temp.next;
			}
			Node targeted = temp.next;
			temp.next = targeted.next;
			targeted.next.prev = temp;
			targeted.next = null;
			targeted.prev = null;
			size--;
		}
     }

	void Display()
	{
		Node temp = first;
		while(temp!=null)
		{
			System.out.print("|"+temp.data+"|-> ");
			temp = temp.next;
		}
		System.out.println("null");
	}

	int Count()
	{
		return size;
	}


}

class Program264
{
	public static void main(String Arg[])
	{
		DoublyLL obj = new DoublyLL();
		obj.InsertFirst(51);
		obj.InsertFirst(21);
		obj.InsertFirst(11);
		obj.InsertFirst(10);
		obj.Display();
		int iRet = obj.Count();
		System.out.println("Total Number of Nodes are : "+iRet);
	
        obj.InsertLast(91);
        obj.InsertLast(101);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Total Number of Nodes are : "+iRet);
       
        obj.DeleteFirst();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Total Number of Nodes are : "+iRet);
	 
        obj.DeleteLast();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Total Number of Nodes are : "+iRet);

	    obj.InsertAtPos(151,3);
	    obj.Display();
        iRet = obj.Count();
        System.out.println("Total Number of Nodes are : "+iRet);
        
        obj.DeleteAtPos(3);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Total Number of Nodes are : "+iRet);
	}
}