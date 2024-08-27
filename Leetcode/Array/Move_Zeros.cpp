class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = (int) nums.size();
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[i] == 0) {
                if (nums[j] != 0) {
                    swap(nums[i], nums[j]);
                    i++;
                }
            } else {
                i++;
            }
        }
    }
};

// Time Complexity: O(n) - traverse one time (runtime top 10%)
// Space Complexity: O(1) - no extra memory