/*

//https://hack.codingblocks.com/app/contests/7857/3917/problem

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
Input Format

Enter the number of nodes N and add N more numbers to the BST, then add the two numbers whose LCA is to be found.
Constraints

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST
Output Format

Display the LCA value.
Sample Input

4
5
3
2
7
7
5

Sample Output

5

Explanation

None

*/

#include <iostream>

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

Node* findLCA(Node* root, int p, int q) {
    Node* current = root;
    while (current != nullptr) {
        if (p > current->data && q > current->data) {
            current = current->right;
        } else if (p < current->data && q < current->data) {
            current = current->left;
        } else {
            return current;
        }
    }
    return nullptr; 
}

int main() {
    int n;
    std::cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        root = insert(root, val);
    }

    int p, q;
    std::cin >> p >> q;

    Node* lcaNode = findLCA(root, p, q);
    if (lcaNode != nullptr) {
        std::cout << lcaNode->data << std::endl;
    }

    return 0;
}