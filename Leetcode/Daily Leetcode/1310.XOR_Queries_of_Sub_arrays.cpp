//Approach: use prefx sum
#include<bits/stdc++.h>
using namespace std;

void preprocess(vector<int> arr, vector<int>& prefixSum) {
	cout << "the prefixSum table: ";
    for (int i = 1; i < (int) arr.size(); i++) {
        prefixSum[i] = prefixSum[i-1] ^ arr[i];

        cout << prefixSum[i] << " ";// print the prefix sum table
    }
    cout << endl;     
}

int findXOR(vector<int> prefixSum, vector<int> query) {
   	if (query[0] == 0) return prefixSum[query[1]];
    else return prefixSum[query[1]] ^ prefixSum[query[0] - 1];
}

vector<int> xorQueries(vector<int>& arr, vector<vector<int> >& queries) {
    vector<int> res;
    int n = (int) arr.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = arr[0];
    preprocess(arr, prefixSum);
    for (auto query : queries) {
        res.push_back(findXOR(prefixSum, query));
    }
    return res;
}

int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<vector<int> > queries(q, vector<int>(2));
	for (int i = 0; i < q; i++) {
		cin >> queries[i][0] >> queries[i][1];
	}

	vector<int> res = xorQueries(arr, queries);
	for (auto i : res) {
		cout << i << " ";
	}
	return 0;
}

//XOR properties:
// - a ^ a = 0
// - a ^ 0 = a
//Time complexity: O(N + Q)