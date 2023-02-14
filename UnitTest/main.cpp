#include "unit_test.h"
#include <iostream>

template <typename T>
class Node {
public:
	T data;
	Node<T>* next = NULL;

	Node(T value) : data(value)
	{
	}
};

template<typename T>
class LinkedList {
public:
	Node<T>* first;
	Node<T>* last;

	LinkedList()
	{
		first = NULL;
		last = NULL;
	}


	int GetSize()
	{
		Node<T>* n = first;
		int size = 0;
		while (n != NULL)
		{
			size++;
			n = n->next;
		}
		return size;
	}

	void Append(T value)
	{
		Node<T>* element = new Node<T>(value);
		if (first == NULL)
		{
			first = element;
		}
		if (last)
		{
			last->next = element;
		}
		last = element;
	}

	void RemoveElement(T element)
	{
		// is element in LinkedList .. *search*
		Node<T>* n = first;
		Node<T>* p = first;
		while (n != NULL)
		{
			if (n->data == element)
			{
				if (first == last)
				{
					first = NULL;
					last = NULL;
				}
				if (p == n)
				{
					first = n->next;
				}
				p->next = n->next;
				last = lastElement();
				delete n;
				break;
			}
			p = n;
			n = n->next;
		}
	}

	~LinkedList()
	{
		Node<T>* n = first;
		while (n != NULL)
		{	
			Node<T>* temp = n;
			n = n->next;
			delete temp;
		}
	}
private:
	Node<T>* lastElement()
	{
		Node<T>* n = first;
		while (n != NULL)
		{
			if (n->next == NULL)
			{
				break;
			}
			n = n->next;
		}
		return n;
	}
};



int main()
{
	RunAllTests();
	return 0;
}


UNIT_TEST(Llist, create_list_isLastNull)
{
	LinkedList<int> myList;
	Assert(myList.last == NULL, "last is not equal to null");
}

UNIT_TEST(LList, create_list_with_one_element)
{
	LinkedList<int> myList;
	myList.Append(5);
	Assert(myList.last->data == 5, "one element could not been added");
	Assert(myList.first == myList.last, "first and last element are different");
}

UNIT_TEST(Llist, remove_one_element)
{
	LinkedList<int> myList;
	myList.Append(3);
	myList.RemoveElement(3);
	Assert(myList.first == NULL, "first element is not null");
	Assert(myList.last == NULL, "last element is not null");
}

UNIT_TEST(LList, get_size_2_elements)
{
	LinkedList<int> myList;
	myList.Append(2);
	myList.Append(3);
	Assert(myList.GetSize()==2, "list size is not equal to 2");
}


UNIT_TEST(LList, add_three_remove_second)
{
	LinkedList<int> myList;
	myList.Append(1);
	myList.Append(2);
	myList.Append(3);
	myList.RemoveElement(2);
	Assert(myList.GetSize() == 2, "list size is not equal to 2");
}

UNIT_TEST(Llist, add_two_remove_last_pointer_to_firstHM)
{
	LinkedList<int> myList;
	myList.Append(1);
	myList.Append(2);
	myList.RemoveElement(2);
	Assert(myList.last->data == 1, "something went wrong");
}
UNIT_TEST(Llist, get_size_add_two_remove_last)
{
	LinkedList<int> myList;
	myList.Append(1);
	myList.Append(2);
	myList.RemoveElement(2);
	Assert(myList.GetSize()== 1, "size is not equal to one");
}

UNIT_TEST(LList, add_three_remove_last)
{
	LinkedList<int> myList;
	myList.Append(1);
	myList.Append(2);
	myList.Append(3);
	myList.RemoveElement(3);
	Assert(myList.last->data == 2, "last data is not equal to 2");
}

UNIT_TEST(LList, add_two_remove_first)
{
	LinkedList<int> myList;
	myList.Append(1);
	myList.Append(2);
	myList.RemoveElement(1);
	Assert(myList.first->data == 2, "first element is not equal to 2");
	Assert(myList.last->data == 2, "last element is not equal to 2");
	Assert(myList.GetSize() == 1, "size is not equal to 1");
}


