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

TreeNode *BuildBFSTree()
{
}

// time: O(n)
// space: O(h) due to func call stack (h is height of the tree)

vector<vector<int>> paths;

void traverse(TreeNode *node, int sum, vector<int> path)
{
    // base case
    if (node == NULL)
    {
        return;
    }

    if (node->left == NULL && node->right == NULL)
    {
        if (node->val == sum)
        {
            path.push_back(node->val);
            paths.push_back(path);
            path.pop_back();
        }
        else
        {
            return;
        }
    }

    // recursive case
    path.push_back(node->val);
    traverse(node->left, sum - node->val, path);

    traverse(node->right, sum - node->val, path);
    path.pop_back();
    return;
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<int> path;
    traverse(root, targetSum, path);
    return paths;
}

int main()
{

    TreeNode *root = NULL;

    root = BuildBFSTree();

    int sum = 22;

    // cout << hasPathSum(root, sum);
}

/*
input:- 5 4 8 11 -1 13 4 7 2 -1 -1 -1 1
target sum:- 22
*/
