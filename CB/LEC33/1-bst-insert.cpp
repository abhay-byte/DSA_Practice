#include<iostream>
#include<queue>
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


void printLevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (cur == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << cur->val << " ";
            if (cur->left != NULL)
            {
                q.push(cur->left);
            }
            if (cur->right != NULL)
            {
                q.push(cur->right);
            }
        }
    }
}

TreeNode* insert(TreeNode* root, int key)
{
    //base case
    if(root == NULL)
    {
        return new TreeNode(key);
    }

    //recursive case

    if(key < root->val)
    {
        root->left = insert(root->left, key);
    }
    else{
        root->right = insert(root->right, key);
    }

    return root;
}

int main()
{
    TreeNode* root = NULL;

    root = insert(root,10);

    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 13);
    root = insert(root, 17);

    printLevelOrder(root);

    cout << endl;

    printPreOrder(root);
    
}

