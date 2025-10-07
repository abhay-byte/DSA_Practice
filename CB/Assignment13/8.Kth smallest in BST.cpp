/*

//https://hack.codingblocks.com/app/contests/7857/3918/problem

Given the root of a binary search tree, and an integer k, print the kth smallest value (1-indexed) of all the values of the nodes in the tree.
Input Format

First line contains the number of nodes. Next line contains n space separated integers denoting the elements of the BST. Insert them into the BST as given in order. Third line contains a single line integer k
Constraints

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
Output Format

Print the kth smallest value in the BST
Sample Input

6
4 2 3 9 5 1
3

Sample Output

3

Explanation

None

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

void findKthSmallestHelper(Node* node, int k, int& count, int& result) {
    if (node == nullptr || count >= k) {
        return;
    }

    findKthSmallestHelper(node->left, k, count, result);

    if (count < k) {
        count++;
        if (count == k) {
            result = node->data;
            return;
        }
    }

    findKthSmallestHelper(node->right, k, count, result);
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

    int k;
    std::cin >> k;

    int count = 0;
    int result = -1; 
    findKthSmallestHelper(root, k, count, result);

    std::cout << result << std::endl;

    return 0;
}