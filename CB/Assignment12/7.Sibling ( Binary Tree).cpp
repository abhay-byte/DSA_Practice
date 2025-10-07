/*

//https://hack.codingblocks.com/app/contests/7856/918/problem

Given a binary tree print all nodes that don’t have a sibling
Input Format

Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL
Constraints

None
Output Format

Display all the nodes which do not have a sibling in a space separated manner
Sample Input

50 true 12 true 18 false false false false

Sample Output

12 18

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
    int data;
    std::string hasChild;

    if (!(std::cin >> data)) {
        return nullptr;
    }

    Node* root = new Node(data);

    std::cin >> hasChild;
    if (hasChild == "true") {
        root->left = buildTree();
    }

    std::cin >> hasChild;
    if (hasChild == "true") {
        root->right = buildTree();
    }

    return root;
}

void printNodesWithoutSibling(Node* node) {
    if (node == nullptr) {
        return;
    }

    if (node->left != nullptr && node->right == nullptr) {
        std::cout << node->left->data << " ";
    }
    
    if (node->left == nullptr && node->right != nullptr) {
        std::cout << node->right->data << " ";
    }

    printNodesWithoutSibling(node->left);
    printNodesWithoutSibling(node->right);
}

int main() {

    Node* root = buildTree();
    printNodesWithoutSibling(root);
    std::cout << std::endl;

    return 0;
}