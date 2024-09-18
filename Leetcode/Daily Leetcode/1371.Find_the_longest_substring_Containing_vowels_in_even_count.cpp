class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> firstOccurence(32, 10e6); //keep track of the first occurence
        firstOccurence[0] = -1; 
        string vowels = "aeiou";
        int currentState = 0, maxLength = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            for (int j = 0; j < 5; j++) {
                if (s[i] == vowels[j]) currentState ^= (1<<j);
            }

            firstOccurence[currentState] = min(firstOccurence[State], i); //update the vector for first occurence state of a state
            maxLength = max(maxLength, i - firstOccurence[i]); 
        }
    }
};
//use bit manipulation and XOR property