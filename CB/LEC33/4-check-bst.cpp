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

class triple
{
    public:
    int minVal;
    int maxVal;
    bool isBal;
};

triple checkBSTOptimized(TreeNode* root)
{
    triple t;
    //base case
    if(root == NULL)
    {
        t.maxVal = INT_MIN;
        t.minVal = INT_MAX;
        t.isBal = true;

        return t;
    }

    //recursive case
    triple left = checkBSTOptimized(root->left);
    triple right = checkBSTOptimized(root->right);

    bool rootBal = root->val > left.maxVal && root->val < right.minVal;

    t.isBal = left.isBal && right.isBal && rootBal;
    t.maxVal = max(left.maxVal, max(root->val,right.maxVal));
    t.minVal = min(left.minVal, max(right.minVal,root->val));

    return t;

}

bool checkBSTRange(TreeNode* root, long long lb, long long ub)
{
    //base case
    if(root == NULL)
    {
        return true;
    }

    //recursive case
    return root->val > lb && root->val < ub && checkBSTRange(root->left,lb,root->val) && checkBSTRange(root->right,root->val,ub); 

}
int main()
{
    TreeNode *root = NULL;

    root = new TreeNode(10);
    root->left = new TreeNode(20);
    
    cout << checkBST(root) << endl;
    cout << checkBSTOptimized(root).isBal << endl;

    long long lb = (long long) INT_MIN - 1;
    long long rb = (long long) INT_MAX - 1;

    cout << checkBSTRange(root,lb,rb) << endl;
}
