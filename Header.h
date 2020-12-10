#include "Header1.h"
//#include <iostream>
//using namespace std;

template<typename Type>
class circular_List {
	template<typename Type>
	struct Node {

		AvlNode<Type>* node;
		Node* next = NULL;
	};


	Node<Type>* head;
	int count;
public:

	circular_List() { head = NULL; count = 0; }

	void insert(AvlNode<Type>* n)
	{
		if (!head)
		{
			head = new Node<Type>;
			head->node = n;
			//cout <<"insertion 1 " <<head->node->data << endl;
			head->next = head; count++;
		}
		else
		{
			Node<Type>* temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}

			temp->next = new Node<Type>;
			temp->next->node = n;
			//cout << "insertion 2 " << temp->next->node->data << endl;
			temp->next->next = head; count++;

		}

	}

	void display()
	{
		Node<Type>* temp = head;
		while (temp->next != head)
		{
			cout << temp->node->data << endl;
			temp = temp->next;
		}

		cout << temp->node->data << endl;

	}

	int getcount() {

		return count;
	}

};