#include <iostream>

using namespace std;

class TreeNode
{

public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void printPreOrder(TreeNode *root)
{
    // base case

    if(root == NULL)
    {
        cout << -1 << " ";
        return;
    }

    // recursive case

    // print the preOrder of the given tree

    // 1. process the root node

    cout << root->val << " ";

    // 2. print the preOrder of the left Subtree

    printPreOrder(root->left);

    // 3. print the preOrder of the right Subtree

    printPreOrder(root->right);
}

void printInOrder(TreeNode *root)
{
    // base case

    if(root == NULL)
    {
        cout << -1 << " ";
        return;
    }

    // recursive case

    // print the preOrder of the given tree

    // 1. print the preOrder of the left Subtree

    printInOrder(root->left);

    // 2. process the root node

    cout << root->val << " ";

    // 3. print the preOrder of the right Subtree

    printInOrder(root->right);
}

void printPostOrder(TreeNode *root)
{
    // base case

    if(root == NULL)
    {
        cout << -1 << " ";
        return;
    }

    // recursive case

    // print the preOrder of the given tree

    // 1. print the preOrder of the left Subtree

    printPostOrder(root->left);

    // 2. print the preOrder of the right Subtree

    printPostOrder(root->right);

    // 3. process the root node

    cout << root->val << " ";

}

int main()
{
    TreeNode *root = NULL;

    root = new TreeNode(10);

    root->left = new TreeNode(20);

    root->right = new TreeNode(30);

    root->left->left = new TreeNode(40);

    root->left->right = new TreeNode(50);

    root->right->right = new TreeNode(60);

    root->left->right->left = new TreeNode(70);

    printPreOrder(root);

    cout << endl;

    printInOrder(root);

    cout << endl;

    printPostOrder(root);

    cout << endl;
}