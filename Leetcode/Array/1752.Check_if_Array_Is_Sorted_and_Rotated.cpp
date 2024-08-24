class Solution {
public:
    bool check(vector<int>& nums) {
        int n = (int) nums.size();
        int i = 0;
        for (; i < n; i++) {
            if (nums[i] < nums[0]) break;
            if (nums[i] == nums[0]) {
                if (i == n-1) break;
                else {
                    bool flag = true;
                    for (int j = i+1; j < n; j++) {
                        if (nums[j] != nums[i]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) break;
                }
            }
        }

        vector<int> temp(n);
        for (int j = 0; j < n; j++) {
            temp[j] = nums[(j+i) % n];
        }

        for (int j = 0; j < n-1; j++) {
            if (temp[j+1] < temp[j]) return false;
        }

        return true;
    }
};

// Best Approach
// REMEMBER This is a NON DECREASING order
class Solution {
public:
    bool check(vector<int>& nums) {
        
        int count = 0;
        int n = nums.size();

        for (int i=1; i<n; i++) {
            if (nums[i-1] > nums[i]) { //need rotate
                count++;
            }
           
        }

        //check additional cases: 3 4 5 6 1
        if(nums[n-1] > nums[0]) {
                count++;
        }
        return count <= 1;
    }
};