#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
/*
int main()
{
	ll n;
	cin >> n;
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		if (i % 10 == 0) {
			int c = i;
			while (c % 10 == 0) {
				res++;
				c /= 10;
			}
			if (c % 5 == 0) res++;
		}

		if (i % 5 == 0 && i % 10 != 0) {
			res++;
		}
	}
	cout << res << endl;
	return 0;
}
*/

//not to the limited time
/*
int main()
{
	ll n;
	cin >> n;
	ll res = 0;
	int largestNum = n - (n % 5);
	for (int i = 5; i <= largestNum; i *= 5) {
		for (int j = 1; j <= n; j++) {
			if (j % i == 0) res++;
		}
	}
	cout << res << endl;
	return 0;
}
*/
//analyse: right approach, using the math concept of trailing zeros and base-ten representation

int solve(int N) {
	if (N == 0) return 0;
	else return N / 5 + solve(N / 5);
}

int main()
{
	int N;
	cin >> N;
	cout << solve(N) << endl;
	return 0;
}