//https://hack.codingblocks.com/app/contests/7854/505/problem
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int findIntersection(Node* head1, Node* head2) {
    if (!head1 || !head2) return -1;
    
    // Calculate lengths of both lists
    int len1 = 0, len2 = 0;
    Node* p1 = head1;
    Node* p2 = head2;
    
    while (p1) {
        len1++;
        p1 = p1->next;
    }
    
    while (p2) {
        len2++;
        p2 = p2->next;
    }
    
    // Reset pointers to heads
    p1 = head1;
    p2 = head2;
    
    // Advance the pointer of longer list by the difference
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff-- > 0) {
            p1 = p1->next;
        }
    } else {
        while (diff-- > 0) {
            p2 = p2->next;
        }
    }
    
    // Move both pointers together until they meet
    while (p1 && p2) {
        if (p1 == p2) {
            return p1->data;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return -1;
}

int main() {
    int n1;
    cin >> n1;
    
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    Node* nodes[n1];
    
    for (int i = 0; i < n1; i++) {
        int val;
        cin >> val;
        nodes[i] = new Node(val);
        
        if (!head1) {
            head1 = tail1 = nodes[i];
        } else {
            tail1->next = nodes[i];
            tail1 = nodes[i];
        }
    }
    
    int n2;
    cin >> n2;
    
    Node* head2 = nullptr;
    Node* tail2 = nullptr;
    
    for (int i = 0; i < n2; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        
        if (!head2) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    
    int x1, x2;
    cin >> x1 >> x2;
    
    // Create intersection if x1 and x2 are valid
    if (x1 > 0 && x1 <= n1 && x2 > 0) {
        // Connect list2 to the intersection point in list1
        Node* intersectionNode = nodes[x1 - 1];
        if (tail2) {
            tail2->next = intersectionNode;
        }
    }
    
    cout << findIntersection(head1, head2) << endl;
    
    return 0;
}