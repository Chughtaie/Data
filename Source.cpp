#include "pch.h"
#include "../lab 9/Header.h"

TEST(Queue, Concat) {

	Queue<char> var[4];
	Queue<char> fin;
	/*
	char ab;
	for (int i = 0; i < 4; i++) {
		cin >> ab;
		var[i].enqueue(a);

	}*/
	int i = 0;
	var[i].enqueue('d');
	var[i].enqueue('a');
	var[i].enqueue('t');
	var[i].enqueue('a');
	//var[0].Print();
	i++;

	var[i].enqueue('s');
	var[i].enqueue('t');
	var[i].enqueue('r');
	var[i].enqueue('u');
	var[i].enqueue('c');
	var[i].enqueue('t');
	//var[0].Print();
	i++;

	var[i].enqueue('a');
	var[i].enqueue('n');
	var[i].enqueue('d');
	i++;

	var[i].enqueue('A');
	var[i].enqueue('l');
	var[i].enqueue('g');
	var[i].enqueue('o');
	//var[0].Print(); var[1].Print(); var[2].Print(); var[3].Print();

	i++;

	i = 0;
	while (i<4){
	//for (int j=0; var[i]. ; j++) {
		while(!var[i].is_empty()){
		fin.enqueue(var[i].dequeue());
		}
		fin.enqueue(' ');
		i++;
	}


	while (!fin.is_empty())
		cout << fin.dequeue();

	
	EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Stack, brackets__jn) {

	char arr[100] = "#include<iostream> using namespace std; int main{ ()System(“Pause”); }";

	Stack<char> var;
EXPECT_EQ(1, var.function(arr));

EXPECT_TRUE(true);
}


TEST(Stack, brackets_valid) {

	char arr[200] = "Test1.txt #include<iostream> using namespace std; int main ()	{	System(“Pause”);	}";

	Stack<char> var;
	EXPECT_EQ(1, var.function(arr));

	EXPECT_TRUE(true);
}


TEST(Stacks, brackets_Invalid) {

	char arr[200] = "Test3.txt #include<iostream> using namespace std; int main(){	for (int i = 0; i < 10; i++)	{cout << i << end; system(“pause”);}";

	Stack<char> var;
	EXPECT_EQ(0, var.function(arr));

	//EXPECT_TRUE(true);
}