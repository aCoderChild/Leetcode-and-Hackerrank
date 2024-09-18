//prefix sum
#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int> nums) {
        int max = nums[0];
        for (auto i : nums) {
            if (i > max) max = i;
        }
        return max;
    }

int longestSubarray(vector<int>& nums) { 
    int maxArr = findMax(nums);
    int maxLength = 0, currentLength = 0; //have this

    for (int i = 0; i < (int) nums.size(); i++) {
        if (nums[i] == maxArr) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } else {
            currentLength = 0;
        }
    }
    return maxLength;
}
//technique to find the longest subarray of the largest number

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	cout << longestSubarray(nums);
	return 0;
}

// Time Complexity: O(N)
// Bit AND wise operation property: the result of the bitwise operation of 2 numbers are strictly LESSER than the maximum of the 2 numbers
// The most important feature: figure out the nature of the longest sequence should be

// --- Another way of coding---
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, ans = 0, currentStreak = 0;

        for (int num : nums) {
            if (maxVal < num) {
                maxVal = num;
                ans = currentStreak = 0; //new max values initialise
            }

            if (maxVal == num) {
                currentStreak++;
            } else {
                currentStreak = 0;
            }

            ans = max(ans, currentStreak);
        }
        return ans;
    }
};