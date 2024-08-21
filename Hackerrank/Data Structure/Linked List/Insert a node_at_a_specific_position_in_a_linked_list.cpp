SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* toInsert = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* current = llist;
    if (position == 1) {
        toInsert->next = llist;
        return toInsert;
    }
    
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    SinglyLinkedListNode* next = current->next;
    current->next = toInsert;
    toInsert->next = next;
    return llist;
}