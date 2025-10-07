/*

//https://hack.codingblocks.com/app/contests/7856/925/problem

Given a Binary Tree Print all the leaf nodes.
Input Format

Level order input of the binary tree
Constraints

Total no of nodes <1000
Output Format

All leaf nodes from left to right in single line
Sample Input

1
2 3
4 5
6 7
-1 -1
-1 -1
-1 -1
-1 -1

Sample Output

4 5 6 7

*/

#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree() {
    int rootData;
    std::cin >> rootData;
    if (rootData == -1) {
        return nullptr;
    }

    Node* root = new Node(rootData);
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftData, rightData;
        std::cin >> leftData >> rightData;

        if (leftData != -1) {
            current->left = new Node(leftData);
            q.push(current->left);
        }
        if (rightData != -1) {
            current->right = new Node(rightData);
            q.push(current->right);
        }
    }
    return root;
}

void printLeaves(Node* node) {
    if (node == nullptr) {
        return;
    }

    if (node->left == nullptr && node->right == nullptr) {
        std::cout << node->data << " ";
    }
    
    printLeaves(node->left);
    printLeaves(node->right);
}

int main() {

    Node* root = buildTree();
    printLeaves(root);
    std::cout << std::endl;

    return 0;
}