//Most simple approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int) nums.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[(i+k)%n] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};
//Analysis:
// Time complexity: O(N);
// Space complexity: O(N) (new vector)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int) nums.size(); //not to get out of boundaries
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
// Time Complexity: O(N);
// Space Complexity: O(1) (no extra memory)