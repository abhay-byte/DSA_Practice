#include <iostream>
#include <vector>
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

// time: O(n)
// space: O(n) due to queue, 2^h ~ n, n/2

void printLevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *cur = q.front();
            q.pop();

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

        cout << endl;
    }
}

int main()
{

    TreeNode *root = NULL;
    root = BuildPreOrderTree();

    printLevelOrder(root);
}
/*
input:- 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
*/