/*

//https://hack.codingblocks.com/app/contests/7857/239/problem

Given a tree and a node of tree, print all nodes which are at distance k from the given node.
Input Format

Enter the number of nodes N and add N more numbers to the BST. Then enter the target number and value of k.
Constraints

None
Output Format

Display all the nodes which are at a distance k in a new line
Sample Input

4
1
2
3
4
4
2

Sample Output

2

*/

#include <iostream>
#include <vector>

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

void printNodesAtDepthK(Node* node, int k) {
    if (node == nullptr || k < 0) {
        return;
    }
    if (k == 0) {
        std::cout << node->data << std::endl;
        return;
    }
    printNodesAtDepthK(node->left, k - 1);
    printNodesAtDepthK(node->right, k - 1);
}

int findKDistanceNodes(Node* node, int target, int k) {
    if (node == nullptr) {
        return -1;
    }

    if (node->data == target) {
        printNodesAtDepthK(node, k);
        return 0;
    }

    int leftDist = findKDistanceNodes(node->left, target, k);
    if (leftDist != -1) {
        int currentDist = leftDist + 1;
        if (currentDist == k) {
            std::cout << node->data << std::endl;
        } else {
            printNodesAtDepthK(node->right, k - currentDist - 1);
        }
        return currentDist;
    }

    int rightDist = findKDistanceNodes(node->right, target, k);
    if (rightDist != -1) {
        int currentDist = rightDist + 1;
        if (currentDist == k) {
            std::cout << node->data << std::endl;
        } else {
            printNodesAtDepthK(node->left, k - currentDist - 1);
        }
        return currentDist;
    }

    return -1;
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

    int target, k;
    std::cin >> target >> k;

    findKDistanceNodes(root, target, k);

    return 0;
}