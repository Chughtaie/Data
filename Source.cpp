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


string Hash(string str) {

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
	return strin;
}


string Machine(string val, string max) {
	//cout << "\n\nbfhfbheb \t"
	//val[9] = '\0';
	return to_string(stoi(val) % stoi(max));
}



int main()
{
	srand(time(0));

	int aut = 0; string auts;
	int n = 0, idspace = 0;
	string no = "2";
	cout << "enter number of machines\n";
	getline(cin, no);
	n = stoi(no);
	no = "2";
	cout << "enter identifier space\n";
	getline(cin, no);

	cout << "\n\n";
	idspace = stoi(no);
	cout << "If you want to assign machine IDs manually, PRESS 1 and enter, else press any key to continue\n";
	getline(cin, auts);
	aut = stoi(auts);

	int p = pow(2, idspace);
	//cout << "\nPower = " << p << endl;
	int* arr = new int[n];

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


	Ring_DHT<string> system_mach(idspace, p);

	string t = "";

	for (int i = 0; i < n; i++)
	{
		t = Hash(to_string(arr[i]));

		system_mach.insert(to_string(arr[i]), t);
	}
	system_mach.Set(arr, idspace);






	string s = "0";
	while (1) {
		cout << "\nEnter The shit you want to store!!\n";
		std::getline(cin, s);
		if (s == "-1") break;
		AvlNode<string>* var = new AvlNode<string>;
		var->data = s;
		var->key = Hash(s);
		var->mach = Machine(var->key, to_string(p));
		//cout << var->mach << "\t" << var->key << "\t" << n << endl;;
		system_mach.Add(var);
		//var.
	}
	system_mach.display();


	cout << "\nEnter The search!!\n";
	std::getline(cin, s);
	if (s != "-1")
	system_mach.Search(Hash(s));

	cout << "\nEnter 1 to ENter a machINe!!\n";
	std::getline(cin, s);
	if (s != "-1")
	{
		std::getline(cin, s);
		system_mach.Add_Machine(s, Hash(s));
	}
	system_mach.display();


	//=========		Inputs of Strings	 ==============



	return 0;


}