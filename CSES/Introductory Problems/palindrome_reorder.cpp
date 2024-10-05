/*
#include <iostream>
#include <string>
#include <algorithm>

const int ALPHABET_SIZE = 26;

//put it in the array
void countLetterFrequencies(const std::string& inputString, int alphabet[]) {
    for (char c : inputString) {
        alphabet[c - 'A']++;
    }
}

//check Palindrome
bool checkPalindromePossibility(const int alphabet[], int stringLength) {
    int oddCount = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (alphabet[i] % 2 == 1) {
            oddCount++;
        }
    }
    return oddCount <= 1 && (stringLength % 2 == 1 || oddCount == 0);
}

std::string constructPalindrome(const int alphabet[], const std::string& inputString) {
    std::string ans;
    char oddChar;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char c = 'A' + i;
        int count = alphabet[i];
        while (count >= 2) {
        	ans += c;
        	count -= 2;
        } if (count == 1){
        	oddChar = c;
        }
    }

    std::string reverseAns = ans;
    std::reverse(reverseAns.begin(), reverseAns.end());
    ans = ans + oddChar + reverseAns;
    return ans;
}

int main() {
    std::string inputString;
    std::cin >> inputString;
    int stringLength = inputString.length();
    int alphabet[ALPHABET_SIZE] = {0};

    countLetterFrequencies(inputString, alphabet);

    if (!checkPalindromePossibility(alphabet, stringLength)) {
        std::cout << "NO SOLUTION" << std::endl;
        return 0;
    }

    std::string palindrome = constructPalindrome(alphabet, inputString);
    std::cout << palindrome << std::endl;

    return 0;
}
*/

/*
5. Code Organization

The code is a bit dense and could be organized better. Consider breaking it down into separate functions, like countLetterFrequencies, checkPalindromePossibility, and constructPalindrome.

6. Error Handling

The code doesn't handle errors well. Consider adding error checking for cases like invalid input or unexpected errors.

7. Code Style

The code uses inconsistent spacing and indentation. Consider using a consistent coding style throughout the code.

Here's an updated version of your code with these suggestions in mind:
*/

//Achtung: code in small functional functions

#include <bits/stdc++.h>
using namespace std;

// function to construct a palindromic string
string solve(string S)
{
    int N = S.length();
    string ans(N, ' ');

    // frequency array to count the occurrence of each
    // character
    int freq[26] = {};
    for (int i = 0; i < N; i++) {
        freq[S[i] - 'A'] += 1;
    }

    // Count the number of character having odd frequency
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            cnt += 1;
        }
    }

    // If more than one characters have odd frequency, then
    // no solution exists
    if (cnt > 1)
        return "NO SOLUTION";

    //create a fixed - length vector in string format
    int left = 0, right = N - 1;
    for (int i = 0; i < N; i++) {
        if (freq[S[i] - 'A'] % 2 == 1) {
            ans[N / 2] = S[i];
            freq[S[i] - 'A'] -= 1;
        }
        while (freq[S[i] - 'A'] > 0) {
            ans[left++] = ans[right--] = S[i];
            freq[S[i] - 'A'] -= 2;
        }
    }
    return ans;
}

int main()
{
    // Sample Input
    string s;
    cin >> s;
    string ans = solve(s);
    cout << ans << endl;
    return 0;
}