#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* deleteHead(Node* head) {

    if (head == NULL) {
        return NULL;
    }

    Node* temp = head;

    head = head->next;

    delete temp;

    return head;
}

void printList(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Before Deletion: ";
    printList(head);

    head = deleteHead(head);

    cout << "\nAfter Deletion: ";
    printList(head);

    return 0;
}