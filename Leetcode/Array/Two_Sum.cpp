class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int) nums.size();
        vector<pair<int, int>> nums1;
        for (int i = 0; i < n; i++) {
            nums1.push_back({nums[i], i});
        }
        int left = 0;
        int right = n-1;
        sort(nums1.begin(), nums1.end());
        while (left < right) {
            if (nums1[left].first + nums1[right].first == target) {
                return {nums1[left].second, nums1[right].second}; //pair
            }

            if (nums1[left].first + nums1[right].first < target) left++;
            else if(nums1[left].first + nums1[right].first > target) right--;
        }
        return {};
    }
};
/* Analyse:
- time complexity: O(n) (linear time) - use left and right indices to keep track
- space complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution  found
  
    }
};
/* Analyse:
- time complexity: O(n^2) - 2 for loop within each other
*/