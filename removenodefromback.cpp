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

Node* removeNthFromEnd(Node* head, int n) {

    Node* dummy = new Node(0);

    dummy->next = head;

    Node* fast = dummy;
    Node* slow = dummy;

    for (int i = 0; i <= n; i++) {

        if (fast == NULL) {
            return head;
        }

        fast = fast->next;
    }

    while (fast != NULL) {

        slow = slow->next;
        fast = fast->next;
    }

    Node* deleteNode = slow->next;

    slow->next = slow->next->next;

    delete deleteNode;

    return dummy->next;
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

    int n = 2;

    head = removeNthFromEnd(head, n);

    printList(head);

    return 0;
}