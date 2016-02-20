#include <iostream>

using namespace std;

void somefun(int *p) {
	cout << "inside function" << *p;
}

int main()
{
	int q = 10;
	int *p;
	p = &q;
	cout << *p;
	*p = 20;
	cout << "value of q" << q << endl;

	int *a = new int;
	*a = 10;
	cout << *a << endl;
	
	//without allocating memory it will fail. As, at first b points to nothing. *b means 
	//dereferencing the pointer. If we dereference the pointer then we will get an undefined address. So it fails 

	/*
	int *b;
	*b = 10;
	cout << *b;
	*/
	int *fv = new int;
	*fv = 10;
	somefun(fv);
}