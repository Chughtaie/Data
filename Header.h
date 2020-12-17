#include "Header1.h"
//#include <iostream>
//using namespace std;

struct Node {

	string data;
	Node* next;
	Node* prev;

	Node() { next = prev = NULL; data = ""; }
};


class Routing_Table { // doubly link list





public:

	Node* head;
	int count;

	Routing_Table() { head =  NULL; count = 0; }

	void insert(Node* n)
	{
		if (!head)
		{
			//head = new Node;
			head = n;
			//head = new Node;
			//head->next = head;
			//head->prev = head;
			// head->prev = head->
			//cout <<"insertion 1 " <<head->node->data << endl;
			//head->next = head; count++;
		}
		else
		{
			Node* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			//temp->next = new Node;
			temp->next = n;
			temp->next->prev = temp;
			//cout << "insertion 2 " << temp->next->node->data << endl;
			//temp->next->next = head; count++;

		}
		count++;
	}

	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		//temp->tree.display(temp->tree.root);

	}


	bool Delete(Node* n) {
	
		Node* temp = head;
		Node* temp1;

		if (head->data == n->data)
		{
			temp1 = head;
			head = head->next;
			count--;
			temp1 = NULL;
			return true;
		}
		else 
		while (temp != NULL)
		{
			if (temp->data == n->data)
			{	
				temp1 = temp->prev;
				temp1->next = temp->next;
				if(temp->next)
				temp->next->prev = temp1;
				count--;
				temp = NULL;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}


	int getcount() {

		return count;
	}

};




//================ RING ====================


template<typename Type>
class Ring_DHT {

	template<typename Type>
	struct Machine {
		
		Table Fht;
		AvlTree<Type> Tree;
		Machine* next;

		Machine() { next = NULL; }
	};


	Machine<Type>* head;
	int count;
public:

	Ring_DHT() { head = NULL; count = 0; }

	void insert(AvlTree<Type> n)
	{
		if (!head)
		{
			head = new Machine<Type>;
			head->tree = n;
			//cout <<"insertion 1 " <<head->node->data << endl;
			head->next = head; count++;
		}
		else
		{
			Machine<Type>* temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}

			temp->next = new Machine<Type>;
			temp->next->tree = n;
			//cout << "insertion 2 " << temp->next->node->data << endl;
			temp->next->next = head; count++;

		}

	}

	void display()
	{
		Machine<Type>* temp = head;
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