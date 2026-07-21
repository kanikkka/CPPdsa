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

Node* sortLL(Node* head) {

    if (head == NULL || head->next == NULL)
        return head;

    Node* first;
    Node* second;

    for (first = head; first != NULL; first = first->next) {

        for (second = first->next; second != NULL; second = second->next) {

            if (first->data > second->data) {
                swap(first->data, second->data);
            }
        }
    }

    return head;
}

void printList(Node* head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {

    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Before Sorting: ";
    printList(head);

    head = sortLL(head);

    cout << "\nAfter Sorting: ";
    printList(head);

    return 0;
}