#include <iostream>
using namespace std;

// Node structure for circular linked list
struct CNode {
    int data;
    CNode* next;
};

// Circular Linked List class
class CircularLinkedList {
private:
    CNode* last;  // Points to last node for easy insertion at end

public:
    CircularLinkedList() {
        last = nullptr;
    }

    // Add node at the end
    void add(int value) {
        CNode* newNode = new CNode{value, nullptr};
        if (last == nullptr) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Remove first occurrence of node with given value
    void remove(int value) {
        if (last == nullptr) return;

        CNode* curr = last->next;
        CNode* prev = last;

        do {
            if (curr->data == value) {
                if (curr == last && curr == last->next) {
                    // Only one node
                    delete curr;
                    last = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == last) last = prev;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);
    }

    // Traverse and print the list
    void traverse() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        CNode* temp = last->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(back to start)" << endl;
    }
};

