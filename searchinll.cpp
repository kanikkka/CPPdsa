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

bool searchKey(Node* head, int key) {

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data == key) {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int key;

    cout << "Enter element to search: ";
    cin >> key;

    if (searchKey(head, key)) {
        cout << "Element Found";
    }
    else {
        cout << "Element Not Found";
    }

    return 0;
}