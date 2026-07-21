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

int getLength(Node* head) {

    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

Node* intersectionPoint(Node* head1, Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Move longer list ahead
    if (len1 > len2) {

        int diff = len1 - len2;

        while (diff--) {
            head1 = head1->next;
        }

    } else {

        int diff = len2 - len1;

        while (diff--) {
            head2 = head2->next;
        }
    }

    // Move both together
    while (head1 != NULL && head2 != NULL) {

        if (head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {

    // Common part
    Node* common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);

    // List 1
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = common;

    // List 2
    Node* head2 = new Node(15);
    head2->next = common;

    Node* ans = intersectionPoint(head1, head2);

    if (ans != NULL)
        cout << "Intersection Point: " << ans->data;
    else
        cout << "No Intersection";

    return 0;
}