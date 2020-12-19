#include<iostream>
#include<cstring>
#include<string>
#include <fstream>
using namespace std;

template<typename T>
class AvlNode {

public:

	T data;		//Foxxy
	T path;		//file1
	T line_no;	//line no
	T key;		//foxxy ki hash
	T mach;		//machine no.


	AvlNode* left;
	AvlNode* right;
	AvlNode() { left = right = NULL; data = "0"; path = line_no = key = ""; }

};

template<typename T>
class AvlTree {




public:

	AvlNode<T>* root;
	int height;
	int lh = 0, rh = 0;
	int h = 0, a = 0;

	AvlTree() {

		root = NULL;
		height = 0;

	}

	AvlNode<T>* getRoot()
	{
		return root;
	}
	int R_H() {
		h = 0, a = 0;
		Height(root);
		//cout << "\nRoot\t" << root->data << "\t Root Height = " << h << endl;
		return 1;
	}

	int balanceFactor(AvlNode<T>* r) {

		if (!root)
			return -1;
		h = 0, a = 0;
		Height(r->left); lh = h;
		h = 0, a = 0;
		Height(r->right); rh = h;

		if (r->left) lh++;
		if (r->right) rh++;
		//cout << "\nData = " << r->data << "\tlh\t" << lh << "\trh\t" << rh << endl;
		return (lh - rh);
	}

	void Height(AvlNode<T>* temp)
	{
		if (root == NULL || temp == NULL)
			return;

		//cout << "1";
		if (temp->left != NULL)
		{
			//cout << "a";
			a++;
			Height(temp->left);
		}

		//cout << "2";
		if (temp->right)
		{
			//cout << "b";
			a++;
			Height(temp->right);
		}

		if (h < a) {
			h = a;
		}
		a--;
		return;
	}

	void RR(AvlNode<T>** temp) {
		//cout << "\tRR\n";
		AvlNode<T>* ch;					// 4-3-5
		ch = (*temp)->left;
		(*temp)->left = ch->right;
		ch->right = (*temp);
		(*temp) = ch;

	}

	void LL(AvlNode<T>** temp) {
		//cout << "\tLL\n";
		AvlNode<T>* ch;
		ch = (*temp)->right;
		(*temp)->right = ch->left;
		ch->left = (*temp);
		(*temp) = ch;


	}

	void Left(AvlNode<T>** temp) {
		//cout << "\nLeft";
		LL(&((*temp)->left));
		RR(temp);

	}

	void Right(AvlNode<T>** temp) {

		//cout << "\nRight";
		RR(&((*temp)->right));
		LL(temp);


	}


	void Insert(AvlNode<T>* number, AvlNode<T>** temp)
	{
		//cout << "\nEntered\n";
		if (root == NULL)
		{
			(root) = new AvlNode<T>;
			root = number;
			*temp = root;
			return;
		}

		else if ((*temp)->key == number->key)
		{
			cout << " \n Given number is already present in tree.\n";
			return;
		}

		else if ((*temp)->key > number->key)
		{
			if ((*temp)->left != NULL)
			{
				Insert(number, &((*temp)->left));


				if (balanceFactor(*temp) == 2) { //5-3-4
					if (number->key < (*temp)->left->key) // 5-4-3
						RR(temp);
					else
						Left(temp);
				}

				return;
			}
			else
			{
				//cout << "\nEnter Left\t" << number->key << endl;
				//(*temp)->left = new Node<T>;
				(*temp)->left = number;
				return;
			}
		}

		else if ((*temp)->key < number->key)
		{
			if ((*temp)->right != NULL)
			{
				Insert(number, &((*temp)->right));

				if (balanceFactor(*temp) == -2) { //5-3-4
					if (number->key > (*temp)->right->key) // 5-4-3
						LL(temp);
					else
						Right(temp);

				}
				return;
			}
			else
			{
				//cout << "\nEnter Right\t" << number->key << endl;
				//(*temp)->right = new Node<T>;
				(*temp)->right = number;
				return;
			}
		}
	}

	void display(AvlNode<T>* temp)  //traverse
	{
		if (temp == NULL || root == NULL)
		{
			return;
		}

		cout << "\ndata\t" <<  temp->data << '\n';	// left root right
		cout << "path\t" << temp->path << '\n';	// left root right
		cout << "Line no\t" << temp->line_no << '\n';	// left root right
		cout << "mach\t" << temp->mach << '\n';	// left root right
		cout << "key\t" << temp->key << '\n';	// left root right
		//cout << temp << endl;
		if (temp->left != NULL)
		{
			display(temp->left);    //LVR display

		}

		// cout << "\nSdfd\n";

		if (temp->right != NULL)
		{
			display(temp->right);
		}

	}

	AvlNode<T>* retrieve(string d)
	{
		AvlNode<T>* temp = root;

		while (temp)
		{
			//cout << "str   " << stoi(temp->key) << "\t" << stoi(d) << endl;
			if (stoi(temp->key) == stoi(d))
				return temp;

			if (stoi(d) > stoi(temp->key))
				temp = temp->right;
			else
				temp = temp->left;
		}
		cout << "\nDoes Not Exist\n";
		return NULL;
	}

	int MAXHeight()
	{
		lh = rh = 0;
		if (root == NULL)
		{
			cout << "Empty tree\n";
			return 0;
		}

		AvlNode<T>* templ = root->left;
		AvlNode<T>* tempr = root->right;
		while (templ)
		{
			if (templ->left)
				templ = templ->left;
			else
				templ = templ->right;
			lh++;

		}
		while (tempr)
		{
			if (tempr->left)
				tempr = tempr->left;
			else
				tempr = tempr->right;
			rh++;

		}

		if (lh > rh)
			return lh;
		else
			return rh;


	}


	AvlNode<T>* minimum(AvlNode<T>* min)
	{
		

		while (min && min->left != NULL)
			min = min->left;

		return min;
	}

	void Bal(AvlNode<T>** temp,T number) {
	
		if (!(*temp)) return;

		if (balanceFactor(*temp) == 2) { //5-3-4
			if (number > (*temp)->left->data) // 5-4-3
				RR(temp);
			else
				Left(temp);
		}
		else
		if (balanceFactor(*temp) == -2) { //5-3-4
				if (number < (*temp)->right->data) // 5-4-3
					LL(temp);
				else
					Right(temp);

			}
	
	}

	AvlNode<T>* del(AvlNode<T>** temp, int n) {
		if (*temp == NULL )
			return *temp;
		if (n > (*temp)->data)
		{
			(*temp)->right = del(&((*temp)->right), n);	//
			Bal(&((*temp)->right),n);
		}
		else if ((*temp)->data > n)
		{
			(*temp)->left = del(&((*temp)->left), n);	//
			Bal(&((*temp)->left), n);
		}
		else {
			if ((*temp)->left == NULL && (*temp)->right == NULL) {
				delete *temp;
				*temp = NULL;
			}
			else if ((*temp)->left == NULL) {
				AvlNode<T>* temp1 = *temp;
				*temp = (*temp)->right;
				delete temp1;
			}
			else if ((*temp)->right == NULL) {
				AvlNode<T>* temp1 = *temp;
				*temp = (*temp)->left;
				delete temp1;

			}
			else { //case  3
				AvlNode<T>* temp1 = minimum((*temp)->right);
				(*temp)->data = temp1->data;
				//temp->right = 
				(*temp)->right = del(&((*temp)->right), temp1->data);

			}
		}

		return *temp;
	}
};





/*AvlNode<T>* del(AvlNode<T>* temp, int val)
{
	cout << "\ndel\n";
	if (root == NULL || temp==NULL)
	{
		return root;
	}
	else if (temp->data > val)
	{
		temp->left = del(temp->left, val);
	}
	else if (temp->data < val)
	{
		temp->right = del(temp->right, val);
	}
	else
	{
		if (temp->left == NULL && temp->right == NULL)
		{
			root = NULL;
		}
		else if (temp->left == NULL)
		{
			AvlNode<T>* det = temp;
			temp = temp->right;
			det = NULL;
			delete det;
		}
		else if (temp->right == NULL)
		{
			AvlNode<T>* det = temp;
			temp = temp->left;
			det = NULL;
			delete det;
		}
		else
		{
			AvlNode<T>* det = minimum(temp->right);
			temp->data = det->data;
			temp->right = del(temp->right, det->data);
		}
	}
	return temp;
}*/