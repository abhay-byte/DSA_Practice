/*
//https://hack.codingblocks.com/app/contests/7856/74/problem

Given two trees check if they are structurally identically. Structurally identical trees are trees that have same structure. They may or may not have the same data though.
Input Format

Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL
Constraints

1 <= N <= 10^4
Output Format

Display the Boolean result
Sample Input

10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

Sample Output

true

Explanation

The given two trees have the exact same structure and hence we print true.

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

bool areStructurallyIdentical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    return areStructurallyIdentical(root1->left, root2->left) &&
           areStructurallyIdentical(root1->right, root2->right);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Node* tree1 = buildTree();
    Node* tree2 = buildTree();

    std::cout << std::boolalpha << areStructurallyIdentical(tree1, tree2) << std::endl;

    return 0;
}