#include <iostream>
#include <queue>
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

TreeNode *insert(TreeNode *root, int key)
{
    // base case
    if (root == NULL)
    {
        return new TreeNode(key);
    }

    // recursive case

    if (key < root->val)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}

bool searchBST(TreeNode *root, int key)
{
    // base case
    if (root == NULL)
    {
        return false;
    }

    if (root->val == key)
    {
        return true;
    }

    // recursive case

    if (root->val > key)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
}

TreeNode* findMin(TreeNode* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    TreeNode* node = root;

    while(node->left != NULL)
    {
        node = node->left;
    }

    return node;
}

TreeNode* findMax(TreeNode* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    TreeNode* node = root;

    while(node->right != NULL)
    {
        node = node->right;
    }

    return node;
}

int main()
{
    TreeNode *root = NULL;

    root = insert(root, 10);

    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 13);
    root = insert(root, 17);

    TreeNode *min = findMin(root);
    TreeNode *max = findMax(root);

    cout << min->val; // if bst is not null
    cout << endl;
    cout << max->val; // if bst is not null;

}
