#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int maxLength = 0, current = 0;
	char key = s[0];
	for (int i = 0; i < (int) s.size(); i++) {
		if (s[i] == key) {
			current++;
		}
		else {
			maxLength = max(maxLength, current);
			current = 1;
			key = s[i];
		}
	}
	maxLength = max(maxLength, current);
	cout << maxLength << endl;
	return 0;
}