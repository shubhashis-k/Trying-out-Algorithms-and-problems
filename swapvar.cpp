#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int y = 5;

	x = x + y;
	y = x - y;
	x = x - y;
	//can be done via multiply, divide 

	cout << x << y;
}