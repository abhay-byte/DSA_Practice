/*

//https://hack.codingblocks.com/app/contests/7856/451/problem

Given a binary tree, remove all the leaves from the tree
Input Format

Enter the value of the nodes of the tree
Constraints

None
Output Format

Display the tree in which all the leaves have been removed in pre-order traversal in the following format :
Left->data => Root->data <= Right->Data
Output END if left or right node is NULL
Sample Input

50 true 12 true 18 false false false false

Sample Output

12 => 50 <= END
END => 12 <= END

*/

#include <iostream>
#include <string>

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

Node* removeLeaves(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
    }

    node->left = removeLeaves(node->left);
    node->right = removeLeaves(node->right);

    return node;
}

void displayPreOrder(Node* node) {
    if (node == nullptr) {
        return;
    }

    std::string leftStr = "END";
    if (node->left != nullptr) {
        leftStr = std::to_string(node->left->data);
    }

    std::string rightStr = "END";
    if (node->right != nullptr) {
        rightStr = std::to_string(node->right->data);
    }

    std::cout << leftStr << " => " << node->data << " <= " << rightStr << std::endl;

    displayPreOrder(node->left);
    displayPreOrder(node->right);
}

int main() {

    Node* root = buildTree();
    root = removeLeaves(root);
    displayPreOrder(root);

    return 0;
}