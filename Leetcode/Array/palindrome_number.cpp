class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        string x1 = num;
        reverse(x1.begin(), x1.end());
        for (int i = 0; i < (int) num.size(); i++) {
            if (num[i] != x1[i]) return false;
        }
        return true;
    }
};

//Analyse: time complexity - linear O(n) - which is good