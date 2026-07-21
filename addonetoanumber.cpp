#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* reverseList(Node* head) {

    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {

        Node* nextNode = curr->next;

        curr->next = prev;

        prev = curr;
        curr = nextNode;
    }

    return prev;
}

Node* addOne(Node* head) {

    // Reverse list
    head = reverseList(head);

    Node* temp = head;
    Node* prev = NULL;

    int carry = 1;

    while (temp != NULL && carry != 0) {

        int sum = temp->data + carry;

        temp->data = sum % 10;

        carry = sum / 10;

        prev = temp;
        temp = temp->next;
    }

    // If carry remains
    if (carry != 0) {
        prev->next = new Node(carry);
    }

    // Reverse again
    head = reverseList(head);

    return head;
}

void printList(Node* head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);

    cout << "Original Number: ";
    printList(head);

    head = addOne(head);

    cout << "\nAfter Adding 1: ";
    printList(head);

    return 0;
}