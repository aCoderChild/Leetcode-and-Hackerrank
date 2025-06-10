class Solution {
public:
    int maxDifference(string s) {
        int count[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            count[s[i]-'a']++;
        }
        int maxOdd = 0, minEven = s.length();
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1 && count[i] > maxOdd) maxOdd = count[i];
            if (count[i] % 2 == 0 && count[i] > 0 && count[i] < minEven) minEven = count[i];
        }
        if (minEven == s.length()) minEven = 0;
        return maxOdd - minEven;
    }
};
// Time Complexity: O(n + 26) = O(n)
// Space Complexity: O(26) = O(1)