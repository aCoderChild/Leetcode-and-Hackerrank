class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 0) return 0;
        vector<int> memo(n+1, -1);
        memo[0] = 0;
        memo[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            memo[i] = max(memo[i-2]+nums[i-1], memo[i-1]);
        }
        return memo[n];
    }
};