/*

//https://hack.codingblocks.com/app/contests/7856/2120/problem

Given a binary tree, print it's nodes level by level in reverse order, i.e., print all nodes present at the last level first, followed by nodes of the second last level and so on. Print nodes at any level from left to right.
Input Format

Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL
Constraints

The number of nodes in the tree is in the range [1, 1000]
0 <= root->data <= 1000
Output Format

Reverse level order print of the node values.
Sample Input

10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

Sample Output

40 50 60 73 20 30 10 

Explanation

Last level should be printed first, then second last , then third last and so on.

*/

#include <iostream>
#include <string>
#include <queue>
#include <stack>

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

void printReverseLevelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node*> q;
    std::stack<int> s;

    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        s.push(current->data);

        if (current->right != nullptr) {
            q.push(current->right);
        }
        if (current->left != nullptr) {
            q.push(current->left);
        }
    }

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {

    Node* root = buildTree();
    printReverseLevelOrder(root);

    return 0;
}