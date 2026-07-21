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

int lengthOfLoop(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {

            int count = 1;

            Node* temp = slow->next;

            while (temp != slow) {

                count++;

                temp = temp->next;
            }

            return count;
        }
    }

    return 0;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Loop 5 -> 3
    head->next->next->next->next->next = head->next->next;

    cout << "Length of Loop: " << lengthOfLoop(head);

    return 0;
}