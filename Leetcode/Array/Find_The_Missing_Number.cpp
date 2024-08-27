class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end()); //Time complexity: NlogN
        for (int i = 0; i < n-1; i++) {
            if (nums[i+1] - nums[i] != 1) {
                return nums[i]+1;
            } 
        }
        if (nums[0] != 0) return 0;
        return nums[n-1]+1;
    }
};

// Time Complexity: O(NlogN)

//--- Better Approach ---
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n + 1) / 2);
        int s2 = 0;
        for(int i = 0; i < n; i++)
        {
            s2 += nums[i];
        }
        return sum - s2;
    }
};
// Time Complexity: O(N) - only traversing to get the sum of the sequence