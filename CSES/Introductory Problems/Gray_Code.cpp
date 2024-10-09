/*
#include <bits/stdc++.h>
using namespace std;

void permutation(string s, int current, int n) {
	if (current == n) {
		cout << s << endl;
	}
	else {
		permutation(s + '0', current + 1, n);
		permutation(s + '1', current + 1, n);
	}
}

int main()
{
	int n;
	cin >> n;
	permutation("",0,n);
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

void permutation(vector<string>& result, string s, int current, int n) {
	if (current == n) result.push_back(n);
	else {
		permutation(result, s+'0', current + 1, n);
		permutation(result, s+'1', current + 1, n);
	}
}

int main() {
    int n = 3; // generate permutations of length 3
    vector<string> result;
    permutation(result, "", 0, n);
    for (const auto& str : result) {
        cout << str << endl;
    }
    return 0;
}
*/

//just the normal permutation, not the gray code

#include <bits/stdc++.h>
using namespace std;

vector<string> grayCode(int n) {
	vector<string> actual;
	if (n == 1) {
		actual.push_back("0");
		actual.push_back("1");
		return actual;
	}

	vector<string> previous = grayCode(n-1);
	for (int i = 0; i < (int) previous.size(); i++) {
		string s;
		s += '0';
		s += previous[i];
		actual.push_back(s);
	}

	for (int i = (int) previous.size() - 1; i >= 0; i--) {
		string s;
		s += '1';
		s += previous[i];
		actual.push_back(s);
	}
	return actual;
}

int main()
{
	int n;
	cin >> n;
	vector<string> ans = grayCode(n);
	for (string s  : ans) {
		cout << s << endl;
	}
	return 0;
}
