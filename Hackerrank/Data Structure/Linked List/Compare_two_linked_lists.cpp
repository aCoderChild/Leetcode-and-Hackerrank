bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1 == NULL && head2 == NULL) return true;
    SinglyLinkedListNode* current1 = head1;
    SinglyLinkedListNode* current2 = head2;
    while (current1 != NULL && current2 != NULL) {
        if (current1->data != current2->data) return false;
        current1 = current1->next;
        current2 = current2->next;
    }
    
    if (current1 != NULL || current2 != NULL) return false;
    return true;
}