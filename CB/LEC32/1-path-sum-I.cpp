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

TreeNode *BuildBFSTree()
{

  
}

bool traverse(TreeNode *node, int sum)
{
    // base case
    if (node == NULL)
    {
        return false;
    }

    if (node->left == NULL && node->right == NULL)
    {
        if (node->val == sum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // recursive case

    bool left = traverse(node->left, sum - node->val);
    bool right = traverse(node->right, sum - node->val);

    return left || right;
}

bool hasPathSum(TreeNode *node, int targetSum)
{
    return traverse(node, targetSum);
}

int main()
{

    TreeNode *root = NULL;

    root = BuildBFSTree();

    int sum = 22;

    cout << hasPathSum(root, sum);
}

/*
input:- 5 4 8 11 -1 13 4 7 2 -1 -1 -1 1
target sum:- 22
*/
