#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	ll n;
	cin >> n;
	for (int i = 0 ; i < n; i++) {
		ll x, y;
		cin >> x >> y;

		/*
		ll z = max(x, y), ans;
		ll z2 = z * z; //most important
		if (z % 2 == 0) {
			ans = z2 - (y-1);
		} else {
			ans = z2 - (x-1);
		}
		*/

		ll z = max(x, y), ans;
		ll z2 = (z-1) * (z-1);
		if (z == y) {
			if (z % 2 == 0) ans = z2 + x;
			else ans = z2 + 2 * z - x;
		} else {
			if (z % 2 == 1) ans = z2 + y;
			else  ans = z2 + 2 * z - y;
		}

		cout << ans << endl;
	}
}
//figure out by looking at the examples
//find the last full layer where all the numbers are < than target