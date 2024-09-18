#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int mx = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mx = max(x, mx); //find the max of the pre sequence (aka last number)
		ans += mx-x;
		//cout << ans << endl;
	}
	cout << ans;
}