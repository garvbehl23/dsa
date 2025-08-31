#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        // Agar next NULL hai toh bhi safe deletion
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data: " << this->data << endl;
    }
};

// Head mein insert karta hai
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Tail mein insert karta hai
void insert_at_Tail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Kisi bhi position par insert karta hai
void insertAtPosition(Node*& tail, Node*& head, int position, int d) {
    if (position < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds. Inserting at the end." << endl;
        insert_at_Tail(tail, d);
        return;
    }

    if (temp->next == NULL) {
        insert_at_Tail(tail, d);
        return;
    }

    Node* nodetoInsert = new Node(d);
    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;
}

// Kisi bhi position par node delete karti hai
void deleteNode(int position, Node* &head) {
    if (head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (position < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    // Agar pehla node delete karni hai
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;  // Safely detach
        delete temp;        // Delete old head
        return;
    }

    // Any other node delete karna
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    while (cnt < position && curr != NULL) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL) {
        cout << "Position out of bounds. Cannot delete." << endl;
        return;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

// List print karta hai
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

    insertAtHead(head, 12);
    cout << "After inserting 12 at head: ";
    print(head);

    insert_at_Tail(tail, 22);
    cout << "After inserting 22 at tail: ";
    print(head);

    insertAtPosition(tail, head, 2, 21);
    cout << "After inserting 21 at position 2: ";
    print(head);

    insertAtPosition(tail, head, 5, 30); // Beyond current size
    cout << "After inserting 30 at position 5: ";
    print(head);

    cout << "Deleting node at position 1: ";
    deleteNode(1, head);
    print(head);

    cout << "Deleting node at position 4: ";
    deleteNode(4, head);
    print(head);

    cout << "Deleting node at position 3: ";
    deleteNode(3, head);
    print(head);

    return 0;
}
