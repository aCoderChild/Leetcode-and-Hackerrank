class Solution {
public:
    bool isAppear (string allowed, char c) {
        for (int i = 0; i < (int) allowed.size(); i++) {
            if (allowed[i] == c) return true;
        }
        return false;
    }

    bool isConsistent (string allowed, string word) {
        for (int i = 0; i < (int) word.size(); i++) {
            if (!isAppear(allowed, word[i])) return false;
        }
        return true;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for (auto word : words) {
            if (isConsistent(allowed, word)) count++;
        }
        return count;
    }
};

//---different Approach---
class Solution {
public:
    void isAllowed (string allowed, vector<int>& ab) {
        for (auto c : allowed) {
            ab[(int) (c - 'a')] = 1;
        }
    }

    bool isConsistent(string allowed, string word, vector<int> ab) {
        for (auto c : word) {
            if (ab[(int) c - 'a'] != 1) return false;
        }
        return true;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> ab(26, 0);
        isAllowed(allowed, ab);
        int count = 0;
        for (auto word : words) {
            if (isConsistent(allowed, word, ab)) count++;
        }
        return count;
    }
};
// create an array for storing the characters
// more optimal than the first approach
