#include "Header1.h"
//#include <iostream>
//using namespace std;

template<typename Type>
struct Node {
	string mech;	//actual machine
	string data;	//succ of machine
	//Machine<Type>* ptr = NULL;
	void* ptr;		//ptr of succ
	int val;		//1 = i

	Node* next;
	Node* prev;

	Node() { next = prev = NULL; data = mech = ""; }
};


template<typename Type>
class Routing_Table { // doubly link list


	

public:

	Node<Type>* head;
	int count;

	Routing_Table() { head = NULL; count = 0; }

	void insert(int id, string space, string h, void* p = NULL)
	{

		cout << "\nPROGRESS\n";
		if (!head)
		{
			head = new Node<Type>;
			head->val = id;
			head->data = space;
			head->mech = h;
			head->ptr = p;
		}
		else
		{
			Node<Type>* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			//temp->next = new Node;
			temp->next = new Node<Type>;
			temp->next->prev = temp;
			temp->next->data = space;
			temp->next->val = id;// (temp->val + 1);
			temp->next->mech = h;
			temp->next->ptr = p;
			//cout << "insertion 2 " << temp->next->node->data << endl;
			//temp->next->next = head; count++;

		}
		count++;
	}

	void display()
	{
		Node<Type>* temp = head;
		while (temp != NULL)
		{
			cout << "val data mech\t" << temp->val << "\t" << temp->data << "\t" << temp->mech << "\t" << temp->ptr << endl;
			temp = temp->next;
		}
		//temp->tree.display(temp->tree.root);

	}

	bool Delete(Node* n) {

		Node<Type>* temp = head;
		Node<Type>* temp1;

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
					if (temp->next)
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

	bool Check(string key) {
	
		Node<Type>* temp = head;

		while (temp)
		{



			temp = temp->next;
		}
	
	
	
	
	}


};







template<typename Type>
class Machine  {

public:
	Type id;
	Type hashed_id;
	Routing_Table<Type> Fht;
	AvlTree<Type> Tree;

	Machine* next;

	int count = 0;
	int tot = 0;

	Machine() { next = NULL; }

	void lol() {
		cout << endl;
	}

	string File(string key)
	{
		string name = "";

		if (count == 100 || count == 0) {
			tot++;
			name = "Treefile_Machine_" + id + "_(" + to_string(tot) + ").txt";
			ofstream file(name);
			file << key << endl;
			file.close();
			count = 1;
		}
		else {

			fstream file;
			name = "Treefile_Machine_" + id + "_(" + to_string(tot) + ").txt";
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

	

	//================ RING ====================

	



	Machine<Type>* head;
	int lol = 0;
	int id_space;
	int max;



	Ring_DHT(int Lo = 0, int ma = 0) { head = NULL; id_space = Lo; max = ma; }
	

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

	void Ret(Machine<Type>* temp) {}

	void* Search(Type key,int mac = 0) {

		int log = stoi(key) % max;
		Machine<Type>* temp = head;

		while (1) {

			Node<Type>* tempo = temp->Fht.head;

			if (to_string(log) == temp->id) { Ret(temp); return; }
			else if (temp->id < to_string (log)   && to_string(log) <= tempo->data) {	//p<e and e<=Ftp[1]
				temp = tempo->ptr; break;
			}
			else 
			while (tempo) {
				if (tempo->next != NULL)
					if (tempo->data < to_string(log) && tempo->next->data >= to_string(log))	//Ftp[j] < e < Ftp[j+1]
					{
						temp = tempo->ptr;
						break;
					}

				tempo = tempo->next;
			}
				
		}
	}


	

	void Set(int* arr, int id) {

		Machine<Type>* temp = head;

		for (int p = 0; p < lol; p++) {		//for every machine

			for (int i = 1; i <= id; i++) {	//
				string h = to_string((int(stoi(temp->id) + pow(2, i - 1))) % int(pow(2, id)));
				
				//Machine<Type>* loo = (Get_ptr(Succ(h)));
				//LoL<Type>* lp = new Machine<Type>;
				//lp = loo;
				//cout << "\nuirhfyref\n";
				temp->Fht.insert(i, Succ(h), h , Get_ptr(Succ(h)));
			}
			temp = temp->next;
		}
	}



	void display()
	{
		Machine<Type>* temp = head;

		do{
			//temp->tree.display(temp->tree.root);
			cout << "\n--------------------------\n";
			cout << "\n\nsimple id " << temp->id << endl;
			cout<< "hashed id " << temp->hashed_id << endl;
			cout << temp << endl;
			temp->Tree.display(temp->Tree.root);
			temp->Fht.display();


			//cout << endl << endl;
			temp = temp->next;
		} while (temp->next != head);
		cout << "\n--------------------------\n";
		cout << "\n\nsimple id " << temp->id << endl;
		cout << "hashed id " << temp->hashed_id << endl;
		cout << temp << endl;
		temp->Tree.display(temp->Tree.root);
		temp->Fht.display();
		cout << endl << endl;
		//temp->tree.display(temp->tree.root);

	}

	Machine<Type>* Get_ptr(string str) {

		Machine<string>* temp = head;
		while (temp) {
			if (temp->id == str) return temp;
			temp = temp->next;
		}

		//return ;	
	}


};