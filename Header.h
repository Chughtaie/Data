#include "Header1.h"
//#include <iostream>
//using namespace std;


template<typename Type,typename Type1>
struct Node {
	Type1 mech;	//actual machine
	Type1 data;	//succ of machine
	Type1 val;	//1 = i
	void* ptr;	//ptr of succ

	Node* next;
	Node* prev;

	Node() { next = prev = NULL; data = mech = val = 0; }
};


template<typename Type, typename Type1>
class Routing_Table { // doubly link list

public:

	Node<Type,Type1>* head;
	Type1 count;

	Routing_Table() { head = NULL; count = 0; }

	void insert(Type1 id, Type1 space, Type1 h, void* p = NULL)
	{

		//cout << "\nPROGRESS\n";
		if (!head)
		{
			head = new Node<Type,Type1>;
			head->val = id;
			head->data = space;
			head->mech = h;
			head->ptr = p;
		}
		else
		{
			Node<Type, Type1>* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			//temp->next = new Node;
			temp->next = new Node<Type, Type1>;
			temp->next->prev = temp;
			temp->next->data = space;
			temp->next->val = id;// (temp->val + 1);
			temp->next->mech = h;
			temp->next->ptr = p;
			//cout << "insertion 2 " << temp->next->node->data << endl;
			//temp->next->next = head; line++;

		}
		count++;
	}

	void display()
	{
		Node<Type,Type1>* temp = head;
		while (temp != NULL)
		{
			cout << "val data mech\t" << temp->val << "\t" << temp->data << "\t" << temp->mech << "\t" << temp->ptr << endl;
			temp = temp->next;
		}
		//temp->tree.display(temp->tree.root);
	}

	bool Delete(Node<Type, Type1>* n) {

		Node<Type, Type1>* temp = head;
		Node<Type, Type1>* temp1;

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

	bool Check(Type key) {
	
		Node<Type, Type1>* temp = head;

		while (temp)
		{

			temp = temp->next;
		}
	}


};

template<typename Type, typename Type1>
class Machinee {

public:
	Type1 id;
	Type1 hashed_id;
	Routing_Table<Type, Type1> Fht;
	AvlTree<Type, Type1> Tree;

	Machinee* next;

	Type1 line ;
	Type1 file_no ;

	Machinee() { next = NULL; file_no = 0; line = 0; }

	Type File(Type key)
	{
		Type name = "";

		if (line == 100 || line == 0) {
			file_no++;
			line = 1;
			name = "Treefile_Machine_" + to_string(id) + "_(" + to_string(file_no) + ").txt";
			ofstream file(name);
			file << key << endl;
			file.close();
		}
		else {

			ofstream file;
			name = "Treefile_Machine_" + to_string(id) + "_(" + to_string(file_no) + ").txt";
			file.open(name, std::ios::app);
			file << key << endl;
			file.close();
			line++;
		}
		return name;
	}

	bool Add(AvlNode<Type, Type1>* var) {
		Type s = File(var->data + "\t\t" + to_string(var->key));
		var->path = s;
		var->line_no = line;
		Tree.Insert(var, &(Tree.root));
		return true;
	}

};


template<typename Type, typename Type1>
class Ring_DHT {


public:

	//================ RING ====================

	Machinee<Type, Type1>* head;

	Type1 machines = 0;
	Type1 id_space;
	Type1 max;



	Ring_DHT(Type1 Lo = 0, Type1 ma = 0) { head = NULL; id_space = Lo; max = ma; }
	

	bool Add(AvlNode<Type, Type1>* var) {	//Add data in a machine
	
		if (head->id == var->mach)
		{
			head->Add(var);
			return true;
		}

		else {
		
			Machinee<Type, Type1>* temp = head;

			while (temp->id < var->mach && temp->next != head) 			
				temp = temp->next;
			if (temp->id >= var->mach)
				temp->Add(var);
			else head->Add(var);
			
			return 1;		
		}
	}
	
	
	void Add_Machine(Type1 idd, Type1 hid) {

		Machinee<Type, Type1>* temp = new Machinee < Type, Type1 >;

		temp->id = idd;	temp->hashed_id = hid;
		//Machinee<Type, Type1>* temp = insert(idd, hid);

		Machinee<Type, Type1>* temp1 = head;

		while (temp1->id < idd)
		{						//9
			temp1 = temp1->next;
			if (temp1 == head)
			break;
		}

		AvlNode<Type, Type1>* node = temp1->Tree.root;
		temp1->Tree.root = NULL;
		temp1->file_no = NULL;
		temp1->line = NULL;
		
		if (temp1 != head)
		{
			temp1 = head;

			while (temp1->next->id < idd)
			{
				temp1 = temp1->next;	//5
				if (temp1->next == head)
					break;
			}

			temp->next = temp1->next;
			temp1->next = temp;


			machines++;

			temp1 = head;

			for (int i = 0; i < machines; i++)
			{
				temp1->Fht.head = NULL;
				temp1 = temp1->next;
			}
		}
		else {
			while (temp1->next != head)
				temp1 = temp1->next;

			temp->next = head;
			temp1->next = temp;
			head = temp;
			machines++;
			temp1 = head;

			for (int i = 0; i < machines; i++)
			{
				temp1->Fht.head = NULL;
				temp1 = temp1->next;
			}
		}
		go(node);
		
	}


	void go(AvlNode<Type, Type1>* temp, Type1 val = 0)  //traverse
	{
		if (temp == NULL )
			return;

		if (val <= 0) Add(temp);	//Preorder

		if (temp->left != NULL)
			go(temp->left, val);    //LVR display

		if (val == 1) Add(temp);	//Inorder

		if (temp->right != NULL)
			go(temp->right, val);

		if (val > 1)  Add(temp);	//PostOrder


	}

	void delete_machine(Type1 idd)
	{
		Machinee<Type, Type1>* temp1 = head;
		bool check = 1;
		Machinee<Type, Type1>* temp;
		while (1)
		{
			if (temp1->id == idd)			//7
				break;

			temp1 = temp1->next;

			if(temp1==head)
			{
				cout << "this id doesn't exit\n"; check = 0; break;
			}
		}

		if (check)
		{
			AvlNode<Type, Type1>* node = temp1->Tree.root;
			temp1->Tree.root = NULL;
			temp1->file_no = NULL;
			temp1->line = NULL;
			
			if (temp1 != head)
			{
				temp = head;

				while (1)
				{
					if (temp->next->id == idd)			//5
						break;
					temp = temp->next;
				}

				temp->next = temp1->next; temp1 = NULL;

				machines--;

				temp1 = head;

				for (int i = 0; i < machines; i++)
				{
					temp1->Fht.head = NULL;
					temp1 = temp1->next;
				}
			}
			else
			{
				temp = head;

				while (1)
				{
					if (temp->next->id == idd)			//5
						break;
					temp = temp->next;
				}
				temp->next = head->next;
				head = temp->next;
				temp1 = head;
				machines--;
				for (int i = 0; i < machines; i++)
				{
					temp1->Fht.head = NULL;
					temp1 = temp1->next;
				}
			}
			go(node);

		}

	}

	Machinee<Type, Type1>* insert(Type1 idd, Type1 hid)	//Insert a Machine Node
	{
		if (!head)
		{
			head = new Machinee<Type, Type1>;
			head->id = idd;
			head->hashed_id = hid;
			head->next = head; //line++;
			machines++;
			return NULL;
		}
		else if (head->id > idd)	//enter 0 after 1,2
		{
			Machinee<Type, Type1>* temp = head;
			while (temp->next != head)
				temp = temp->next;
			
			temp->next = new Machinee<Type, Type1>;
			//temp = temp->next;
			temp->next->id = idd;
			temp->next->hashed_id = hid;
			temp->next->next = head;
		
			if (head->next == head)	//enter 0 after 1
				head->next = temp->next;
			
			head = temp->next;
			cout << "\n222\n";
			machines++;
			return temp;
		}
		else
		{
			Machinee<Type, Type1>* temp = head;
			while (temp->next != head)
			{
				if (temp->id == idd || temp->next->id == idd) 
				{
					cout << "\nCannot Enter Machine. Its already Present!"; return NULL;
				}
				if (temp->next->id > idd)
					break;
				else temp = temp->next;				
			}
			Machinee<Type, Type1>* tempo = temp->next;
			temp->next = new Machinee<Type, Type1>;
			temp->next->id = idd;
			temp->next->hashed_id = hid;
			temp->next->next = tempo; //line++;
			machines++;
			return temp;
		}
	}


	Type1 Succ(Type1 log) {
	
		if (head->id == log)
			return head->id;
		else{

			Machinee<Type, Type1>* temp = head;

			while (temp->id < log && temp->next != head)
				temp = temp->next;
			if (temp->id >= log)
				return temp->id;
			else 
				return head->id;
		}
	}

	void Ret(Machinee<Type, Type1>* temp, Type1 key) {	//Find and Show Data
		
		if (!temp) return;
		cout << "\nMachine NO. " << temp->id << endl;
		AvlNode<Type, Type1>* lo = temp->Tree.retrieve(key);
		if (!lo) { cout << "\nNULL\n"; return; }
		cout << "\n\n=======================Data==============================";
		cout << "\ndata\t"	<< lo->data		<< '\n';	// left root right
		cout << "path\t"	<< lo->path		<< '\n';	// left root right
		cout << "Line no\t" << lo->line_no	<< '\n';	// left root right
		cout << "mach\t"	<< lo->mach		<< '\n';	// left root right
		cout << "key\t"		<< lo->key		<< '\n';	// left root right

		cout << "By File\n";

		ifstream input;
		Type data;
		input.open(lo->path);
		for (int i = 1; (!input.eof()); i++)
		{
			getline(input,data);
			if (i == lo->line_no) { cout << "\n data = " << data; break; }
		}
		input.close();
	
	}

	void Search(Type1 key, Type1 mac = 0) {

		Type1 log = (key) % max;
		log = Succ(log);
		Machinee<Type, Type1>* temp = head;
		Node<Type, Type1>* tempo = temp->Fht.head;
		

		while (1) {

			 tempo = temp->Fht.head;
			 cout << "\n\nMachine no =  " << temp->id;
			 int i = 0;
			if (log == temp->id) { cout << "\n=====1=======\n"; Ret(temp, key);  return; }

			else if (temp->id < log && log <= tempo->data) {	//p<e and e<=Ftp[1]
				temp = static_cast<Machinee<Type, Type1>*>(tempo->ptr); cout << "\n=====2=======\n"; Ret(temp,key); return;
			}			
			else
			while (tempo) {
				if (tempo->next != NULL)
				if (tempo->data < log && log <= tempo->next->data )	//Ftp[j] < e < Ftp[j+1]
				{
					cout << "\n=====3=======\n";
					temp = static_cast<Machinee<Type, Type1>*>(tempo->ptr);
					break;
				}
				if (tempo->next == NULL)
				{
					cout << "\n=====4=======\n";
					temp = static_cast<Machinee<Type, Type1>*>(tempo->ptr);
					break;
				}
				cout << "\ntempo\t" << i << "\n" ;
				//tempo.
				i++;
				tempo = tempo->next;
			}	


		}
		
		
	}
		

	void Set(Type1* arr, Type1 id) {

		Machinee<Type, Type1>* temp = head;

		for (int p = 0; p < machines; p++) {		//for every machine

			for (int i = 1; i <= id; i++) {	//
				Type1 h = (Type1(temp->id + pow(2, i - 1))) % Type1(pow(2, id));
				temp->Fht.insert(i, Succ(h), h , Get_ptr(Succ(h)));
			}
			temp = temp->next;
		}
	}



	void display()
	{
		Machinee<Type, Type1>* temp = head;
		if (!head) return;
		do{
			//temp->tree.display(temp->tree.root);
			cout << "\n----------------------------------------------------------\n";
			cout << "\nSimple id " << temp->id << "\tHashed id " << temp->hashed_id << endl;
			cout << temp << endl;
			temp->Tree.display(temp->Tree.root,temp->id);
			temp->Fht.display();

			temp = temp->next;
		}while (temp->next != head);

		cout << "\n----------------------------------------------------------\n";
		cout << "\nSimple id " << temp->id << "\tHashed id " << temp->hashed_id << endl;
		cout << temp << endl;
		temp->Tree.display(temp->Tree.root, temp->id);
		temp->Fht.display();
		cout << endl << endl;
		//temp->tree.display(temp->tree.root);

	}

	Machinee<Type, Type1>* Get_ptr(Type1 str) {

		Machinee<Type, Type1>* temp = head;
		bool b = 1;
		while (temp!=head || b) {
			b = 0;
			if (temp->id == str) return temp;
			temp = temp->next;
		}
	//return ;	
	}


};