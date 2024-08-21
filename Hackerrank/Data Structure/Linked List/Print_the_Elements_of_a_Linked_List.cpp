void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }
}