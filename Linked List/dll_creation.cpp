#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

int main() {
    // Create 3 nodes manually
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Linking
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Traverse forward
    Node* temp = head;
    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
