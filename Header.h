#include "Header1.h"
//#include <iostream>
//using namespace std;


class Jh {

public:
	virtual void lol()=0;
};


class Routing_Table { // doubly link list



	struct Node {
		string mech;
		string data;
		Jh* ptr;
		int val;
		Node* next;
		Node* prev;

		Node() { next = prev = NULL; data = mech = ""; }
	};

public:

	Node* head;
	int count;

	Routing_Table() { head =  NULL; count = 0; }

	void insert(int id,string space,string h)
	{
		if (!head)
		{
			head = new Node;
			head->val = id;
			head->data = space;
			head->mech = h;
		}
		else
		{
			Node* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			//temp->next = new Node;
			temp->next = new Node;
			temp->next->prev = temp;
			temp->next->data = space;
			temp->next->val = id;// (temp->val + 1);
			temp->next->mech = h;
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
			cout << "val data mech\t" <<temp->val << "\t" << temp->data << "\t" << temp->mech <<  endl;
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
struct Machine:public Jh {

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







template<typename Type>
class Ring_DHT {
public:
	


	Machine<Type>* head;
	int lol = 0;
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
		lol++;
	}



	string Succ(string log) {
	
		if (head->id == log)
			return head->id;
		else {

			Machine<Type>* temp = head;

			while (stoi(temp->id) < stoi(log) && temp->next != head)
				temp = temp->next;
			if (stoi(temp->id) >= stoi(log))
				return temp->id;
			else 
				return head->id;
		}
	}



	void Set(int* arr, int id) {

		Machine<Type>* temp = head;

		for (int p = 0; p < lol; p++) {		//for every machine

			for (int i = 1; i <= id; i++) {	//
				string h = to_string((int(stoi(temp->id) + pow(2, i - 1))) % int(pow(2, id)));
				temp->Fht.insert(i, Succ(h),h);
			}
			temp = temp->next;
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
			temp->Fht.display();
			//cout << endl << endl;
			temp = temp->next;
		} while (temp->next != head);

		cout << "\n\nsimple id " << temp->id << endl;
		cout << "hashed id " << temp->hashed_id << endl;
		temp->Tree.display(temp->Tree.root);
		temp->Fht.display();
		cout << endl << endl;
		//temp->tree.display(temp->tree.root);

	}

};