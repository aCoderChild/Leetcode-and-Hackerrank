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