
/*#include "Header.h"
#include <math.h>
// #include "../Hash/header2.h"
//#include "Header1.h"


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
	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] == ' ' && a[i-1]  != ' ') o++;
	return o + 1;
}



char Generate(char ch,int yo,int num=0) {

	int a = ch;
	a += (num+yo);
	//cout << "\nchar = " << ch << "   " << a << endl;;
	a %= 36;
	a += yo;
	a %= 36;
	if (a <= 25)
		ch = 65 + a;
	else ch = 22 + a;
	return ch;

}


string MY(string lol,int s) {


	/*
	string hash = "0";
	int size = 0;
	int mid = Total(lol) / 2;
	hash = word(lol,mid-1,mid+1);
	for (int i = 0; hash[i] != '\0'; i++)	
		size++;
	//	yo += hash[i];
	*/

	/*
	int siz = 0,talib =0,yo=0;
	for (int i = 0; lol[i] != '\0'; i++)
	{
		siz++; yo += lol[i];
	}
	
	//int div = (size / 2);
	//cout << size;
	//cout << hash[div] << endl;
	//char a = 's';
	//a += hash[div];
	//div = hash[div];
	//char ch = hash[div];
	//cout << "div = " << div << endl;
	
	//cout << yo << "  " << endl;
	talib = yo*2 ;
	talib = talib % s; 
	if (talib == 0) talib = s/2;
	//cout << talib << endl;
	//cout << yo << "  " << endl;
	int k = 0;
	string h = "";
	for (int i = 0,j=5; i < talib; i++)
	{
		if (k <= 2)
		{
			j += i * 3; k++;
		}
		else {
			j -= i * 3; k = 0;
		}
		
		h += Generate(lol[(j+yo) % siz],yo, j * yo);

	}
	
	return h;
}

int main()
{
	//HashString();
	AvlTree<int> obj;

	/*;
	obj.Insert(5, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(3, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(4, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(2, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(1, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(6, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(7, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	*/
	/*
	for (int i = 1; i <= 7; i++)
	{
		AvlNode<int>* ch;
		ch = new AvlNode<int>;
		ch->data = i;

		obj.Insert(ch, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n"; obj.display(obj.root);
	}
	for (int i = 16; i >= 8; i--)
	{
		if (i == 9) i--;
		AvlNode<int>* ch;
		ch = new AvlNode<int>;
		ch->data = i;

		obj.Insert(ch, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n"; obj.display(obj.root);
	}

	{

		AvlNode<int>* ch;
		ch = new AvlNode<int>;
		ch->data = 8;

		obj.Insert(ch, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n"; obj.display(obj.root);
	}

	cout << "\n#######################################################################\n";

	obj.del(&obj.root, 11);



	cout << "\n\n\n";
	obj.display(obj.root);

	*/
	
	/*														//Cheching Table Doubly List
	Table check;
	for (int i = 0; i < 10; i++) {

		
		string ab = to_string(4*i);
		Node* d = new Node;
		d->data = ab;
		check.insert(d);
	}
	Node* d = new Node;
	d->data = "24";
	check.Delete(d);
	check.display();
	*/



	//int a = 2147483647;
	
	
	/*
	
	string a = "0";							//checking Hash local
	int o = 0;
	while (a != "-1") {
		if(a!="0")
		cout << MY(a, 48);
		cout << "\n\nEnter your shit....-1 to exit\n\ninput = ";
		getline(cin,a);	
		cout << "\nHash = ";
	}
	

	//cout << a << endl;
	return 0;

}






/*bool Arr[50] = {0};
Arr[50] = true;
while (s)
{
	if (s % 2 == 1) {

		for (int i = 0; i < 49; i++)
			Arr[i] = Arr[i + 1];
		Arr[49] = 0;

	}
}
for (int i = 0; i < 49; i++)


//hash = hash*lol;
int size = 2147483647;
int a = sizeof(lol);
if (a <=po)

int b = a / size;
for (int i = 0,j=0; i < size ; i++)
	hash += lol[j % size];
	*/


/*
#include <iostream>
#include<math.h>
#include <string>
#include <ctime>
#include "../Data/Header.h"
using namespace std;



char Generate(char ch, int yo, int num = 0) {

	int a = ch;
	a += (num + yo);
	//cout << "\nchar = " << ch << "   " << a << endl;;
	a %= 36;
	a += yo;
	a %= 36;
	if (a <= 25)
		ch = 65 + a;
	else ch = 22 + a;
	return ch;

}


string MY(string lol, int s) {


	
	//string hash = "0";
	//int size = 0;
	//int mid = Total(lol) / 2;
	//hash = word(lol,mid-1,mid+1);
	//for (int i = 0; hash[i] != '\0'; i++)
	//	size++;
	//	yo += hash[i];
	

	
	int siz = 0,talib =0,yo=0;
	for (int i = 0; lol[i] != '\0'; i++)
	{
		siz++; yo += lol[i];
	}

	//int div = (size / 2);
	//cout << size;
	//cout << hash[div] << endl;
	//char a = 's';
	//a += hash[div];
	//div = hash[div];
	//char ch = hash[div];
	//cout << "div = " << div << endl;

	//cout << yo << "  " << endl;
	talib = yo*2 ;
	talib = talib % s;
	if (talib == 0) talib = s/2;
	//cout << talib << endl;
	//cout << yo << "  " << endl;
	int k = 0;
	string h = "";
	for (int i = 0,j=5; i < talib; i++)
	{
		if (k <= 2)
		{
			j += i * 3; k++;
		}
		else {
			j -= i * 3; k = 0;
		}

		h += Generate(lol[(j+yo) % siz],yo, j * yo);

	}

	return h;
}




int main()
{
	int n = 0, idspace;
	cout << "enter number of machines\n";
	cin >> n;
	cout << "enter identifier space\n";
	cin >> idspace;

	int p = pow(2, idspace);
	cout << "\nPower = " << p << endl;
	int* arr = new int[n];

	bool check = 1;
	int temp = 0, j = 0;

	for (int i = 0; i < n;)
	{
		temp = 1 + rand() % p;
		check = 1; j = 0;

		while (j < i)
		{
			if ((temp == arr[j]) || (temp == arr[j] + 1) || (temp == arr[j] - 1))
				check = 0;
			j++;
		}

		if (check)
		{
			arr[i] = temp; i++;
		}

	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;


	string a = "0";							//checking Hash local
	int o = 0;
	while (a != "-1") {
		if (a != "0")
			cout << MY(a, 48);
		cout << "\n\nEnter your shit....-1 to exit\n\ninput = ";
		//getline(cin, a);
		cin >> a;
		cout << "\nHash = ";
	}




	return 0;
}*/



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

int main()
{



	int n = 0, idspace=0;
	string no;
	cout << "enter number of machines\n";
	getline(cin,no);
	n = stoi(no);
	cout << "enter identifier space\n";
	getline(cin, no);
	idspace = stoi(no);


	int p = pow(2, idspace);
	cout << "\nPower = " << p << endl;
	int* arr = new int[n];

	bool check = 1;
	int temp = 0, j = 0;

	for (int i = 0; i < n;)
	{
		temp = 1 + rand() % p;
		check = 1; j = 0;

		while (j < i)
		{
			if ((temp == arr[j]) || (temp == arr[j] + 1) || (temp == arr[j] - 1))
				check = 0;
			j++;
		}

		if (check)
		{
			arr[i] = temp; i++;
		}

	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;




	//=========		Inputs of Strings	 ==============



	
	std::string str = "0";
	do {
		std::string strin = "";
		std::cout << "\n\nEnter your shit....-1 to exit\n\ninput = ";
		//getline(cin, a);
		std::getline(cin,str);
		int  tot = Total(str);
		//cout << "\nTotal" << tot << "\n";
		for (int i = 0; i < tot; i++) {
			//cout << word(str,i) << "\t";
			strin += word(str, i);			  
		}	  
		std::cout << "\nString" << strin << "\n";
		std::size_t str_hash = std::hash<std::string>{}(strin);
		//str = str_hash;
		std::cout << "hash(" << std::quoted(strin) << ") = " << str_hash << '\n';
		long int val = str_hash % p;
		cout  << val << endl;
			  
	}while (str != "-1");
	
	
	
	
			
	
	//S obj = { "Hubert", "Farnsworth" };
	//// using the standalone function object
	//std::cout << "hash(" << std::quoted(obj.first_name) << ", "
	//	<< std::quoted(obj.last_name) << ") = "
	//	<< MyHash{}(obj) << " (using MyHash)\n" << std::setw(31) << "or "
	//	<< std::hash<S>{}(obj) << " (using injected std::hash<S> specialization)\n";

	// custom hash makes it possible to use custom types in unordered containers
	// The example will use the injected std::hash<S> specialization above,
	// to use MyHash instead, pass it as a second template argument
	
	//std::unordered_set<S> names = { obj, {"Bender", "Rodriguez"}, {"Turanga", "Leela"} };
	//for (auto& s : names)
		//std::cout << std::quoted(s.first_name) << ' ' << std::quoted(s.last_name) << '\n';
}