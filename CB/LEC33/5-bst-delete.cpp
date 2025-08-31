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


void printInOrder(TreeNode *root)
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


    // 2. print the preOrder of the left Subtree

    printInOrder(root->left);

    cout << root->val << " ";

    // 3. print the preOrder of the right Subtree

    printInOrder(root->right);
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


TreeNode *deleteFromBST(TreeNode *root, int key)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    // recursive case
    if (root->val > key)
    {
        root->left = deleteFromBST(root->left, key);
    }
    else if (root->val < key)
    {
        root->right = deleteFromBST(root->right, key);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        { //leaf node
            delete(root);
            root = NULL;
        }
        else if(root->left == NULL && root->right != NULL)
        { //one child
            TreeNode* node = root->right;
            delete(root);
            root = node;
        }
        else if(root->left != NULL && root->right == NULL)
        { //one child
            TreeNode* node = root->left;
            delete(root);
            root = node;
        }
        else
        { //two child
            TreeNode* leftMax = findMax(root->left);
            swap(root->val,leftMax->val);
            root->left = deleteFromBST(root->left,leftMax->val);

        }
    }

    return root;
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

    int key = 3;
    printLevelOrder(root);

    cout << endl;

    printInOrder(root);

    cout << endl;

    root = deleteFromBST(root, 10);

    printLevelOrder(root);

    cout << endl;

    printInOrder(root);
}
