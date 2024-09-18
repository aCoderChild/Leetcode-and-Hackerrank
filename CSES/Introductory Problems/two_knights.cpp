#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	 ll k;
	 cin >> k;
	 for (ll i = 1; i <= k; i++) {
	 	ll total = i * i * (i * i - 1) / 2;
	 	ll attacking = 4 * (i -1 ) * (i - 2);
	 	ll ans = total - attacking;
	 	cout << ans << endl;

	 }
}

// remember the knights :( and the squares...