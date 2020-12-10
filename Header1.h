#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class AvlNode {

public:

	T data;

	AvlNode* left;
	AvlNode* right;
	AvlNode() { left = right = NULL; data = 0; }

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
		cout << "\nRoot\t" << root->data << "\t Root Height = " << h << endl;
		return 1;
	}
	/*
	int baanceFactor(AvlNode<T>* r)
	{

		lh = 0; rh = 0;
		AvlNode<>* templ = r->left;
		AvlNode* tempr = r->right;
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

		return lh - rh;

	}
	*/
	int balanceFactor(AvlNode<T>* r) {

		if (!root)
			return -1;
		h = 0, a = 0;
		Height(r->left); lh = h;
		h = 0, a = 0;
		Height(r->right); rh = h;

		if (r->left) lh++;
		if (r->right) rh++;
		cout << "\nData = " << r->data << "\tlh\t" << lh << "\trh\t" << rh << endl;
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
		cout << "\tRR\n";
		AvlNode<T>* ch;					// 4-3-5
		ch = (*temp)->left;
		(*temp)->left = ch->right;
		ch->right = (*temp);
		(*temp) = ch;

	}

	void LL(AvlNode<T>** temp) {
		cout << "\tLL\n";
		AvlNode<T>* ch;
		ch = (*temp)->right;
		(*temp)->right = ch->left;
		ch->left = (*temp);
		(*temp) = ch;


	}

	void Left(AvlNode<T>** temp) {
		cout << "\nLeft";
		LL(&((*temp)->left));
		RR(temp);

	}

	void Right(AvlNode<T>** temp) {

		cout << "\nRight";
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

		else if ((*temp)->data == number->data)
		{
			cout << " \n Given number is already present in tree.\n";
			return;
		}

		else if ((*temp)->data > number->data)
		{
			if ((*temp)->left != NULL)
			{
				Insert(number, &((*temp)->left));


				if (balanceFactor(*temp) == 2) { //5-3-4

					if (number->data < (*temp)->left->data) // 5-4-3
						RR(temp);
					else
						Left(temp);
				}

				return;
			}
			else
			{
				cout << "\nEnter\t" << number->data << endl;
				//(*temp)->left = new Node<T>;
				(*temp)->left = number;
				return;
			}
		}

		else if ((*temp)->data < number->data)
		{
			if ((*temp)->right != NULL)
			{
				Insert(number, &((*temp)->right));

				if (balanceFactor(*temp) == -2) { //5-3-4
					if (number->data > (*temp)->right->data) // 5-4-3
						LL(temp);
					else
						Right(temp);

				}
				return;
			}
			else
			{
				cout << "\nEnter\t" << number->data << endl;
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

		cout << temp->data << ',';	// left root right
		cout << temp << endl;
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

	bool retrieve(int d)
	{
		AvlNode<T>* temp = root;

		while (temp)
		{
			if (temp->data == d)
				return true;

			if (d > temp->data)
				temp = temp->right;
			else
				temp = temp->left;
		}

		return false;
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
	AvlNode<T>* del(AvlNode<T>* temp, int n) {
		if (temp == NULL )
			return temp;
		if (n > temp->data)
		{
			temp->right = del(temp->right, n); //return temp;
		}
		else if (temp->data > n)
		{
			temp->left = del(temp->left, n); //return temp;
		}
		else {
			if (temp->left == NULL && temp->right == NULL) {
				delete temp;
				temp = NULL;
			}
			else if (temp->left == NULL) {
				AvlNode<T>* temp1 = temp;
				temp = temp->right;
				delete temp1;
			}
			else if (temp->right == NULL) {
				AvlNode<T>* temp1 = temp;
				temp = temp->left;
				delete temp1;

			}
			else { //case  3
				AvlNode<T>* temp1 = minimum(temp->right);
				temp->data = temp1->data;
				//temp->right = 
				temp->right = del(temp->right, temp1->data);

			}
		}

		return temp;
	}
};
