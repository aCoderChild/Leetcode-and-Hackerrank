SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* toInsert = new SinglyLinkedListNode (data);
    if (llist == NULL) return toInsert;
    toInsert->next = llist;
    return toInsert;
}