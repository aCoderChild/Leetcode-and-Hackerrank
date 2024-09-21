#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

/*
bool isPossible(ll a, ll b) {
	if (a == 0 && b == 0) return true;
	if (a < 0 || b < 0) return false;

	return isPossible(a-1, b-2) || isPossible(a-2, b-1);
}

int main()
{
	ll n;
	cin >> n;
	while (n--) {
		ll a, b;
		cin >> a >> b;
		if (isPossible(a, b)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
*/

//use logical OR to COMBINE the results

int main()
{
	ll n;
	cin >> n;
	while (n--) {
		ll a, b;
		cin >> a >> b;
		if ((2*a-b) >= 0 && (2*a-b) % 3 == 0 && (2*b-a) >= 0 && (2*b-a) % 3 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}