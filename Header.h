#include "Header1.h"
//#include <iostream>
//using namespace std;

template<typename Type>
class circular_List {
	template<typename Type>
	struct Node {

		AvlTree<Type> tree;
		Node* next = NULL;
	};


	Node<Type>* head;
	int count;
public:

	circular_List() { head = NULL; count = 0; }

	void insert(AvlTree<Type> n)
	{
		if (!head)
		{
			head = new Node<Type>;
			head->tree = n;
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
			temp->next->tree = n;
			//cout << "insertion 2 " << temp->next->node->data << endl;
			temp->next->next = head; count++;

		}

	}

	void display()
	{
		Node<Type>* temp = head;
		while (temp->next != head)
		{
			temp->tree.display(temp->tree.root);
			temp = temp->next;
		}

		temp->tree.display(temp->tree.root);

	}

	int getcount() {

		return count;
	}

};