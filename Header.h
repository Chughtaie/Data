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
		
	public:
		Type id;
		Type hashed_id;
		Routing_Table Fht;
		AvlTree<Type> Tree;
		Machine* next;
		int count = 0;
		int tot = 0;
		Machine() { next = NULL; }

		
		string File(string key)
		{
			string name = "";

			if (count == 100 || count == 0) {
				tot++;
				name = "Treefile_Machine_" + id + "_" + to_string(tot) + ".txt";
				ofstream file(name);
				file << key << endl;
				file.close();
				count = 1;
			}
			else {

				fstream file;
				name = "Treefile_Machine_" + id + "_" + to_string(tot) + ".txt";
				file.open(name, std::ios::app);
				file << key << endl;
				file.close();
				count++;
			}
			return name;
		}
		
		bool Add(AvlNode<Type>* var) {		
			string s = File((var->data + "    " + var->key));
			var->path = s;
			var->line_no = to_string(count);
			Tree.Insert(var, &(Tree.root));
			return true;
		}

		
		
	};


	Machine<Type>* head;
	
public:

	Ring_DHT() { head = NULL; }
	

	bool Add(AvlNode<Type>* var) {
	
		if (head->id == var->mach)
		{
			head->Add(var);
			return true;
		}
		else {
		
			Machine<Type>* temp = head;

			while (temp->id < var->mach && temp->next != head) 			
				temp = temp->next;
			if (temp->id >= var->mach)
				temp->Add(var);
			else head->Add(var);
			
			return 1;
		
		}

	}
	
	

	void insert(Type idd, Type hid)
	{
		if (!head)
		{
			head = new Machine<Type>;
			head->id = idd;
			head->hashed_id = hid;
			//cout <<"insertion 1 " <<head->node->data << endl;
			head->next = head; //count++;
		}
		else
		{
			Machine<Type>* temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}

			temp->next = new Machine<Type>;
			temp->next->id = idd;
			temp->next->hashed_id = hid;
			//cout << "insertion 2 " << temp->next->node->data << endl;
			temp->next->next = head; //count++;

		}
	}

	void display()
	{
		Machine<Type>* temp = head;

		do{
			//temp->tree.display(temp->tree.root);
			cout << "\n\nsimple id " << temp->id << endl;
			cout<< "hashed id " << temp->hashed_id << endl;
			temp->Tree.display(temp->Tree.root);
			//cout << endl << endl;
			temp = temp->next;
		} while (temp->next != head);

		cout << "\n\nsimple id " << temp->id << endl;
		cout << "hashed id " << temp->hashed_id << endl;
		temp->Tree.display(temp->Tree.root);
		cout << endl << endl;
		//temp->tree.display(temp->tree.root);

	}

};