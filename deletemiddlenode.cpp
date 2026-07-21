#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* deleteMiddle(Node* head) {

    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {

        prev = slow;

        slow = slow->next;

        fast = fast->next->next;
    }

    prev->next = slow->next;

    delete slow;

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
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = deleteMiddle(head);

    printList(head);

    return 0;
}