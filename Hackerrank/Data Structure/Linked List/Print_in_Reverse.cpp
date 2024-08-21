void reversePrint(SinglyLinkedListNode* llist) {
    if (llist == NULL) return;
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* prev = NULL;
    while (current != NULL) {
        SinglyLinkedListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    llist = prev;
    
    SinglyLinkedListNode* toPrint = llist;
    while (toPrint != NULL) {
        cout << toPrint->data << endl;
        toPrint = toPrint->next;
    }
}