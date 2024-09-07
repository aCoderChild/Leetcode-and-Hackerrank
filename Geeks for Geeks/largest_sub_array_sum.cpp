//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int start = 0;
        int end = 0;
        
        int sum = A[start];
        int res = 0;
        int cur = 1;
        
        while (end < N) {
            if (sum < K) {
                end ++;
                sum += A[end];
                cur++;
            }
            
            else if (sum > K) {
                if (start < end) {
                    cur--;
                    sum -= A[start];
                    start++;
                } else {
                    cur = 1;
                    end++;
                    start = end;
                    sum = A[start];
                }
            }
            
            else {
                res = max(res, cur);
                sum -= A[start];
                start++;
                cur--;
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

// Sliding window technique
// Only work for POSITIVE INTEGERS, monotonic trend (not like both Positive and Negative)
// using 2 pointers like sliding window
