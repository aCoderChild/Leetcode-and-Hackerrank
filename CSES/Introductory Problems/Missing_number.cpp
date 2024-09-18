#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	vector<int> input(n-1);
	for (int i = 0; i < n-1; i++) {
		cin >> input[i];
	}

	sort(input.begin(), input.end());
	for (int i = 0;i < n; i++) {
		if (input[i] != i+1) {
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}