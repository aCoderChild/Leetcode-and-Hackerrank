bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* turtle = head;
    SinglyLinkedListNode* haare = head;
    if (head == NULL) return false;
    while (turtle && haare && haare->next) {
        turtle = turtle->next;
        haare = haare->next->next;
        if (turtle == haare) return true;
    }
    return false;
}
//Use Floyd Cycle detection algorithm - tortoise and haare