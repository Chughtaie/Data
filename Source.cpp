//#include "Header.h"
#include "Header1.h"

int main()
{
	BSTree<int> obj;

	obj.Insert(5, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(3, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(4, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(2, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(1, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(6, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";
	obj.Insert(7, &obj.root);	obj.R_H();	cout << "\n-------------------------------------\n";

	


	obj.display(obj.root);

	return 0;

}