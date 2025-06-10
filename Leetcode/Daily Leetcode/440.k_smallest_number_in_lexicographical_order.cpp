// Approach 1: MSD Radix Sort
class Solution {
public:
    int findKthNumber(int n, int k) {
        vector<string> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = to_string(i + 1);
        }
        msdRadixSort(nums, 0, nums.size() - 1, 0);

        return stoi(nums[k - 1]);
    }

private:
    // Function to get character at digit position `d` of string `s`
    int charAt(const string& s, int d) {
        if (d < s.length()) return s[d] - '0';
        return -1; // acts as smaller than '0'
    }

    void msdRadixSort(vector<string>& a, int lo, int hi, int d) {
        if (hi <= lo) return;

        const int R = 10; // radix for digits 0-9
        vector<int> count(R + 2, 0); // count[0] for -1 (end), count[1] for '0', ..., count[10] for '9'
        vector<string> aux(hi - lo + 1);

        // Count frequency
        for (int i = lo; i <= hi; i++) {
            int c = charAt(a[i], d);
            count[c + 2]++;
        }

        // Transform counts to indices
        for (int r = 0; r < R + 1; r++) {
            count[r + 1] += count[r];
        }

        // Distribute
        for (int i = lo; i <= hi; i++) {
            int c = charAt(a[i], d);
            aux[count[c + 1]++] = a[i];
        }

        // Copy back
        for (int i = lo; i <= hi; i++) {
            a[i] = aux[i - lo];
        }

        // Recursively sort for each character
        for (int r = 0; r < R; r++) {
            msdRadixSort(a, lo + count[r], lo + count[r + 1] - 1, d + 1);
        }
    }
};


// Aproach 2: Trie-like Counting
// This approach is based on counting the number of elements in the lexicographical order
// by treating the numbers as a tree structure, where each digit represents a level in the tree.
// The root is 1, and each subsequent digit represents a child node.
// The function `countSteps` counts how many numbers are in the range [curr, next) that are less than or equal to n.
class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k --; // remove the First element
        while (k) {
            int steps = countSteps(n, curr, curr+1);
            if (steps <= k) {
                curr ++; // skip the WHOLE subtree
                k -= steps;
            } else {
                curr *= 10; // go Deeper
                k -= 1;
            }
        }
        return curr;
    }
private:
    int countSteps(int n, long curr, long next) {
        int steps = 0;
        while (curr <= n) {
            steps += min((long)n+1, next) - curr; //n+1: range Exclusive for n
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};