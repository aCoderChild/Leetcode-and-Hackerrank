/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* t = head;
        ListNode* h = head;
        while (t != NULL && h != NULL && h->next != NULL) {
            t = t->next;
            h = h->next->next;
            if (t == h) break;
        }
        if (h == NULL || h->next == NULL) return NULL;
        t = head;
        while (t != h) {
            t = t->next;
            h = h->next;
        }
        return t;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
// haare and tortoise method - Floyd cycle