struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* curr = head;

    // Step 1: Insert copied nodes
    while (curr != NULL) {
        struct Node* copy = malloc(sizeof(struct Node));

        copy->val = curr->val;
        copy->next = curr->next;
        curr->next = copy;

        curr = copy->next;
    }

    // Step 2: Set random pointers
    curr = head;

    while (curr != NULL) {
        struct Node* copy = curr->next;

        if (curr->random != NULL)
            copy->random = curr->random->next;
        else
            copy->random = NULL;

        curr = copy->next;
    }

    // Step 3: Separate lists
    curr = head;
    struct Node* newHead = head->next;

    while (curr != NULL) {
        struct Node* copy = curr->next;

        curr->next = copy->next;

        if (copy->next != NULL)
            copy->next = copy->next->next;
        else
            copy->next = NULL;

        curr = curr->next;
    }

    return newHead;
}
