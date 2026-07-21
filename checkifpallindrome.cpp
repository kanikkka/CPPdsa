#include <iostream>
#include <vector>
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

bool isPalindrome(Node* head) {

    vector<int> arr;

    Node* temp = head;

    while (temp != NULL) {

        arr.push_back(temp->data);

        temp = temp->next;
    }

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {

        if (arr[left] != arr[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    if (isPalindrome(head)) {
        cout << "Palindrome";
    }
    else {
        cout << "Not Palindrome";
    }

    return 0;
}