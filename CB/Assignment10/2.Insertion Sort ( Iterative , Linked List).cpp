//https://hack.codingblocks.com/app/contests/7854/166/problem

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Function to perform iterative insertion sort
Node* insertionSortLinkedList(Node* head) {
    if (!head || !head->next)
        return head;

    Node* sorted = nullptr; // Start with an empty sorted list

    Node* current = head;
    while (current) {
        Node* nextNode = current->next;

        // Insert current in sorted list
        if (!sorted || current->data < sorted->data) {
            // Insert at beginning
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    return sorted;
}

// Function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertEnd(head, val);
    }

    head = insertionSortLinkedList(head);

    printList(head);

    return 0;
}
