//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int res = 0;
        int sum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        for (int i = 0; i < N; i++) {
            sum += A[i];
            if (prefixSum.find(sum - K) != prefixSum.end()) {
                res = max(res, i - prefixSum[sum - K]);
            }
            
            if (prefixSum.find(sum) == prefixSum.end()) {
                prefixSum[sum] = i;
            }
        }
        return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

// PrefixSum technique: cumulative method used for both positive and negative integers
// use hash table
// time complexity of find function in a map: O(N) (worst case) / O(1) (best case)
// if it is a normal map => O(log N) (binary search)
