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

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = nullptr; }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertBefore(int key, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        if (temp == nullptr) return; // key not found

        Node* newNode = new Node(value);
        newNode->next = temp;
        newNode->prev = temp->prev;

        if (temp->prev != nullptr)
            temp->prev->next = newNode;
        else
            head = newNode; // inserting before head

        temp->prev = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);

    cout << "Before insertion: ";
    dll.display();

    dll.insertBefore(10, 5);

    cout << "After inserting 5 before 10: ";
    dll.display();

    dll.insertBefore(20, 15);

    cout << "After inserting 15 before 20: ";
    dll.display();

    return 0;
}
