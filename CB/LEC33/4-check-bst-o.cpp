#include <iostream>
#include <queue>
#include <climits>
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

int findMin(TreeNode* root)
{
    if(root == NULL)
    {
        return INT_MAX;
    }

    TreeNode* node = root;

    while(node->left != NULL)
    {
        node = node->left;
    }

    return node->val;
}

int findMax(TreeNode* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }

    TreeNode* node = root;

    while(node->right != NULL)
    {
        node = node->right;
    }

    return node->val;
}

bool checkBST(TreeNode* root)
{
    //base case
    if(root == NULL)
    {
        return true;
    }

    //recursive case
    bool left = checkBST(root->left);
    bool right = checkBST(root->right);

    bool rootBal = root->val > findMax(root->left) && root->val < findMin(root->right);

    return left && right && rootBal;
}


int main()
{
    TreeNode *root = NULL;

    root = new TreeNode(10);
    root->left = new TreeNode(5);
    
    cout << checkBST(root);
}
