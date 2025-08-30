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
        TreeNode* newNode = NULL;
        newNode->val = key;
        return newNode;

        //return new TreeNode(key);
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

    
}

