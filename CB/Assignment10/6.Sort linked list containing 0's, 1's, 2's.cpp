//https://hack.codingblocks.com/app/contests/7854/2106/problem
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void sortList(Node* head) {
    if (!head) return;
    
    // Count 0s, 1s, and 2s
    int count[3] = {0, 0, 0};
    Node* curr = head;
    
    while (curr) {
        count[curr->data]++;
        curr = curr->next;
    }
    
    // Modify the linked list based on counts
    curr = head;
    int i = 0;
    
    while (curr) {
        if (count[i] == 0) {
            i++;
        } else {
            curr->data = i;
            count[i]--;
            curr = curr->next;
        }
    }
}

// Alternative approach: Creating three separate lists and merging
void sortListAlternative(Node* head) {
    if (!head) return;
    
    // Create three dummy heads for 0s, 1s, and 2s
    Node* zero = new Node(-1);
    Node* one = new Node(-1);
    Node* two = new Node(-1);
    
    Node* zeroPtr = zero;
    Node* onePtr = one;
    Node* twoPtr = two;
    
    Node* curr = head;
    
    // Single traversal to separate nodes
    while (curr) {
        Node* next = curr->next;
        curr->next = nullptr;
        
        if (curr->data == 0) {
            zeroPtr->next = curr;
            zeroPtr = curr;
        } else if (curr->data == 1) {
            onePtr->next = curr;
            onePtr = curr;
        } else {
            twoPtr->next = curr;
            twoPtr = curr;
        }
        
        curr = next;
    }
    
    // Connect the three lists
    zeroPtr->next = one->next ? one->next : two->next;
    onePtr->next = two->next;
    
    // Update original list
    Node* newHead = zero->next ? zero->next : (one->next ? one->next : two->next);
    Node* temp = head;
    Node* newCurr = newHead;
    
    while (newCurr) {
        temp->data = newCurr->data;
        temp = temp->next;
        newCurr = newCurr->next;
    }
    
    delete zero;
    delete one;
    delete two;
}

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
    
    sortList(head);
    printList(head);
    
    // Clean up memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}