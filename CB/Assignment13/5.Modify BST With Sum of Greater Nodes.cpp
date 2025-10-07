/*
//https://hack.codingblocks.com/app/contests/7857/1601/problem

Given a BST, you have to modify it so that value at each node is equal to sum of values of nodes in original BST which are greater than or equal to the original value of current node.
Input Format

Single line containing Preorder input for BST.
-1 represents node doesn't exist.
Constraints

1<=No. of nodes<=100
0<=Node value<=100
Output Format

Print Preorder traversal of the modified BST.
Sample Input

8 3 -1 -1 35 -1 52 -1 92 72 67 -1 -1 -1 97 -1 -1 

Sample Output

423 426 415 380 189 261 328 97 

Explanation

None

*/

#include <iostream>
#include <string>
#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree() {
    int val;
    std::cin >> val;

    if (val == -1) {
        return nullptr;
    }

    Node* node = new Node(val);
    node->left = buildTree();
    node->right = buildTree();
    return node;
}

void modifyBstHelper(Node* node, int& sum) {
    if (node == nullptr) {
        return;
    }

    modifyBstHelper(node->right, sum);
    
    sum += node->data;
    node->data = sum;
    
    modifyBstHelper(node->left, sum);
}

void printPreOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

int main() {

    Node* root = buildTree();
    
    int sum = 0;
    modifyBstHelper(root, sum);
    
    printPreOrder(root);
    std::cout << std::endl;

    return 0;
}
