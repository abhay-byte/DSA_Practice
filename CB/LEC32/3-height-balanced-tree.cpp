#include <iostream>
#include <vector>

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

//time: O(n^2)
//space: O(h)

bool checkHeightBalanced(TreeNode *root)
{
    //base case
    if(root == NULL)
    {
        return true;
    }

    //recursive case
    bool left = checkHeightBalanced(root->left);
    bool right = checkHeightBalanced(root->right);

    int leftHeight = findHeightOfTree(root->left);
    int rightHeight = findHeightOfTree(root->right);

    bool rootBalanced = abs(leftHeight - rightHeight) <= 1; 

    return left && right && rootBalanced;
}

int main()
{

    TreeNode *root = NULL;

    root = BuildPreOrderTree();

    cout << checkHeightBalanced(root);
}

/*
input:- 10 20 40 -1 -1 50 70 -1 -1 -1 30 60 -1 -1
*/
