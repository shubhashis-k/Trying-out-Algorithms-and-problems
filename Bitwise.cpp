#include <iostream>
#include <vector>

using namespace std;

void PrintBinary(int number) {//this is constant time
	int a = number;

	int closest = ceil(log2(a));
	int b = 1 << closest;

	while (b > 0) {
		int res = b&a;
		if (res > 0) cout << 1;
		else cout << 0;
		b = b >> 1;
	}
	cout << endl;
}

int findingDistinctNumberUsingXOR(vector<int>& nums) { //every number except 1 is duplicated. XORing will get rid of every number except that number.
	int result = 0;
	for (int i = 0; i < nums.size(); i++) {
		result = result^nums[i];
	}
	return result;
}


int main()
{
	int t = 5 ^ 3;
	PrintBinary(t);
	PrintBinary((t^(t - 1))&t);
}