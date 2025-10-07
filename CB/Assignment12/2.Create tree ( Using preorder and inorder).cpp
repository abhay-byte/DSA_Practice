/*

//https://hack.codingblocks.com/app/contests/7856/79/problem

You are given two integer arrays preorder and inorder representing the preorder and inorder traversal of a binary tree, respectively. Your task is to reconstruct the binary tree and return its level order traversal.
Input Format

    The first line contains an integer n, the number of nodes in the tree.
    The second line contains n space-separated integers representing the preorder traversal of the tree.
    The third line contains n space-separated integers representing the inorder traversal of the tree.

Constraints

    1 ≤ n ≤ 105
    1 ≤ Node.val ≤ 105

Output Format

Print the level order traversal of the reconstructed binary tree in a single line, with each node value separated by a space.
Sample Input

7
1 2 4 5 3 6 7
4 2 5 1 6 3 7

Sample Output

1 2 3 4 5 6 7

Explanation

Given the following traversals:

    Preorder: [1, 2, 4, 5, 3, 6, 7]
    Inorder: [4, 2, 5, 1, 6, 3, 7]

The binary tree reconstructed from these traversals is:

        1
       / \
      2   3
     / \ / \
    4  5 6  7
    

The level order traversal of this tree is: 1 2 3 4 5 6 7.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(const std::vector<int>& preorder, int& preIndex,
                          std::unordered_map<int, int>& inorderMap, int inStart, int inEnd) {
    if (inStart > inEnd) {
        return nullptr;
    }

    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int inIndex = inorderMap[rootVal];

    root->left = buildTreeHelper(preorder, preIndex, inorderMap, inStart, inIndex - 1);
    root->right = buildTreeHelper(preorder, preIndex, inorderMap, inIndex + 1, inEnd);

    return root;
}

void printLevelOrder(TreeNode* root) {
    if (!root) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        std::cout << current->val << " ";

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> preorder(n);
    std::vector<int> inorder(n);
    std::unordered_map<int, int> inorderMap;

    for (int i = 0; i < n; ++i) {
        std::cin >> preorder[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> inorder[i];
        inorderMap[inorder[i]] = i;
    }

    int preIndex = 0;
    TreeNode* root = buildTreeHelper(preorder, preIndex, inorderMap, 0, n - 1);

    printLevelOrder(root);

    return 0;
}