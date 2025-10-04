//https://hack.codingblocks.com/app/contests/7854/2402/problem
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseBetween(Node* head, int left, int right) {
    if (!head || left == right) return head;
    
    // Create a dummy node to simplify edge cases
    Node* dummy = new Node(0);
    dummy->next = head;
    
    // Find the node just before the left position
    Node* prev = dummy;
    for (int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }
    
    // Start reversing from the left position
    Node* start = prev->next;
    Node* then = start->next;
    
    // Reverse the nodes between left and right
    for (int i = 0; i < right - left; i++) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }
    
    head = dummy->next;
    delete dummy;
    return head;
}

// Alternative approach - more intuitive
Node* reverseBetweenAlternative(Node* head, int left, int right) {
    if (!head || left == right) return head;
    
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prevLeft = dummy;
    
    // Move to node before left position
    for (int i = 1; i < left; i++) {
        prevLeft = prevLeft->next;
    }
    
    // Reverse the sublist
    Node* curr = prevLeft->next;
    Node* prev = nullptr;
    Node* leftNode = curr;  // Save the left node
    
    // Reverse nodes from left to right
    for (int i = 0; i <= right - left; i++) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Connect the reversed part back
    prevLeft->next = prev;  // Connect to new head of reversed part
    leftNode->next = curr;  // Connect tail of reversed part to remaining list
    
    head = dummy->next;
    delete dummy;
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    int left, right;
    cin >> left >> right;
    
    head = reverseBetween(head, left, right);
    printList(head);
    
    // Clean up memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}