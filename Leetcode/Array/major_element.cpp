class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int current = 0, maxFreq = 0, currentNumber = 0, ans;
        for (int i = 0; i < (int) nums.size(); i++) {
            if (currentNumber == 0) currentNumber = nums[i];
            if (nums[i] == currentNumber) current++;
            else {
                if (current > maxFreq) {
                    ans = nums[i-1];
                    maxFreq = current;
                }
                current = 1;
                currentNumber = 0;
            }
        }
        if (current > maxFreq) ans = nums[(int)nums.size()-1];
        return ans;
    }
};