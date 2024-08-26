DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* current = llist;
    DoublyLinkedListNode* prev = NULL;
    while (current != NULL) {
        DoublyLinkedListNode* next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    return prev;
}
//Comment: think simple...