#include <bits/stdc++.h>
using namespace std;

//custom comparator, using concentation of the two strings
bool isLarger(string a, string b) {
	string a_b = a + b;
	string b_a = b + a;

	for (int i = 0; i < (int) (a.size() + b.size()); i++) {
		if ((a_b[i] - '0') > (b_a[i] - '0')) return true;
		else if ((a_b[i] - '0') < (b_a[i] - '0')) return false;
	}
	return false;
}

string largestNumber(vector<int>& nums) {
	string res;
	vector<string> nums_to_string;
	for (int i : nums) {
		nums_to_string.push_back(to_string(i));
	}

	for (int i = 0; i < nums.size(); i++) {
		for (int j = i+1; j < nums.size(); j++) {
			if (isLarger(nums_to_string[j], nums_to_string[i])) swap(nums_to_string[i], nums_to_string[j]);
		}
	}

	for (string i : nums_to_string) {
		res = res + i;
	}

	int i = 0;
	//remove leading zeros
    while (i < res.size() && res[i] == '0') {
        res.erase(res.begin() + i);
    }
    if (res.empty()) res = "0";
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << largestNumber(a);
}