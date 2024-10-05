class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        vector<int> ans (n);

        vector<int> temp (n);
        for (int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }
        sort(temp.begin(), temp.end());
        int current = 1;
        for (int i = 0; i < n; i++) {
            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = current;
                current++;
            }
        }

        for (int i = 0; i < n; i++) {
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};