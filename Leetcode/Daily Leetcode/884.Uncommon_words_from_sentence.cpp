#include <bits/stdc++.h>
using namespace std;

// ACHTUNG!
vector<string> word_from_string (string s) {
    vector<string> res;
    string word;
    for (char c : s) {
        if (c == ' ') {
            if (!word.empty()) {
                res.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        res.push_back(word);
    }

    return res;
}

/*
bool check_word (string word1, string word2) {
    if (word1.size() != word2.size()) return false;
    for (int i = 0; i < word1.size(); i++) {
        if (word1[i] != word2[i]) return false;
    }
    return true;
}
*/

//wrong--
/*
vector<string> unique (string s) {
    vector<string> words = word_from_string(s);
    vector<string> res;
    map<string, int> mp;
    for (auto i : words) {
        mp[i]++;
    }
    for (auto i : words) {
        if ( mp[i] == 1) res.push_back(i);
    }

    //print the word vector
    cout << "the words retrieved from string: ";
    for (auto i : res) {
        cout << i << " ";
    }

    return res;
}
*/

vector<string> uncommonFromSentences(string s1, string s2) {
    vector<string> words1 = word_from_string (s1);
    vector<string> words2 = word_from_string (s2);
    vector<string> res;

    map<string, int> mp;
    for (auto i : words1) {
        mp[i]++;
    }
    for (auto i : words2) {
        mp[i]++;
    }

    for(auto i : mp) {
        if (i.second == 1) res.push_back(i.first);
    }
    return res;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<string> ans = uncommonFromSentences(s1, s2);
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}