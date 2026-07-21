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

Node* sort012(Node* head) {

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node* temp = head;

    // Count 0, 1 and 2
    while (temp != NULL) {

        if (temp->data == 0)
            count0++;

        else if (temp->data == 1)
            count1++;

        else
            count2++;

        temp = temp->next;
    }

    temp = head;

    // Put 0s
    while (count0 > 0) {
        temp->data = 0;
        temp = temp->next;
        count0--;
    }

    // Put 1s
    while (count1 > 0) {
        temp->data = 1;
        temp = temp->next;
        count1--;
    }

    // Put 2s
    while (count2 > 0) {
        temp->data = 2;
        temp = temp->next;
        count2--;
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

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);

    cout << "Before Sorting: ";
    printList(head);

    head = sort012(head);

    cout << "\nAfter Sorting: ";
    printList(head);

    return 0;
}