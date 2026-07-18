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

int main() {

    // Creating nodes
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Connecting nodes
    first->next = second;
    second->next = third;

    // Head points to first node
    Node* head = first;

    // Printing Linked List
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}