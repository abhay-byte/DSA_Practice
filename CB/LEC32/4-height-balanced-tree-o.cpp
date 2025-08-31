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
class Pair{
    public:
    int height;
    bool isBal;
};

Pair checkHeightBalancedOptimized(TreeNode *root)
{
    Pair p;
    //base case
    if(root == NULL)
    {
        p.height = -1;
        p.isBal = true;
        return p;
    }

    //recursive case
    Pair left = checkHeightBalancedOptimized(root->left);
    Pair right = checkHeightBalancedOptimized(root->right);

    bool rootBalanced = abs(left.height - right.height) <= 1; 
    p.height = 1 + max(left.height,right.height);
    p.isBal = left.isBal && right.isBal && rootBalanced;

    return p;
}

int main()
{

    TreeNode *root = NULL;

    root = BuildPreOrderTree();

    Pair p = checkHeightBalancedOptimized(root);
    cout << p.isBal;
}

/*
input:- 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
*/
