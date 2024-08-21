SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* toInsert = new SinglyLinkedListNode(data);
    
    if (head == NULL) return toInsert;
    else {
        SinglyLinkedListNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = toInsert;
    }    
    return head;
}