#include <iostream>

using namespace std;

int sum = 0;

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

void computePreOrderSum(TreeNode *root)
{
    // base case

    if (root == NULL)
    {
        return;
    }

    // recursive case

    sum += root->val;
    computePreOrderSum(root->left);
    computePreOrderSum(root->right);
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

    computePreOrderSum(root);

    cout << endl;

    cout << sum;
}

// input:- 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
