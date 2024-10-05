/*
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        for (int i = 0; i <= (s2.length() - s1.length()); i++) {
            int ans = 0;
            for (int j = 0; j < s1.length(); j++) {
                int charToNum_s1 = (int) (s1[j] - 'a');
                int charToNum_s2 = (int) (s2[j+i] - 'a');
                ans = ans ^ charToNum_s1 ^ charToNum_s2;
            }
            if (ans == 0) return true;
        }
        return false;
    }
};
*/

//Analysis: time complexity - pretty good O((N2-N1)*N1)
//There still contains problems - 94/108 cases passed

//Another approach: Sliding window
#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
        vector<int> s1Hash(26, 0);
        int s1Len = s1.size();
        int s2Len = s2.size();
        if (s1Len > s2Len) return false;

        for (int i = 0; i < s1Len; i++) {
            int c = (int) (s1[i] - 'a');
            s1Hash[c]++;
        }

        int id = 0;
        while(id + s1Len <= s2Len) {
            vector<int> s2Hash(26, 0);
            for (int i = id; i < (id+s1Len); i++) {
                int c = (int) (s2[i] - 'a');
                s2Hash[c]++;
            }

            /*
            for (int i = 0; i < 26; i++) {
                cout << s2Hash[i] << " ";
            }
            cout << endl;
            */

            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (s1Hash[i] != s2Hash[i]) {
                    //cout << "id number: " << id << endl;
                    id++;

                    flag = false;
                    //cout << "At this index it is false" << endl;
                    break;
                }
            }
            if(flag) return true;
        }

        return false;
}

int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    cout << (checkInclusion(s1, s2) ? "YES" : "NO") << endl;
    return 0;
}

//Optimal Approach
class Solution {
public:
    //check if the array is full of 0s
 bool allZero(int *arr){
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
    }

    //s1:+, s2:-
    //true: if(allZero)
    bool checkInclusion(string s1, string s2) {
         if(s2.length()<s1.length()){
            return false;
        }
        int arr[26] = {0};
        for(int i=0;i<s1.length();i++){
            arr[s1[i]-'a']++;
        }
        int len = s1.length();
        for(int i=0;i<s2.length();i++){
            arr[s2[i]-'a']--;
            if(i-len>=0){
               arr[s2[i-len]-'a']++;
            }
            if(allZero(arr)) {
                return true;
            }
        }
        return false;
    }
};
