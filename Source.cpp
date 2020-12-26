#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
#include "../Data/Header.h"




string  word(string str, int o, int p = -1) {

	if (p == -1 || p == o || p > 8 || p < o) p = o + 1;
	string c = str;
	string val;

	int i = 0;
	for (int j = 0; j < p; i++)
	{

		val += c[i];
		if (c[i + 1] == ' ')
		{
			if (j < o) {
				val = "\0";
				i++;
			}
			j++;
		}
		if (c[i + 1] == '\0') return val;

		//cout << "\nspace" << i << j;
	}

	//cout << "\nNspace" << i << j;
	return val;
}


int Total(string a) {
	int o = 0;
	//cout << "\na" << a << "\n";
	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] == ' ' && a[i + 1] != ' ') o++;
	return o + 1;
}



struct S {
	std::string first_name;
	std::string last_name;
};
bool operator==(const S& lhs, const S& rhs) {
	return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}

// custom hash can be a standalone function object:
struct MyHash
{
	std::size_t operator()(S const& s) const noexcept
	{
		std::size_t h1 = std::hash<std::string>{}(s.first_name);
		std::size_t h2 = std::hash<std::string>{}(s.last_name);
		return h1 ^ (h2 << 1); // or use boost::hash_combine (see Discussion)
	}
};

// custom specialization of std::hash can be injected in namespace std
namespace std
{
	template<> struct hash<S>
	{
		std::size_t operator()(S const& s) const noexcept
		{
			std::size_t h1 = std::hash<std::string>{}(s.first_name);
			std::size_t h2 = std::hash<std::string>{}(s.last_name);
			return h1 ^ (h2 << 1); // or use boost::hash_combine
		}
	};
}


int Hash(string str) {

	std::string strin = "";

	int  tot = Total(str);
	//cout << "\nTotal" << tot << "\n";
	for (int i = 0; i < tot; i++) {
		//cout << word(str,i) << "\t";
		strin += word(str, i);
	}
	//std::cout << "\nString" << strin << "\n";
	std::size_t str_hash = std::hash<std::string>{}(strin);
	strin = to_string(str_hash);
	strin[9] = '\0';
	//str = str_hash;
	std::cout << "hash(" << std::quoted(strin) << ") = " << str_hash << '\n';
	//long int val = str_hash % p;
	//cout << endl << strin << endl;
	return stoi(strin);
}


string Machine(string val, string max) {
	//cout << "\n\nbfhfbheb \t"
	//val[9] = '\0';
	return to_string(stoi(val) % stoi(max));
}



template<class T, class U>
void datastorage(Ring_DHT<T, U>& obj,int p) {
	string s = " ";
	cout << "\nEnter The shit you want to store!!\n";
	std::getline(cin, s);
	AvlNode<string, int>* var = new AvlNode<string, int>;
	var->data = s;
	var->key = Hash(s);
	var->mach = (var->key % p);
	//cout << var->mach << "\t" << var->key << "\t" << n << endl;;
	obj.Add(var);
}

template<class T, class U>
void searchingg(Ring_DHT<T, U>& obj) {
	string s = " ";
	cout << "\nEnter The search!!\n";
	std::getline(cin, s);
	if (s != "-1")
		obj.Search(Hash(s));

}


template<class T, class U>
void flyingmachine(Ring_DHT<T, U>& obj, int p,int *arr,int idspace) {
	string s = "";	int tempo;

	cout << "Enter the machine id : ";
	std::getline(cin, s);
	obj.Add_Machine(stoi(s), Hash(s));
	int* arr1 = new int[p + 1];

	for (int i = 0; i < p; i++)
		arr1[i] = arr[i];

	arr1[p] = stoi(s);

	for (int i = 0; i < p; i++)
	{

		for (int j = i + 1; j < p; j++)
		{
			if (arr1[i] > arr1[j])
			{
				tempo = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = tempo;
			}
		}
	}

	obj.Set(arr1, idspace);

}


template<class T, class U>
void machineremoval(Ring_DHT<T, U>& obj, int p, int* arr, int idspace) {
	string s = ""; int tempo;
	cout << "\nEnter simple id of machine to be deleted\n";
	std::getline(cin, s);

	obj.delete_machine(stoi(s));
	int* arr1 = new int[p - 1];
	int k = 0;
	for (int i = 0; i < p - 1; i++)
	{
		if (arr[i] != stoi(s))
		{
			arr1[k] = arr[i]; k++;
		}
	}

	for (int i = 0; i < p; i++)
	{

		for (int j = i + 1; j < p; j++)
		{
			if (arr1[i] > arr1[j])
			{
				tempo = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = tempo;
			}
		}
	}

	obj.Set(arr1, idspace);

}








template <class T, class U>
void menu(Ring_DHT<T, U>& obj, int p,int *arr,int idspace) {
	string inp = "";

	/*cout << "Press 1 to enter the number of machines" << endl;
	cout << "Press 2 to enter the identifier space" << endl;
	cout << "Press 3 to manually assign the machine ids" << endl;
	cout << "Press 4 to automatically assign the machine ids" << endl;*/
	


	
	while (inp != "-1") {
		cout << endl << endl<<"\t\tMENU\n";
		cout << "Press 5 to insert data in the form of key, value pairs from any machine" << endl;
		cout << "Press 6 to remove data by specifying the key from any machine" << endl;
		cout << "Press 7 to print the AVL tree maintain on any machine along with the location of files\n";
		cout << "Press 8 to print the routing table of any machine\n";
		cout << "Press 9 to add new machine\n";
		cout << "Press 10 to remove a machine\n";
		cout << "Press 11 to search any id\n";
		cout << "Press -1 to EXIT\n";
		std::getline(cin, inp);
		if (inp == "5")//insert data
		{

			datastorage(obj, p);
			obj.display();
		}
		if (inp == "6") //remove data
		{


		}

		if (inp == "7") //print AVL Tree
		{
			//string s = "";
			//cout << "Enter the machine id for which AVL Tree you want to be printed : ";
			//getline(cin, s);
			//printAVL();
		}

		if (inp == "8")//print routing table of any machine
		{
			//printroutingtabble();

		}

		if (inp == "9") //add new machine on fly
		{
			flyingmachine(obj, p, arr, idspace);

		}

		if (inp == "10") //remove any machine
		{
			machineremoval(obj, p, arr, idspace);

		}

		if (inp == "11") // searching
		{
			searchingg(obj);
		}
	}


}




int main()
{
	srand(time(0));

	int aut = 0; string auts;
	int n = 0, idspace = 0;
	string no = "2";

//START UP MESSAGE
	cout << "\t\tWELCOME TO THE DISTRIBUTED NETWORK\n" << endl;
	cout << "Enter number of Machines initially : ";
	getline(cin, no);
	n = stoi(no);
	no = "2";

	cout << "Enter identifier space : ";
	getline(cin, no);
	cout << "\n\n";
	idspace = stoi(no);

	cout << "If you want to assign machine IDs manually, PRESS 1 and enter, else press any key to continue\n";
	getline(cin, auts);
	aut = stoi(auts);

	int p = pow(2, idspace);
	//cout << "\nPower = " << p << endl;
	int* arr = new int[p];

	bool check = 1;
	int temp = 0, j = 0;

	if (aut != 1) {
		for (int i = 0; i < n;)
		{

			temp = 0 + rand() % (p - 1);
			check = 1; j = 0;

			while (j < i)
			{
				if (temp == arr[j])
					check = 0;
				j++;
			}

			if (check)
			{
				arr[i] = temp; i++;
			}

		}
	}
	else {
		for (int i = 0; i < n;)
		{

			cout << "\nEnter machine ID to store : ";
			getline(cin, auts);
			temp = stoi(auts);
			if (temp >= p) {
				cout << "The size is bigger...";
				temp = temp % (p - 1);
			}
			check = 1; j = 0;

			while (j < i)
			{
				if (temp == arr[j])
					check = 0;
				j++;
			}

			if (check)
			{
				arr[i] = temp; i++;
			}

		}

	}





	int tempo;

	for (int i = 0; i < n; i++)
	{

		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				tempo = arr[i];
				arr[i] = arr[j];
				arr[j] = tempo;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;


	Ring_DHT<string, int> system_mach(idspace, p);

	int t = 0;

	for (int i = 0; i < n; i++)
	{
		t = Hash(to_string(arr[i]));

		system_mach.insert(arr[i], t);
	}
	system_mach.Set(arr, idspace);


	menu(system_mach, p,arr,idspace);



	string s = " ";
//	string s = " ";
	//while (1) {
		//cout << "\nEnter The shit you want to store!!\n";
		//std::getline(cin, s);
		//if (s == "-1") break;
		/*AvlNode<string, int>* var = new AvlNode<string, int>;
		var->data = s;
		var->key = Hash(s);
		var->mach = (var->key%p);
		system_mach.Add(var);
		*/
	//}
	//system_mach.display();


	/*cout << "\nEnter The search!!\n";
	std::getline(cin, s);
	if (s != "-1")
		system_mach.Search(Hash(s));*/

	/*cout << "\nEnter 1 to ENter a machINe!!\n";
	std::getline(cin, s);
	if (s != "-1")
	{
		std::getline(cin, s);
		system_mach.Add_Machine(stoi(s), Hash(s));
		int* arr1 = new int[p + 1];

		for (int i = 0; i < p; i++)
			arr1[i] = arr[i];

		arr1[p] = stoi(s);

		for (int i = 0; i < p; i++)
		{

			for (int j = i + 1; j < p; j++)
			{
				if (arr1[i] > arr1[j])
				{
					tempo = arr1[i];
					arr1[i] = arr1[j];
					arr1[j] = tempo;
				}
			}
		}

		system_mach.Set(arr1, idspace);
	}
	system_mach.display();*/


	/*cout << "\nEnter 1 to delete a machINe!!\n";
	std::getline(cin, s);
	if (s == "1")
	{
		cout<< "\nEnter simple id of machine to be deleted\n";
		std::getline(cin, s);

		system_mach.delete_machine(stoi(s));
		int* arr1 = new int[p - 1];
		int k = 0;
		for (int i = 0; i < p - 1; i++)
		{
			if (arr[i] != stoi(s))
			{
				arr1[k] = arr[i]; k++;
			}
		}
		
		for (int i = 0; i < p; i++)
		{

			for (int j = i + 1; j < p; j++)
			{
				if (arr1[i] > arr1[j])
				{
					tempo = arr1[i];
					arr1[i] = arr1[j];
					arr1[j] = tempo;
				}
			}
		}

		system_mach.Set(arr1, idspace);
	}
	system_mach.display();*/




	//=========		Inputs of Strings	 ==============



	return 0;


}