/*

//https://hack.codingblocks.com/app/contests/7857/1884/problem

Given a BST and an integer k, print the kth largest element in the BST without modifying the BST.

Can you do it in O(n) time ?
Input Format

First line contains the number of nodes. Next line contains n space separated integers denoting the elements of the BST. Insert them into the BST as given in order. Third line contains a single line integer k
Constraints

Output Format

Print the kth largest value in the BST
Sample Input

6
4 2 3 9 5 1
3

Sample Output

4

Explanation

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

void findKthLargestHelper(Node* node, int k, int& count, int& result) {
    if (node == nullptr || count >= k) {
        return;
    }

    findKthLargestHelper(node->right, k, count, result);

    if (count < k) {
        count++;
        if (count == k) {
            result = node->data;
            return;
        }
    }

    findKthLargestHelper(node->left, k, count, result);
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
    findKthLargestHelper(root, k, count, result);

    std::cout << result << std::endl;

    return 0;
}