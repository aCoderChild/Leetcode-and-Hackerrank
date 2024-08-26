class Solution {
public:
    map<char, int> mp;
    Solution() {
        mp.insert({'I', 1});
        mp.insert({'V', 5});
        mp.insert({'X', 10});
        mp.insert({'L', 50});
        mp.insert({'C', 100});
        mp.insert({'D', 500});
        mp.insert({'M', 1000});
    }
    int romanToInt(string s) {
        int n = (int) s.size();
        int num = mp[s[n-1]];
        for (int i = n-2; i >= 0; i--) {
            if (mp[s[i]] < mp[s[i+1]]) num -= mp[s[i]];
            else num += mp[s[i]];
        }
        return num;
    }
};

//Analyse: 
// Time Complexity: O(n)
// Space Complexity: O(n) - worst case

//--- Another interesting approach ---
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int sum = 0;
        for(int i = 0; i < n;){
            if(s[i] == 'I' && s[i + 1] == 'V'){
                sum += 4;
                i += 2;
            }
            else if(s[i] == 'I' && s[i + 1] == 'X'){
                sum += 9;
                i += 2;
            }
            else if(s[i] == 'X' && s[i + 1] == 'L'){
                sum += 40;
                i += 2;
            }
            else if(s[i] == 'X' && s[i + 1] == 'C'){
                sum += 90;
                i += 2;
            }
            else if(s[i] == 'C' && s[i + 1] == 'D'){
                sum += 400;
                i += 2;
            }
            else if(s[i] == 'C' && s[i + 1] == 'M'){
                sum += 900;
                i += 2;
            }
            else if(s[i] == 'I'){
                sum += 1;
                i++;
            }
            else if(s[i] == 'V'){
                sum += 5;
                i++;
            }
            else if(s[i] == 'X'){
                sum += 10;
                i++;
            }
            else if(s[i] == 'L'){
                sum += 50;
                i++;
            }
            else if(s[i] == 'C'){
                sum += 100;
                i++;
            }
            else if(s[i] == 'D'){
                sum += 500;
                i++;
            }
            else if(s[i] == 'M'){
                sum += 1000;
                i++;
            }
        }
        return sum;
    }
};