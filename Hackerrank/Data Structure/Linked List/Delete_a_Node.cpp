SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (position == 0) {
        llist = llist->next;
    }
    
    else {
    SinglyLinkedListNode* current = llist;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    SinglyLinkedListNode* next = current->next->next;
    current->next = next;
    }
    
    return llist;
}