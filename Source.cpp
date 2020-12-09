//#include "Header.h"
#include "Header1.h"

int main()
{
	BSTree<int> obj;

	obj.Insert(5, obj.getRoot());	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(3, obj.getRoot());	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(4, obj.getRoot());	obj.R_H();	cout << "\n-------------------------------------\n";
	//obj.Insert(2, obj.getRoot());	obj.R_H();	cout << "\n-------------------------------------\n";
	//obj.Insert(1, obj.getRoot());	obj.R_H();	cout << "\n-------------------------------------\n";

	


	obj.display(obj.root);

	return 0;

}