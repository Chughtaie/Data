#include "Header.h"
#include <math.h>
//#include "../Hash/header2.h"
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
	
	
	
	
	
	string a = "0";							//checking Hash local
	int o = 0;
	while (a != "-1") {
		if(a!="0")
		cout << MY(a, 9);
		cout << "\n\nEnter your shit....-1 to exit\n\n";
		getline(cin,a);	
		cout << "\n\n";
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