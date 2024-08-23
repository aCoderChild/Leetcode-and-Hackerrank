SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* current = llist->next;
    SinglyLinkedListNode* prev = llist;
    while (current != NULL) {
        SinglyLinkedListNode* next = current->next;
        if (prev->data == current->data) {
            prev->next = next;
        } else {
            prev = current;
        }
        current = next;
    }
    return llist;
}