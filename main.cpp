#include<iostream>

using namespace std;

template <class T>
class linkedList
{
private:

	struct node
	{
	public:
		T data;
		node* next;
	};

	class iterator
	{
	private:
		friend class linkedList<T>;
		node* current;
	public:

		iterator()
		{
			current = nullptr;
		}

		iterator(node* c)
		{
			current = c;
		}

		T& operator*()
		{
			return (current->data);
		}

		iterator operator++()
		{
			// pre fix increment operator
			iterator ite = current->next;
			current = current->next;
			return ite;
		}

		bool operator != (iterator ite)
		{
			if (ite.current != current)
			{
				return true;
			}

			return false;
		}

		iterator operator++(int)
		{
			// post fix operator 
			iterator old = current;
			current = current->next;
			return old;
		}


	};

	node* tail , *head;

public:

	linkedList()
	{
		head = new node;
		tail = new node; 
		head->next = tail;
		tail->next = nullptr; 
	}

	iterator begin()
	{
		return (head->next);
	}

	iterator end()
	{
		return tail;
	}

	bool isEmpty()
	{
		if (head->next == tail)
		{
			return true; 
		}

		return false; 
	}

	void Remove(iterator ite)
	{
		//cout << "Remove Called"; 
		node* temp = head; 
		while (temp->next != tail)
		{
			if (temp->next == ite.current)
			{
				break; 
			}

			temp = temp->next; 
		}

		node* nodeToDelete = ite.current; 
		temp->next = nodeToDelete->next; 
		nodeToDelete = nullptr; 
	}

	void insert_using_iterator(iterator ite, T n)  // insert at which the current iterator is pointing 
	{
		node* temp = new node;
		temp->data = n; 
		temp->next = nullptr; 
		if (isEmpty())
		{
			head->next = temp; 
			temp->next = tail;
		}
		else
		{
			node* t = head;
			while (t->next != tail)
			{
				if (t->next == ite.current)
				{
					break; 
				}

				t = t->next; 
			}
			temp->next = ite.current; 
			t->next = temp; 
		}
	}

	void RemoveFirst()
	{
		Remove(begin()); 

	}

	void InsertAtTail(T n)
	{
		insert_using_iterator(end(), n); 
	}

	void insertAtHead(T n)
	{
		insert_using_iterator(begin(), n); 
	}

	void print()
	{
		if (!isEmpty())
		{
			linkedList<T>::iterator ite = begin(); 
			while (ite != end())
			{
			cout << *ite << " ";
			ite++; 
			}
		}
		else
			cout << "List is Empty \n"; 
	

	}

	void RemoveSublist()
	{
		linkedList<T>::iterator ite = begin(); 
		for (ite = begin(); ite != end(); ite++)
		{
			T binary = *ite; 
			if (binary == 1)
			{
				linkedList<T>::iterator ite1(ite.current);
				ite1++; 

				if (*ite1 == 0)
				{
					Remove(ite); 
				}

				for (; *ite1 != 1 && ite1 != end(); ite1++)
				{
					
					Remove(ite1); 
				}
				
			}
		}
	}

};

int main()
{
	linkedList<int> a; 

	int s = 0; 
	cout << "Enter -1 when you wish to end your input values : "; 
	while (s != -1)
	{
		cin >> s; 
		if(s != -1)
		a.InsertAtTail(s); 
	}

	cout << "Your List : \n"; 
	a.print(); 
	cout << endl;
	a.RemoveSublist();
	 
	cout << "Updated List : \n"; 
	a.print(); 
	cout << endl; 
	system("pause");
	return 0;
}
