#include <iostream>

using namespace std;

struct node {
	string type;
	void *item;
	node *next;
};
typedef node * nodeptr;

nodeptr Head;

void insertNode(nodeptr n)
{
	if (Head == NULL)
	{
		Head = n;
	}

}

void printNode()
{
	nodeptr n = Head;
	if (n->type == "int")
		cout << *(static_cast<int*>(n->item)) << endl;
}


int main()
{
	/*
	int value = 5;
	void *voidPtr = &value;

	int *intPtr = static_cast<int*>(voidPtr); // however, if we cast our void pointer to an int pointer...

	cout << *intPtr << endl; // then we can dereference it like normal
	*/

	int val = 5;


	nodeptr n = new node;
	n->type = "int";
	n->item = &val;
	n->next = NULL;

	insertNode(n);
	printNode();
}