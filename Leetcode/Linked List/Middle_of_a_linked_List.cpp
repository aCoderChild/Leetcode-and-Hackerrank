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
    int count(ListNode* head) {
        int res = 0;
        ListNode* current = head;
        while (current != NULL) {
            res++;
            current = current->next;
        }
        return res;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;
        for (int i = 0; i < count(head) / 2; i++) {
            current = current->next;
        }
        return current;
    }
};

//easy