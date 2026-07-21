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

Node* addTwoLists(Node* head1, Node* head2) {

    Node* dummy = new Node(0);
    Node* temp = dummy;

    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0) {

        int sum = carry;

        if (head1 != NULL) {
            sum += head1->data;
            head1 = head1->next;
        }

        if (head2 != NULL) {
            sum += head2->data;
            head2 = head2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        temp->next = new Node(digit);
        temp = temp->next;
    }

    return dummy->next;
}

void printList(Node* head) {

    while (head != NULL) {
        cout << head->data << " ";

        if (head->next != NULL)
            cout << "-> ";

        head = head->next;
    }
}

int main() {

    // First number: 342
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    // Second number: 465
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    cout << "First List: ";
    printList(head1);

    cout << "\nSecond List: ";
    printList(head2);

    Node* result = addTwoLists(head1, head2);

    cout << "\nResult: ";
    printList(result);

    return 0;
}