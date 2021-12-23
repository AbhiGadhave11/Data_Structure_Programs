import java.lang.*;
import java.util.*;

class Node
{
	public int data;
	public Node next;
	public Node prev;
}

class DoublyCL
{
	private Node first;
	private Node last;
	private int size;

	public DoublyCL()
	{
		first = null;
		last = null;
		size = 0;
	}

	public void InsertFirst(int no)
	{
		Node newn = null;
		newn = new Node();

		newn.data = no;
		newn.next = null;
		newn.prev = null;

		if((first==null)&&(last==null))
		{
			first = newn;
			last = newn;
		}
		else
		{
			newn.next = first;
			first.prev = newn;
			first = newn;
		}
		last.next = first;
		first.prev = last;
		size++;
	}

	void InsertLast(int no)
	{
		Node newn = null;
		newn = new Node();

		newn.data = no;
		newn.next = null;
		newn.prev = null;

		if((first==null)&&(last==null))
		{
			first = newn;
			last = newn;
		}
		else
		{
			last.next = newn;
			newn.prev = last;
			last = newn; 
		}
		last.next = first;
		first.prev = last;
		size++;
	}
    void DeleteFirst()
    {
    	if((first==null)&&(last==null))
		{
			return;
		}
		if(first == last)
		{
			first.prev = null;
			first.next = null;
		}
		else
		{
            Node temp = first;
            temp.prev = null;
            first = first.next;
			temp.next = null;
			
		}
		first.prev = last;
        last.next = first;
        size--;
    }

	void DeleteLast()
	{
		if((first==null)&&(last==null))
		{
			return;
		}
		if(first == last)
		{
			first.prev = null;
			first.next = null;
		}
		else
		{
			Node temp = last.prev;
			
			last.next = null;
			last.prev = null;
			last = temp;
		}
		first.prev = last;
        last.next = first;
        size--;
    }

	void InsertAtPos(int no,int iPos)
	{
		if((iPos<1)&&(iPos>size+1))
		{
			return;
		}
		if(iPos==1)
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
			newn = new Node();

			newn.data = no;
			newn.next = null;
			newn.prev = null;

			Node temp = first;
			for(int i=1;i<(iPos-1);i++)
			{
				temp = temp.next;
			}
			newn.next = temp.next;
			newn.prev = temp;
			temp.next.prev = newn;
			temp.next = newn;
			first.prev = last;
		    last.next = first;
		    size++;
		}
	}

	void DeleteAtPos(int iPos)
	{
		if((iPos<1)&&(iPos>size+1))
		{
			return;
		}
		if(iPos==1)
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
			
			first.prev = last;
		    last.next = first;
		    size++;

		}
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

class Program266
{
	public static void main(String Arg[])
	{
		DoublyCL obj = new DoublyCL();

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

		obj.InsertAtPos(151,2);
        obj.Display();
		 iRet = obj.Count();
		System.out.println("Total Number of Nodes are : "+iRet);

		obj.DeleteAtPos(4);
        obj.Display();
		iRet = obj.Count();
		System.out.println("Total Number of Nodes are : "+iRet);
	}
}