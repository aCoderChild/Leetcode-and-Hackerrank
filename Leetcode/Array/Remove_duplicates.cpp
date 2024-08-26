class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < (int) nums.size() - 1;) {
            if(nums[i] == nums[i+1]) nums.erase(nums.begin() + i + 1);
            else i++;
        }
        int k = (int) nums.size();
        return k;
    }
};

// BAD runtime
// Space complexity is quite good


// --- Better Approach: 2 Pointers ---
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < (int) nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
//Time Complexity: O(N)