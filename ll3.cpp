// insert at tail of linked list


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insert_at_Tail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    cout << "Initial List: ";
    print(head);

    insert_at_Tail(tail, 12);
    cout << "After Inserting 12: ";
    print(head); // Always print from head

    return 0;
}