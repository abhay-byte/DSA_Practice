#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
    node *left;
    node *right;

    node()
    {
        this->left = NULL;
        this->right = NULL;
    }
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node();
    }

    void insert(int n)
    {
        node *cur = root;
        for (int k = 31; k >= 0; k--)
        {
            int kthBit = (n >> k) & 1;
            if(kthBit == 1)
            {
                if(cur->right == NULL)
                {
                    cur->right = new node();
                }
                cur = cur->right;
            }
            else{
                if(cur->left == NULL)
                {
                    cur->left = new node();
                }
                cur = cur->left;
            }
        }
    }

    bool search(int n)
    {
        node *cur = root;
        for (int k = 31; k >= 0; k--)
        {
            int kthBit = (n >> k) & 1;
            if(kthBit == 1)
            {
                if(cur->right == NULL)
                {
                    return false;
                }
                cur = cur->right;
            }
            else{
                if(cur->left == NULL)
                {
                    return false;
                }
                cur = cur->left;
            }
        }

        return true;
    }
};

int main()
{
    int nums[] = {3, 4, 9, 6, 10};

    trie t;
    for (int n : nums)
    {
        t.insert(n);
    }

    int brr[] = {1, 2, 5, 10, 25, 0};

    for (int n : brr)
    {
        t.search(n) ? cout << n << " Present" << endl : cout << n << " Absent" << endl;
    }
    return 0;
}

