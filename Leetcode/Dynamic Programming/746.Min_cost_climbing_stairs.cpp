class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int) cost.size();
        int a[n+2];
        a[0] = 0;
        a[1] = cost[0];
        for (int i = 2; i <= n; i++) {
            a[i] = min(a[i-2]+cost[i-1], a[i-1]+cost[i-1]);
        } 
        a[n+1] = min(a[n], a[n-1]);
        return a[n+1];
    }
};