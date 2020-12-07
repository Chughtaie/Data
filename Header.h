#pragma once

#include <iostream>
using namespace std;

template <class T>
struct Arr {

	T str;// = "fxkhjvgh";
	Arr* next;

	Arr() { str = ' '; next = NULL; }
};

template <class T>
class Queue {
	/*	A linkedlist based queue to implement databases
		Implement additional functions as per requirement
	*/
	Arr<T>* front;
	Arr<T>* back;
	Arr<T>* ptr;
	int size=0;

public:

	Queue() {
		front = NULL;
		back = front;
		ptr = front;
	}

	T Front() {

		return T(front->str);
	}
	T Back() {

		return T(back->str);
	}

	T enqueue(T val) {

		if (front == NULL) {
			front = new Arr<T>;
			front->str = val;
			back = front;
			//size++;
		}
		else {

			back->next = new Arr<T>;
			back = back->next;
			back->str = val;

		}
		size++;
		return back->str;
	}

	T dequeue() {

		if (!is_empty()) {

			Arr<T>* var = front;
			T temp = front->str;
			front = front->next;
			//delete var;
			size--;
			return temp;

		}
		return ' ';

	}

	bool is_empty() {
		if (size == 0) return true;
		if (front == NULL)	return true;
		if (back == NULL)	return true;
		return false;
	}

	int Size(int o = 0) {

		return size;

	}

	//void Print() {

	//	cout << endl << "Print of Queue is called\n\n";
	//	ptr = front;

	//	while (ptr != back)
	//	{
	//		cout << ptr->str << endl;
	//		ptr = ptr->next;
	//	}
	//	cout << ptr->str << endl;

	//}

};



template <class T>
class Stack {

	Arr<T>* point;
	Arr<T>* ptr;
	/* Implement a stack for your Alien Database operations */
public:
	Stack() {
		point = NULL;
	}

	void push_roll(T add) {
		
		

		if (point == NULL) {
			point = new Arr<T>; point->str = add; cout << "  " << point->str << endl;
			return;
		}
		else {
			ptr = new  Arr<T>;
			ptr->next = point;
			point = ptr;
			point->str = add; cout << "  " << point->str << endl;
		}
		//cout <<ptr->next->cnic << "  " << ptr->next->get_str() << endl;
	}

	T top() {

		return point();
	}

	T pop() {

		T str;
		ptr = point;

		if (point == NULL) return NULL;
		else 
		str = point->str;
		 point = point->next;
		return str; 
		

	}
	bool function(T val[200]) {
		char o;
		bool b = 1;
		for (int i = 0; val[i] != '\0' && i < 200 && b==1; i++){
			if (val[i] == '(' || val[i] == '{' || val[i] == '[')
			{
				cout << "input " << val[i] << endl;

				push_roll(val[i]);
			}
		if (val[i] == ')' || val[i] == '}' || val[i] == ']')
		{
			o = pop();

			cout <<"compare "<<val[i] << " "<< o << endl;

			//if (o == '(' || o == '{' || o == '[')
			if ((o == '(' && val[i] == ')' || o == '{' && val[i] == '}' || o == '[' && val[i] == ']'))

			{
				b = 1;
			}
			else
			{
				b = 0; return 0;
			}
		}
	}
		
		if (!is_empty())
		{
			cout << "hgjfyf";
			return 0;
		}
		return b;

	//	string a;
	//	char oo = ' ';
	//	bool out = 1;
	//for (int i = 0; val[i] != '\0' && i<200; i++) {
	//	if (val[i] != '(' && val[i] != '{' && val[i] != '[' && val[i] != ')' && val[i] != '}' && val[i] != ']')
	//	{
	//			cout << "";
	//	}
	//	else if (val[i] == '(' || val[i] == '{' || val[i] == '[')
	//	{
	//		push_roll(val[i]); a += val[i];
	//		// cout << val[i];
	//	}
	//	else 
	//	{
	//		oo = pop();  a += val[i];
	//		cout << a << endl;
	//		//cout << val[i]; a+=
	//		if (!(oo == '(' && val[i] == ')' || oo == '{' && val[i] == '}' || oo == '[' && val[i] == ']'))
	//			return false;	//out = 1;

	//		//else return 0;


	//	}//cout << i;
	//	//Print(); cout << endl;
	//}
	//	cout << "khsfyfg";
	//	if (is_empty())  return true;

	//	else
	//		return false;
	
	}

	bool is_empty() {
		if (point == NULL) return true;
		return false;
	}

	void Print() {
	
		ptr = point;
		while (ptr != NULL) {
		
			cout << ptr->str;
				ptr = ptr->next;
		
		
		}
	
	
	
	}

};