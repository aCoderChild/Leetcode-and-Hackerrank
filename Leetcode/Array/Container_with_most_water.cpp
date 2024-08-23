//-----Naive Approach-----
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int) height.size();
        vector<pair<int, int>> temp;
        for (int i = 0;i < n; i++) {
            temp.push_back({height[i], i});
        }

        sort(temp.begin(), temp.end());
        int maximum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int current = temp[i].first * ((abs(temp[i].second - temp[j].second)));
                if (current > maximum) maximum = current;
            }
        }
        return maximum;
    }
};
//Analyse:
// Time Complexity: O(n^2)
// Space Complexity: O(1)

//-----Use 2 pointers-----
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int) height.size();
        int left = 0, right = n - 1;
        int length = n - 1;
        int maximum = 0;
        while (left < right) {
            int current = (min(height[left], height[right])) * length;
            if (current > maximum) maximum = current;
            if (height[left] <= height[right]) {
                left++;
                length--;
            } else {
                right--;
                length--;
            }
        }
        return maximum;
    }
};
//Analysis:
// Time Complexity: O(n)
// Space Complexity: O(1)

//Algorithm idea: 2 pointers pointing the 2 edges of the array. Keeps the pointers pointing to the higher value (ALWAYS)
