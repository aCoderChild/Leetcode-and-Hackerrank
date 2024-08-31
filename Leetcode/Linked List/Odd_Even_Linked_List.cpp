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
    ListNode* findTail(ListNode* head) {
        if (head->next->next == NULL) return head;
        ListNode* temp = head;
        while(temp!= NULL && temp->next != NULL && temp->next->next != NULL) {
            temp = temp->next->next;
        }
        return temp;
    }

    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* tail = findTail(head);
        ListNode* evenTail;
        if (tail->next != NULL) evenTail = tail->next;

        ListNode* temp1 = head;
        ListNode* temp2 = tail;

        while (temp1 != tail) {
            ListNode* even = temp1->next;
            temp1->next = temp1->next->next;
            even->next = NULL;
            temp1 = temp1->next;

            temp2->next = even;
            temp2 = temp2->next; 
            
        }

        if(evenTail) {
            temp2->next = evenTail;
        }
        
        return head;
    }
};

// --- Better Approach ---

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenStart = head->next;

        
        //split into 2 parts and then merge 
        while(even!= NULL && even->next != NULL)
        {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenStart;
        return head;
    }
};