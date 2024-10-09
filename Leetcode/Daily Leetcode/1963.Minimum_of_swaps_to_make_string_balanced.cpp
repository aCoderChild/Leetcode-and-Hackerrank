#include <bits/stdc++.h>
using namespace std;

/*
int minSwaps (string s) {
	stack<char> order;
	int swaps = 0;
	string after;
	int n = (int) s.size();
	int charCount = 0;
	for (char c : s) {
		if (c == '[') {
			after = after + c;
			charCount++;
		} else {
			if (after.back() == '[') {
				after = after + c;
			} else {
				if (charCount != n/2) {
					swaps++;
					order.push(c);
				} else {
					while (!order.empty()) {
						char d = order.top();
						after = after + d;
						order.pop();
						swaps++;
					}
 				}
			}
		}
	}
	cout << after << endl;
	return swaps;
}
*/

/*
int minSwaps(string s) {
	int imbalance = 0, swapCount = 0;
	for (char c : s) {
		if (c == '[') {
			imbalance ++;
		} else imbalance --;
		if (imbalance < 0) {
			imbalance++;
			swapCount ++;
		}
	}
	return swapCount;
}
*/

int minSwaps(string s) {
	stack<char> sk;
	int unbalanced = 0;
	for (char c : s) {
		if (c == '[') {
			sk.push(c);
		} else {
			if (!sk.empty()) sk.pop();
			else unbalanced++;
		}
	}
	return (unbalanced+1)/2;
}

int main() 
{
	string s;
	cin >> s;
	cout << minSwaps(s) << endl;
	return 0;
}