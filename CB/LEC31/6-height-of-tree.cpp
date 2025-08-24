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

    if (val == -1)
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


int findHeightOfTree(TreeNode* root)
{
    // base case
    if(root == NULL)
    {
        return -1;
    }

    // recursive case
    int hl = findHeightOfTree(root->left);
    int hr = findHeightOfTree(root->right);
    return max(hl,hr)+1;
}

int main()
{
    TreeNode *root = NULL;

    root = BuildPreOrderTree();

    cout << endl;

    cout << findHeightOfTree(root);
}

// input:- 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
// output:- 10 30 60 -1 -1 -1 20 50 -1 70 -1 -1 40 -1 -1
