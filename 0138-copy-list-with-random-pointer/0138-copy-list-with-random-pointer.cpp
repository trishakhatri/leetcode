/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    Node* temp = head;

    // Step 1: insert copy after every original node
    while (temp) {
        Node* copy = new Node(temp->val);

        copy->next = temp->next;
        temp->next = copy;

        temp = copy->next;
    }

    // Step 2: set random pointers
    temp = head;

    while (temp) {
        if (temp->random)
            temp->next->random = temp->random->next;

        temp = temp->next->next;
    }

    // Step 3: separate the two lists
    temp = head;
    Node* newHead = head->next;

    while (temp) {
        Node* copy = temp->next;

        temp->next = copy->next;

        if (copy->next)
            copy->next = copy->next->next;

        temp = temp->next;
    }

    return newHead;
}
};