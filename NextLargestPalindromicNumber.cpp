#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>
#include <string>

using namespace std;

int myCompare(string X, string Y)
{
	// first append Y at the end of X
	string XY = X+Y;

	// then append X at the end of Y
	string YX = Y+X;

	// Now see which of the two formed numbers is greater
	if (XY > YX) return 1;
	return 0;
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector <string> v;

		for (int i = 0; i < nums.size(); i++) {
			v.push_back(to_string(nums[i]));
		}

		sort(v.begin(), v.end(), myCompare);

		string result = "";

		for (int i = 0; i < v.size(); i++) {
			result += v[i];
		}

		return result;
	}
};


int main() {
	vector<int> v;
	v.push_back(3);
	v.push_back(30);
	v.push_back(34);
	v.push_back(5);
	v.push_back(9);

	Solution s;

	cout << s.largestNumber(v);
}
