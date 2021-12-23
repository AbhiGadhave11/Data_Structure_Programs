import java.lang.*;
import java.util.*;

class Node
{
	public int data;
	public Node next;
}

class SinglyCL
{
	private Node first;
	private Node last;
	private int size;

	public SinglyCL()
	{
		first = null;
		last = null;
		size = 0;
	}

	void InsertFirst(int no)
	{
		Node newn = null;
		newn = new Node();

		newn.data = no;
		newn.next = null;

		if((first == null)&&(first == null))
		{
			first = newn;
			last = newn;
		} 
		else
		{
			newn.next = first;
			first = newn;
		}
		last.next = first;
		size++;

	}

	void InsertLast(int no)
	{
		Node newn = null;
		newn = new Node();

		newn.data = no;
		newn.next = null;

		if((first == null)&&(first == null))
		{
			first = newn;
			last = newn;
		}
		else
		{
			last.next = newn;
			last = newn;
		}
		last.next = first;
		size++;
	}
	
	void DeleteFirst()
	{
		if((first==null)&&(last==null))
		{
			return;
		}
		if(first==last)
		{
			first.next = null;
		}
		else
		{
			first = first.next;
		}
		last.next = first;
		size--;
	}

	void DeleteLast()
	{
		if((first==null)&&(last==null))
		{
			return;
		}
		if(first==last)
		{
			first.next = null;
		}
		else
		{
			Node temp = first;
			while(temp.next!=last)
			{
				temp = temp.next;
			}
			last.next = null;
			last = temp;
		}
		last.next = first;
		size--;
	}

	void InsertAtPos(int no,int iPos)
	{
		if((iPos<1)||(iPos>size+1))
		{
			return ;
		}
		if(iPos==1)
		{
			InsertFirst(no);
		}
		else if(iPos==size+1)
		{
			InsertLast(no);
		}
		else
		{
			Node newn = null;
			newn = new Node();
			
			newn.data = no;
			newn.next = null;

			Node temp = first;
			for(int i=1;i<(iPos-1);i++)
			{
				temp = temp.next;
			}
			newn.next = temp.next;
			temp.next = newn; 


		}
		size++;
	}

	void DeleteAtPos(int iPos)
	{

		if((iPos<1)||(iPos>size+1))
		{
			return ;
		}
		if(iPos==1)
		{
			DeleteFirst();
		}
		else if(iPos==size+1)
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
			targeted.next = null;


		}
		size--;
	}
	void Display()
	{
		Node temp = first;
		do
		{
			System.out.print("|"+temp.data+"|-> ");
			temp = temp.next;
		}while(temp!=last.next);
		System.out.println();
	}

	int Count()
	{
		return size;
	}
}

class Program265
{
	public static void main(String Arg[])
	{
		SinglyCL obj = new SinglyCL();
		obj.InsertFirst(51);
		obj.InsertFirst(21);
		obj.InsertFirst(11);
		obj.InsertFirst(10);
		obj.Display();
		int iRet = obj.Count();
		System.out.println("Total Number of Nodes are : "+iRet);
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