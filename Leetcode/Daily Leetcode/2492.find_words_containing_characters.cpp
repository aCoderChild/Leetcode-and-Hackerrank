class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            if (contains(words[i], x)) result.push_back(i);
        }
        return result;
    }
private:
    bool contains(string word, char x) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == x) return true;
        }
        return false;
    }
};