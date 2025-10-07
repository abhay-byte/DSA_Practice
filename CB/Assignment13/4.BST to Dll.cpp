/*

//https://hack.codingblocks.com/app/contests/7857/1564/problem

Convert a BST to a sorted circular doubly-linked list in-place. Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.
We want to transform this BST into a circular doubly linked list. Each node in a doubly linked list has a predecessor and successor. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.
We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.
Input Format

take input list of BST Node
Constraints

Node
Output Format

print sorted circular doubly-linked list
Sample Input

[4,2,5,1,3]

Sample Output

[1, 2, 3, 4, 5]


*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void bstToCdllHelper(Node* node, Node** headRef, Node** prevRef) {
    if (node == nullptr) {
        return;
    }

    bstToCdllHelper(node->left, headRef, prevRef);

    if (*prevRef == nullptr) {
        *headRef = node;
    } else {
        (*prevRef)->right = node;
        node->left = *prevRef;
    }

    *prevRef = node;

    bstToCdllHelper(node->right, headRef, prevRef);
}

Node* treeToDoublyList(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* head = nullptr;
    Node* prev = nullptr;

    bstToCdllHelper(root, &head, &prev);

    prev->right = head;
    head->left = prev;

    return head;
}

void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "[]" << std::endl;
        return;
    }

    Node* current = head;
    std::cout << "[";
    do {
        std::cout << current->data;
        current = current->right;
        if (current != head) {
            std::cout << ", ";
        }
    } while (current != head);
    std::cout << "]" << std::endl;
}

int main() {

    std::string line;
    std::cin >> line;

    if (line.length() >= 2) {
        line = line.substr(1, line.length() - 2);
    }

    std::replace(line.begin(), line.end(), ',', ' ');

    std::stringstream ss(line);
    int val;
    Node* root = nullptr;

    while (ss >> val) {
        root = insert(root, val);
    }

    Node* headOfList = treeToDoublyList(root);
    printList(headOfList);

    return 0;
}