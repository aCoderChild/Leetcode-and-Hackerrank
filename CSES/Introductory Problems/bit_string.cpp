#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main()
{
	int n;
	cin >> n;
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= 2;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}

//please analyse the problem first, thinking just BASIC solution
//ANALYSE THE PROPERTIES