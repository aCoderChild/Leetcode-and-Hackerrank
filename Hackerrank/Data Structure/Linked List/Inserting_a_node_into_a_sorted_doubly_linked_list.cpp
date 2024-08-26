DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* current = llist;
    DoublyLinkedListNode* toInsert = new DoublyLinkedListNode(data);
    if (llist == NULL) return toInsert;
    DoublyLinkedListNode* prev = NULL;
    if (data < current->data) {
        toInsert->next = current;
        current->prev = toInsert;
        return toInsert;
    }
    
    while (current != NULL) {
        DoublyLinkedListNode* next = current->next;
        if (current->data > data) {
            current->prev = toInsert;
            toInsert->next = current;
            toInsert->prev = prev;
            prev->next = toInsert;
            break;
        }
        prev = current;
        current = next;
    }
    
    if (prev->data <= data) {
        prev->next = toInsert;
        toInsert->prev = prev;
    }
    return llist;
}

//--- Recursive Approach ---
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
    if (llist == NULL) return newNode;
    else if (data <= llist->data) { //has to contain the EQUAL so that not to rule out some cases
        newNode->next = llist;
        llist->prev = newNode;
        return newNode;
    } else {
        DoublyLinkedListNode* rest = sortedInsert(llist->next, data);
        llist->next = rest; //reconnect the first element and the REST, for cases that the newNode is the BEGINNING of the REST
        rest->prev = llist;
        return llist;
    }
}