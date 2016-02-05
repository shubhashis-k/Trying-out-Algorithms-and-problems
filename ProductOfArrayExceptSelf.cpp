#include <iostream>

using namespace std;

/*
It is like this [1,2,3,4]

At first compute the left sum, that is sum of all elements from left side except that element
thus we get [1(default),1,2,6] ~[1,1,2,6]

Then compute sum of all elements that is on right side. 
[24,12,4,1]

The result is 
[1x24,1x12,2x4,6x1]

Thus multiple of left and right side except that element is the answer

http://www.geeksforgeeks.org/a-product-array-puzzle/
*/

//This is the same implementation with constant space O(1)[output array is ignored from space complexity computation]
void productArray(int arr[], int n)
{
	int temp = 1;
	int prod[5];

	for (int i = 0; i < n; i++)
		prod[i] = 1;

	for (int i = 1; i < n; i++) {
		temp *= arr[i - 1];
		prod[i] *= temp;
	}

	temp = 1;
	for (int i = n - 2; i >= 0; i--) {
		temp *= arr[i+1];
		prod[i] *= temp;
	}

	for (int i = 0; i < n; i++)
		cout << prod[i] << " ";
	return;
}

int main()
{
	int arr[] = {10, 3, 5, 6, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("The product array is: \n");
	productArray(arr, n);

}