#include<iostream>
#include<cstring>
#include<string>
#include <fstream>
using namespace std;

template<typename T,typename T1>
class AvlNode {

public:

	T data;		//Foxxy
	T path;		//file1
	T1 line_no;	//line no
	T1 key;		//foxxy ki hash
	T1 mach;		//machine no.


	AvlNode* left;
	AvlNode* right;
	AvlNode() { left = right = NULL; data = path = "";  line_no = key = mach = 0; }
	AvlNode(AvlNode* copy) { left = right = NULL; data = copy->data; path = copy->path;  line_no = copy->line_no; key = copy->key; mach = copy->mach; }
	void Set(AvlNode* copy) {  data = copy->data; path = copy->path;  line_no = copy->line_no; key = copy->key; mach = copy->mach; }

};

template<typename T, typename T1>
class AvlTree {


public:

	AvlNode<T,T1>* root;
	AvlNode<T,T1>* dele;
	T1 key;

	int height;
	int lh = 0, rh = 0;
	T1 h = 0, a = 0;
	bool avail = 1;

	AvlTree() {

		root = dele = NULL;
		height = 0;

	}

	AvlNode<T, T1>* getRoot()
	{
		return root;
	}

	int R_H() {
		h = 0, a = 0;
		Height(root);
		//cout << "\nRoot\t" << root->data << "\t Root Height = " << h << endl;
		return 1;
	}

	int balanceFactor(AvlNode<T, T1>* r) {

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

	void Height(AvlNode<T, T1>* temp)
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

	void RR(AvlNode<T, T1>** temp) {
		//cout << "\tRR\n";
		AvlNode<T, T1>* ch;					// 4-3-5
		ch = (*temp)->left;
		(*temp)->left = ch->right;
		ch->right = (*temp);
		(*temp) = ch;

	}

	void LL(AvlNode<T, T1>** temp) {
		//cout << "\tLL\n";
		AvlNode<T, T1>* ch;
		ch = (*temp)->right;
		(*temp)->right = ch->left;
		ch->left = (*temp);
		(*temp) = ch;


	}

	void Left(AvlNode<T, T1>** temp) {
		//cout << "\nLeft";
		LL(&((*temp)->left));
		RR(temp);

	}

	void Right(AvlNode<T, T1>** temp) {

		//cout << "\nRight";
		RR(&((*temp)->right));
		LL(temp);


	}

	void Insert(AvlNode<T, T1>* number, AvlNode<T, T1>** temp)
	{
		//cout << "\nEntered\n";
		if (number == NULL) return;
		if (root == NULL)
		{
			(root) = new AvlNode<T, T1>;
			root = number;
			*temp = root;
			return;
		}

		else if ((*temp)->key == number->key)
		{
			cout << " \n Given number is already present in tree.\t" << number->data << "\t" << number->mach << endl;
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

	void Show(AvlNode<T, T1>* temp) {
	
		cout << "\ndata	\t" << temp->data	<< '\t';	// left root right
		cout << "path	\t" << temp->path	<< '\t';	// left root right
		cout << "line no\t" << temp->line_no<< '\t';	// left root right
		cout << "mach	\t" << temp->mach	<< '\t';	// left root right
		cout << "key	\t" << temp->key	<< '\t';	// left root right		
	}

	void display(AvlNode<T, T1>* temp,T1 val=0)  //traverse
	{
		if (temp == NULL || root == NULL)
			return;		

		if (val <= 0) Show(temp);	//Preorder

		if (temp->left != NULL)
			display(temp->left,val);    //LVR display

		if (val == 1) Show(temp);	//Inorder

		if (temp->right != NULL)
			display(temp->right, val);

		if (val > 1)  Show(temp);	//PostOrder
		

	}

	AvlNode<T, T1>* retrieve(T1 d)
	{
		AvlNode<T, T1>* temp = root;

		while (temp)
		{
			//cout << "str   " << stoi(temp->key) << "\t" << stoi(d) << endl;
			if (temp->key == d)
				return temp;

			if (d > temp->key)
				temp = temp->right;
			else
				temp = temp->left;
		}
		cout << "\nDoes Not Exist\n";
		return NULL;
	}

	/*
	int MAXHeight()
	{
		lh = rh = 0;
		if (root == NULL)
		{
			cout << "Empty tree\n";
			return 0;
		}

		AvlNode<T, T1>* templ = root->left;
		AvlNode<T, T1>* tempr = root->right;
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
	*/

	AvlNode<T, T1>* minimum(AvlNode<T, T1>* min)
	{
		if(min)
		while (min->left)
			min = min->left;
		return min;
	}

	void Bal(AvlNode<T, T1>** temp,T1 number) {
	
		if (!(*temp)) return;

		if (balanceFactor(*temp) == 2) { //5-3-4
			if (number > (*temp)->left->key) // 5-4-3
				RR(temp);
			else
				Left(temp);
		}
		else
		if (balanceFactor(*temp) == -2) { //5-3-4
				if (number < (*temp)->right->key) // 5-4-3
					LL(temp);
				else
					Right(temp);

			}	
	}

	//==========special search===========//
	void Search(AvlNode<T, T1>* temp, T1 mac, T1 mac2)  //traverse
	{
		if (temp == NULL || root == NULL)
			return;
		if (temp->mach <= mac && key == -1) key = temp->key;
		if (temp->mach >= mac2 && mac2 != -1 && key == -1) key = temp->key;

		if (temp->left != NULL)
			Search(temp->left, mac, mac2);    //LVR display

		if (temp->right != NULL)
			Search(temp->right, mac, mac2);

	}

	AvlNode<T, T1>* Delete_Mach(T1 mach, T1 mac2 = -1) {
		//AvlNode<T, T1>* temp = (root);
		dele = NULL;
		key = -1;
		Search(root, mach, mac2);
		cout << key;
		//if(key!=-1)
		Delete(&root, key);
		if (dele) {
	
			dele->right = NULL;		
			dele->left = NULL;
		}
		return dele;
	}

	AvlNode<T, T1>* Delete(AvlNode<T, T1>** temp, T1 n) {
		if (*temp == NULL )
			return *temp;
		if (n > (*temp)->key)
		{
			//(*temp)->right = 
			Delete(&((*temp)->right), n);	//
			Bal(&((*temp)),n);
		}
		else if ((*temp)->key > n)
		{
			//(*temp)->left = 
			Delete(&((*temp)->left), n);	//
			Bal(&((*temp)), n);
		}
		else {
			if ((*temp)->left == NULL && (*temp)->right == NULL) {
				//delete *temp;				
				//AvlNode<T>* loo = (*temp);
				dele = *temp;
				*temp = NULL;
				//return loo;

			}
			else if ((*temp)->left == NULL) {
				//AvlNode<T>* temp1 = *temp;
				if (!dele)
				dele = *temp; 
				*temp = (*temp)->right;
				//return temp1;
				//delete temp1;
			}
			else if ((*temp)->right == NULL) {
				//AvlNode<T>* temp1 = *temp;
				if(!dele)
				dele = *temp;
				*temp = (*temp)->left;				
				//return temp1;
				//delete temp1;

			}
			else { //case  3
				if (!dele)
					dele = new AvlNode<T,T1>(*temp);
				AvlNode<T, T1>* temp1 = minimum((*temp)->right);		
				(*temp)->Set(temp1);
				/*(*temp)->data	= temp1->data;
				(*temp)->mach	= temp1->mach;
				(*temp)->key	= temp1->key;
				(*temp)->path	= temp1->path;
				(*temp)->line_no= temp1->line_no;
				*/
				//(*temp)->right	=
				Delete(&((*temp)->right),temp1->key);
			}
		}
		return *temp;
	}
};





/*AvlNode<T>* Delete(AvlNode<T>* temp, int val)
{
	cout << "\ndel\n";
	if (root == NULL || temp==NULL)
	{
		return root;
	}
	else if (temp->data > val)
	{
		temp->left = Delete(temp->left, val);
	}
	else if (temp->data < val)
	{
		temp->right = Delete(temp->right, val);
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
			temp->right = Delete(temp->right, det->data);
		}
	}
	return temp;
}*/