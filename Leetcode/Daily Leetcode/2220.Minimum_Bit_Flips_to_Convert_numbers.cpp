class Solution {
public:
    string toBinary(int x) {
        string res = "";
        while (x) {
            int d = x % 2;
            res = to_string(d) + res;
            x /= 2;
        }
        return res;
    }

    int minBitFlips(int start, int goal) {
        string startBinary = toBinary(start);
        string goalBinary = toBinary(goal);
        int slen = (int) startBinary.size();
        int glen = (int) goalBinary.size();

        if (glen < slen) {
            swap(startBinary, goalBinary);
            swap(slen, glen);
        }
        while (slen != glen) {
            startBinary = "0" + startBinary;
            slen++;
        }

        int res = 0;
        for (int i = 0; i < slen; i++) {
            if (startBinary[i] != goalBinary[i]) res++;
        }
        return res;
    }
};

//time complexity: O(Log(Start) + Log(Goal))

//--- Better Approach ---
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        while (start > 0 || goal > 0) {
            if ((start & 1) != (goal & 1)) {
                count++;
            }
            start >>= 1;
            goal >>= 1;
        }
        return count;
    }
};
//bit approach
//time complexity: O(maxbit)