#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class Node {

public:

	T data;

	Node* left;
	Node* right;
	Node() { left = right = NULL; data = 0; }

};

template<typename T>
class BSTree {




public:

	Node<T>* root;
	int height;
	int lh = 0, rh = 0;
	int h = 0, a = 0;

	BSTree() {

		root = NULL;
		height = 0;

	}

	Node<T>* getRoot()
	{
		return root;
	}
	int R_H() {
		h = 0, a = 0;
		Height(root);
		cout << "\nRoot\t" << root->data << "\t Root Height = " << h << endl;
		return 1;
	}

	int baanceFactor(Node<T>* r)
	{

		lh = 0; rh = 0;
		Node* templ = r->left;
		Node* tempr = r->right;
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

	int balanceFactor(Node<T>* r) {

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

	void Height(Node<T>* temp)
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

	void RR(Node<T>** temp) {
		cout << "\tRR\n";
		Node<T>* ch;					// 4-3-5
		ch = (*temp)->left;
		(*temp)->left = ch->right;
		ch->right = (*temp);
		(*temp) = ch;

	}

	void LL(Node<T>** temp) {
		cout << "\tLL\n";
		Node<T>* ch;
		ch = (*temp)->right;
		(*temp)->right = ch->left;
		ch->left = (*temp);
		(*temp) = ch;


	}

	void Left(Node<T>** temp) {
		cout << "\nLeft";
		LL(&((*temp)->left));
		RR(temp);

	}

	void Right(Node<T>** temp) {

		cout << "\nRight";
		RR(&((*temp)->right));
		LL(temp);


	}


	void Insert(Node<T>* number, Node<T>** temp)
	{
		if (root == NULL)
		{
			(root) = new Node<T>;
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

	void display(Node<T>* temp)  //traverse
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
		Node<T>* temp = root;

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

		Node<T>* templ = root->left;
		Node<T>* tempr = root->right;
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


	Node<T>* minimum(Node<T>* root)
	{
		if (root->left != NULL)
		{
			root = minimum(root->left);
		}
		else
		{
			return root;
		}
	}
	Node<T>* del(Node<T>* temp, int val)
	{
		if (root == NULL)
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
				Node<T>* det = temp;
				temp = temp->right;
				det = NULL;
				delete det;
			}
			else if (temp->right == NULL)
			{
				Node<T>* det = temp;
				temp = temp->left;
				det = NULL;
				delete det;
			}
			else
			{
				Node<T>* det = minimum(temp->right);
				temp->data = det->data;
				temp->right = del(temp->right, det->data);
			}
		}
		return temp;
	}
};

