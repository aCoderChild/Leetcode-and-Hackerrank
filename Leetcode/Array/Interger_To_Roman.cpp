class Solution {
    std::map<int, string> mp;
public:
Solution() {
        mp.insert({1, "I"});
        mp.insert({2, "II"});
        mp.insert({3, "III"});
        mp.insert({4, "IV"});
        mp.insert({9, "IX"});
        mp.insert({5, "V"});
        mp.insert({6, "VI"});
        mp.insert({7, "VII"});
        mp.insert({8, "VIII"});
        mp.insert({10, "X"});
        mp.insert({20, "XX"});
        mp.insert({30, "XXX"});
        mp.insert({40, "XL"});
        mp.insert({50, "L"});
        mp.insert({60, "LX"});
        mp.insert({70, "LXX"});
        mp.insert({80, "LXXX"});
        mp.insert({90, "XC"});
        mp.insert({100, "C"});
        mp.insert({200, "CC"});
        mp.insert({300, "CCC"});
        mp.insert({400, "CD"});
        mp.insert({500, "D"});
        mp.insert({600, "DC"});
        mp.insert({700, "DCC"});
        mp.insert({800, "DCCC"});
        mp.insert({900, "CM"});
        mp.insert({1000, "M"});
        mp.insert({2000, "MM"});
        mp.insert({3000, "MMM"});
    }
    int power(int a, int b) {
        int res = 1;
        for (int i = 1; i <= b; i++) {
            res *= a;
        }
        return res;
    }

    string intToRoman(int num) {
        string roman = "";
        int i = 0;
        while (num) {
            int d = num % 10;
            roman = mp[d * power(10, i)] + roman;
            i++;
            num /= 10;
        }

        return roman;
    }
};

//Time Complexity: O(logN) - 38ms - beat only 0.92%
//Space complexity: not need to say - the whole thing is shown in the codes...

//--- SAMPLE SOLUTION ---

class Solution {
public:
    string intToRoman(int num) {
        vector<int> n = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int i = 0; //traverse throught the values of the numbers and the strings.  Like a map!
        string res = "";
        while (num) {
            if (n[i] <= num) {
                res = res + s[i];
                num -= n[i];
            } else {
                i++;
            }
        } 
        return res;
    }
};
// the way you sort the data is VERY IMPORTANT


