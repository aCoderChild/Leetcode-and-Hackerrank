int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* prev = NULL;
    while (current != NULL) {
        SinglyLinkedListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    llist = prev;
    
    SinglyLinkedListNode* temp = llist;
    for (int i = 0; i < positionFromTail; i++) {
        temp = temp->next;
    }
    return temp->data;
}