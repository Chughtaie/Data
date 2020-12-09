#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class BSTree {


	class Node {

	public:

		T data;

		Node* left;
		Node* right;
		Node() { left = right = NULL; data = 0;  }

	};

public:

	Node* root;
	int height;
	 int lh = 0, rh = 0;
	 int h = 0, a = 0;

	BSTree() {

		root = NULL;
		height = 0;

	}

	Node* getRoot()
	{
		return root;
	}
	int R_H() {
		h = 0, a = 0;
		Height(root);
		cout << "\nRoot\t" << root->data << "\t Root Height = " << h << endl;	
		return 1;
	}

	int baanceFactor(Node* r)
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

	int balanceFactor(Node* r) {
		
		if (!root)
			return -1;
		h = 0,a = 0;
		Height(r->left); lh = h;
		h = 0,a = 0;
		Height(r->right); rh = h;

		if (r->left ) lh++;
		if (r->right) rh++;
		//cout << "\nlh\t" << lh << "\trh\t" << rh << endl;
		return (lh-rh);
	}

	void Height(Node* temp)
	{
		if (root == NULL || temp== NULL)
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


	Node* LL_Rotate(Node* temp) {
	
		Node* ch;
		ch = temp->left;
		temp->left = NULL;
		ch->right = temp;
		return ch;
	}
	Node* RR_Rotate(Node* temp) {

		Node* ch;
		ch = temp->right;
		temp->right = NULL;
		ch->left = temp;
		return ch;
	}
	Node* LR_Rotate(Node* temp) {

		Node* ch = temp->left;
		temp->left = ch->right;
		ch->right = NULL;
		temp->left->left = ch;
		//ch->left = ch->right;
		//ch->right = NULL;

		return LL_Rotate(temp);
	}
	Node* RL_Rotate(Node* temp) {

		Node* ch = temp->right;
		temp->right = ch->left;
		ch->left = NULL;
		temp->right->right = ch;
		//ch->right = ch->left;
		//ch->left = NULL;

		return RR_Rotate(temp);
	}




	Node* Ball(Node *temp) {

		//h = 0, a = 0; Height(temp->left);
		//cout << endl << temp->data << "\theightleft" << h;// << balanceFactor(temp) << endl;	
		//h = 0, a = 0; Height(temp->right);
		//cout << endl << temp->data << "\theightright" << h;// << balanceFactor(temp) << endl;

		cout << "\ndata\t" << temp->data << "\t Bal \t" << balanceFactor(temp) << endl;
		cout << &(temp)<< endl;
		if (balanceFactor(temp) > 1) {
			cout << "\nZone 1\n";
			if (balanceFactor(temp->left) > 0)
				if (temp == root) { temp = LL_Rotate(temp); root = temp;	cout << "\t1111\t" << temp->data;; }
				else {
					temp = LL_Rotate(temp); cout << "\t2222\t" << temp->data;

					/*Node* yo = root; while (balanceFactor(yo->left) < 2) { yo = yo->left;  }
					yo->left = RR_Rotate(temp);*/
				}
			else
				if (temp == root) { temp = LR_Rotate(temp); root = temp;	cout << "\t3333\t" << temp->data;; }
				else { temp = LR_Rotate(temp);								cout << "\t4444\t" << temp->data; }
		}
		else if (balanceFactor(temp) < -1) {
			cout << "\nZone 2\n";
			if (balanceFactor(temp->right) < 0)
				if (temp == root) { temp = RR_Rotate(temp); root = temp; }
				else temp = RR_Rotate(temp);
			else
				if (temp == root) { temp = RL_Rotate(temp);  root = temp; }
				else temp = RL_Rotate(temp);

		}
		return temp;
	}



	void Insert(T number, Node* temp)
	{
		if (root == NULL)
		{
			root = new Node;
			root->data = number;
			temp = root;
			return;
		} 

		if (temp->data == number)
		{
			cout << " \n Given number is already present in tree.\n";
			return;
		}
		if (temp->data > number)
		{
			if (temp->left != NULL)
			{
				Insert(number,temp->left);

				//temp = Ball(temp);

				if (balanceFactor(temp) > 1) { //5-3-4
					cout << "\nZone 1\n";
					if (balanceFactor(temp->left) < 0) // 5-4-3
					{
						Node* ch = temp->left;
						temp->left = temp->left->right;
						//temp->left = ch->right;
						ch->right = NULL;
						temp->left->left = ch;
					
					}
					
					//Node* ch;					// 4-3-5
					//ch = temp;
					temp = temp->left;
					//temp->right = ch;
					//ch->left = NULL;
								
				}







				return;
			}
			else
			{
				temp->left = new Node;
				temp->left->data = number;
				return;
			}
		}

		if (temp->data < number)
		{
			if (temp->right != NULL)
			{
				Insert(number,temp->right);
				temp = Ball(temp);
				return;
			}
			else
			{
				temp->right = new Node;
				temp->right->data = number;
				return;
			}
		}
	}

	void display(Node* temp)  //traverse
	{
		if (temp == NULL)
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
		Node* temp = root;

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

		Node* templ = root->left;
		Node* tempr = root->right;
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


	Node* minimum(Node* root)
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
	Node* del(Node* temp, int val)
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
				Node* det = temp;
				temp = temp->right;
				det = NULL;
				delete det;
			}
			else if (temp->right == NULL)
			{
				Node* det = temp;
				temp = temp->left;
				det = NULL;
				delete det;
			}
			else
			{
				Node* det = minimum(temp->right);
				temp->data = det->data;
				temp->right = del(temp->right, det->data);
			}
		}
		return temp;
	}
};




/*s
void Insert(T d)
{
	Node* temp = root;

	if (root == NULL)
	{
		root = new Node;
		cout << d << endl;
		root->data = d;
		temp = root;

	}
	else
	{

		while (temp)
		{

			if (d > temp->data)
			{
				if (temp->right == NULL)
				{
					temp->right = new Node;
					cout << d << endl;
					temp->right->data = d;
					break;
				}
				else

					temp = temp->right;
			}
			else
			{

				if (temp->left == NULL)
				{
					temp->left = new Node;
					cout << d << endl;
					temp->left->data = d;  break;
				}
				else
					temp = temp->left;
			}
		}

		if (balanceFactor(temp) == -2 && balanceFactor(temp->right) == -1)
		{
			Node* tempnode1;
			Node* tempnode2;
			tempnode1 = temp;
			tempnode2 = tempnode1->right;

			tempnode1->right = tempnode2->left;
			tempnode2->left = tempnode1;
			temp = tempnode2;
		}
		else if (balanceFactor(temp) == 2 && balanceFactor(temp->left) == 1)
		{
			Node* tempnode1;
			Node* tempnode2;
			tempnode1 = temp;
			tempnode2 = tempnode1->left;

			tempnode1->left = tempnode2->right;
			tempnode2->right = tempnode1;

			temp = tempnode2;
		}
		else if (balanceFactor(temp) == -2 && balanceFactor(temp->right) == 1)
		{
			Node* tempnode1;
			Node* tempnode2;
			Node* tempnode3;
			tempnode1 = temp;
			tempnode2 = tempnode1->right;
			tempnode3 = tempnode1->right->left;

			tempnode1->right = tempnode3->left;
			tempnode2->left = tempnode3->right;
			tempnode3->left = tempnode1;
			tempnode3->right = tempnode2;

			temp = tempnode3;
		}
		else if (balanceFactor(temp) == 2 && balanceFactor(temp->left) == -1)
		{
			Node* tempnode1;
			Node* tempnode2;
			Node* tempnode3;
			tempnode1 = temp;
			tempnode2 = tempnode1->left;
			tempnode3 = tempnode1->left->right;

			tempnode1->left = tempnode3->right;
			tempnode2->right = tempnode3->left;
			tempnode3->right = tempnode1;
			tempnode3->left = tempnode2;

			temp = tempnode3;
		}

	}
}*/