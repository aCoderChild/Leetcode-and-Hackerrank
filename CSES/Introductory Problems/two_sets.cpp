#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll n;
	cin >> n;
	vector<ll> nums1;
	vector<ll> nums2;

	nums1.push_back(n);
	nums2.push_back(n-1);
	ll sum1 = n, sum2 = n-1;

	int i = n - 2;
	while (i >= 1) {
		ll top1 = nums1.back();
		ll top2 = nums2.back();

		if (top1 > top2) {
			nums2.push_back(i);
			sum2 += i;
			i--;
			if (i > 0) {
				nums1.push_back(i);
			}

			sum1 += i;
			i--;
		}

		else {
			nums1.push_back(i);
			sum1 += i;
			i--;
			nums2.push_back(i);
			sum2+= i;
			i--;
		}
	}

	if (sum1 == sum2) {
		cout << "YES" << endl;
		cout << nums1.size() << endl;
		for (ll i : nums1) {
			cout << i << " ";
		}
		cout << endl;
		cout << nums2.size() << endl;
		for (ll i : nums2) {
			cout << i << " ";
		}
		cout << endl;
	}
	else cout << "NO" << endl;
	return 0;
}