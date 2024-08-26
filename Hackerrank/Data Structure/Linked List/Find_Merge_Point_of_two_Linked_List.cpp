SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* prev = NULL;
    while(current != NULL) {
        SinglyLinkedListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;    
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* current1 = reverse(head1);
    SinglyLinkedListNode* current2 = reverse(head2);

    int toFind;
    while (current1 != current2) {
        toFind = current1->data;
        current1 = current1->next;
        current2 = current2->next;
    }
    return toFind;
}
//Comment: wrong Approach

//--- Solution ---
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* current1 = head1;
    SinglyLinkedListNode* current2 = head2;
    while(current1 != current2) {
        if (current1 == NULL) {
            current1 = head2;
        } else {
            current1 = current1->next;
        }
        
        if (current2 == NULL) {
            current2 = head1;
        } else {
            current2 = current2->next;
        }
    }
    return current1->data;
}
//Comment: using 2 pointers and assign on both the lists => it will set the pointers to both the same length to the first Merge Point !!!
// Genius...