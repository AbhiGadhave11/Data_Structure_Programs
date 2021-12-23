/* Java program to show the insertion operation
* of Unrolled Linked List */

import java.util.Scanner;
import java.util.Random;

class Node 
{
	Node next;
	int array_size;
	int Arr[];

	public Node(int n)
	{
		next = null;
		array_size = 0;
		Arr = new int[n];
	}
}

// Operation of Unrolled Function
class UnrolledLL
{

	private Node first;
	private Node last;

	int size_node;
	int nNode;

	UnrolledLL(int capacity)
	{
		first = null;
		last = null;
		nNode = 0;
		size_node = capacity + 1;
	}

	void Insert(int no)
	{
		if (first == null) 
		{
			first = new Node(size_node);
			first.Arr[0] = no;
			(first.array_size)++;
			last = first;
			
		}
        else if (last.array_size + 1 < size_node) 
		{
			last.Arr[last.array_size] = no;
			last.array_size++;
		}
		else 
		{
			Node newn = new Node(size_node);
			int j = 0;
			for (int i = last.array_size / 2 + 1;i < last.array_size;i++)
			{
				newn.Arr[j] = last.Arr[i];
				j++;
			}

			newn.Arr[j++] = no;
			newn.array_size = j;
			last.array_size = last.array_size / 2 + 1;
			last.next = newn;
			last = newn;
		}
		nNode++;
	}

	void display()
	{
		System.out.println();
		Node temp = first;
		while (temp != null) 
		{
			for (int i = 0; i < temp.array_size; i++)
			{
				System.out.print("|"+temp.Arr[i]+"|-> ");
			}
			System.out.println("null");
			temp = temp.next;
		}
		System.out.println();
	}
}

class Unrollled1
{
	public static void main(String Args[])
	{
		UnrolledLL obj = new UnrolledLL(5);
		obj.Insert(10);
		obj.display();
		
		obj.Insert(11);
		obj.display();
		
		obj.Insert(21);
		obj.display();
		
		obj.Insert(51);
		obj.display();
		
		obj.Insert(101);
		obj.display();
		
		obj.Insert(111);
		obj.display();
		
		obj.Insert(121);
		obj.display();

		obj.Insert(151);
		obj.display();

		obj.Insert(191);
		obj.display();
	}
}
