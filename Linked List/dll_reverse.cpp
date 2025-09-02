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

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            // swap prev and next
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            // move to next node (which is prev now)
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev; // new head is last processed node
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    cout << "Original List: ";
    dll.display();

    dll.reverse();

    cout << "Reversed List: ";
    dll.display();

    return 0;
}
