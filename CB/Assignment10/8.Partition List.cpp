//https://hack.codingblocks.com/app/contests/7854/3779/problem

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* partition(ListNode* head, int x) {
    // Create two dummy nodes for two separate lists
    ListNode* less_dummy = new ListNode(0);
    ListNode* greater_dummy = new ListNode(0);
    
    // Pointers to build the two lists
    ListNode* less = less_dummy;
    ListNode* greater = greater_dummy;
    
    // Traverse the original list
    ListNode* current = head;
    while (current != nullptr) {
        if (current->val < x) {
            // Add to less list
            less->next = current;
            less = less->next;
        } else {
            // Add to greater list
            greater->next = current;
            greater = greater->next;
        }
        current = current->next;
    }
    
    // Important: Set the end of greater list to nullptr
    // to avoid cycles
    greater->next = nullptr;
    
    // Connect the two lists
    less->next = greater_dummy->next;
    
    // Save the result head
    ListNode* result = less_dummy->next;
    
    // Clean up dummy nodes
    delete less_dummy;
    delete greater_dummy;
    
    return result;
}

ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

void printLinkedList(ListNode* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n, x;
    cin >> n >> x;
    
    if (n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        ListNode* head = createLinkedList(arr, n);
        ListNode* new_head = partition(head, x);
        printLinkedList(new_head);
    } else {
        cout << endl;
    }
    
    return 0;
}