class Solution {
public:
    int commonPrefix(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        int ans = 0;
        if (sa.size() > sb.size()) swap(sa, sb);
        for (int i = 0; i < (int) sa.size(); i++) {
            if (sa[i] == sb[i]) ans++;
            else break;
        }
        return ans; 
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int current = 0, maxPair = 0;
        for (int i = 0; i < (int) arr1.size(); i++) {
            for (int j = 0; j < (int) arr2.size(); j++) {
                current = commonPrefix(arr1[i], arr2[j]);
                maxPair = max(maxPair, current);
            }
        }
        return maxPair;
    }
};
//Test case passed: 694/718 cases
//Type of error: time limit exceeded
//naive approach

//Another approach: XOR bit operation => largest XOR is answer but still the time complexity be O(N^2)
