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

TreeNode *BuildPreOrderTree()
{

    int val;
    cin >> val;

    if(val == -1)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(val);

    // ask your friend to build the left subtree

    root->left = BuildPreOrderTree();

    // ask you friend to build the right subtree

    root->right = BuildPreOrderTree();

    return root;
}

void printPreOrder(TreeNode *root)
{
    // base case

    if (root == NULL)
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

int main()
{
    TreeNode *root = NULL;

    root = BuildPreOrderTree();

    printPreOrder(root);
}

//input:- 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1 
