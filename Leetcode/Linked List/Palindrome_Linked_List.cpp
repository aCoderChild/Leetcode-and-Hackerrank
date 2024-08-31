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
    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    int length(ListNode* head) {
        if (head == NULL) return 0;
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isPalindrome(ListNode* head) {
        if (head->next == NULL) return true;
        if (head->next->next == NULL) {
            if (head->val == head->next->val) return true;
            else return false;
        }

        int len = length(head);
        ListNode* temp = head;
        for (int i = 0; i < len / 2 - 1; i++) {
            temp = temp->next;
        }
        ListNode* temp1 = temp;
        ListNode* temp2;
        if (len % 2 == 1) temp2 = temp->next->next;
        else temp2 = temp->next;

        temp1->next = NULL;
        temp1 = reverse(head);

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1 != NULL || temp2 != NULL) return false;
        return true;
    }
};

// Time complexity: O(N) (beats 99.20% of the solutions)
// Space Complexity: O(1) (no extra space)
// Overall: good