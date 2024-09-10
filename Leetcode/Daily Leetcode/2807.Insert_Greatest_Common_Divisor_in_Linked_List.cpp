/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int GCD(int a, int b) {
        if (a < b) swap(a, b);
        if (b == 0) return a;
        else return GCD(b, a % b); 
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        while (current->next != NULL) {
            ListNode* next = current->next;
            int a = current->val;
            int b = next->val;
            int c = GCD(a, b);
            ListNode* toInsert = new ListNode(c);
            current->next = toInsert;
            toInsert->next = next;
            current = next;
        }
        return head;
    }
};

//Time Complexity: O(N)