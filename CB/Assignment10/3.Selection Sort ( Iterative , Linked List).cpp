//https://hack.codingblocks.com/app/contests/7854/275/problem
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

// Function to perform selection sort on linked list
void selectionSortLinkedList(Node* head) {
    Node* current = head;

    while (current) {
        Node* minNode = current;
        Node* nextNode = current->next;

        // Find the node with minimum value in the remaining list
        while (nextNode) {
            if (nextNode->data < minNode->data) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        // Swap data of current node and minimum node
        if (minNode != current) {
            int temp = current->data;
            current->data = minNode->data;
            minNode->data = temp;
        }

        current = current->next;
    }
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

    selectionSortLinkedList(head);

    printList(head);

    return 0;
}
