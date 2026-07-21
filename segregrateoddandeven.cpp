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

Node* segregateEvenOdd(Node* head) {

    if (head == NULL) {
        return head;
    }

    Node* evenStart = NULL;
    Node* evenEnd = NULL;

    Node* oddStart = NULL;
    Node* oddEnd = NULL;

    Node* curr = head;

    while (curr != NULL) {

        if (curr->data % 2 == 0) {

            if (evenStart == NULL) {

                evenStart = curr;
                evenEnd = curr;
            }
            else {

                evenEnd->next = curr;
                evenEnd = curr;
            }
        }

        else {

            if (oddStart == NULL) {

                oddStart = curr;
                oddEnd = curr;
            }
            else {

                oddEnd->next = curr;
                oddEnd = curr;
            }
        }

        curr = curr->next;
    }

    if (evenStart == NULL || oddStart == NULL) {
        return head;
    }

    evenEnd->next = oddStart;

    oddEnd->next = NULL;

    return evenStart;
}

void printList(Node* head) {

    while (head != NULL) {

        cout << head->data << " ";

        head = head->next;
    }
}

int main() {

    Node* head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(4);

    head = segregateEvenOdd(head);

    printList(head);

    return 0;
}