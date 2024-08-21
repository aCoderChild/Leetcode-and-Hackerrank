SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* prev = NULL;
    while (current != NULL) {
        SinglyLinkedListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    llist = prev;
    return llist;
}