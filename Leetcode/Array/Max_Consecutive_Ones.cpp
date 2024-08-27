class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = (int) nums.size();
        int maximum = 0;
        int current = 0;
        for (int i = 0; i < n; i++) {
            if(nums[i] == 1) current ++;
            if(nums[i] == 0) {
                maximum = max(maximum, current);
                current = 0;
            }
        }
        maximum = max(maximum, current);
        return maximum;
    }
};