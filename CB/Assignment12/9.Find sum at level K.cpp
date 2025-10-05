/*

//https://hack.codingblocks.com/app/contests/7856/1085/problem

Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.
Input Format

Take a generic tree input where you are first given the data of the node and then its no of children. The input is of preorder form and it is assured that the no of children will not exceed 2. The input of the tree is followed by a single integer K.
Constraints

1 <= Nodes in tree <=1000
1<K<10
Output Format

A single line containing the sum at level K.
Sample Input

1 2
2 2
3 0
4 0
5 2
6 0
7 0
2

Sample Output

20

Explanation

Here the tree looks like

                     1                                 Level 0
                /          \
              2              5                         Level 1
           /      \       /     \
          3       4      6        7                    Level 2

Sum at Level 2 = 3 + 4 + 6 + 7 = 20

*/



#include <iostream>
#include <vector>
#include <numeric>

struct Node {
    int data;
    std::vector<Node*> children;

    Node(int val) : data(val) {}
};

Node* buildTree() {
    int data, numChildren;
    if (!(std::cin >> data >> numChildren)) {
        return nullptr;
    }

    Node* root = new Node(data);
    for (int i = 0; i < numChildren; ++i) {
        root->children.push_back(buildTree());
    }
    return root;
}

void sumAtLevelKHelper(Node* node, int currentLevel, int k, int& sum) {
    if (node == nullptr) {
        return;
    }

    if (currentLevel == k) {
        sum += node->data;
        return;
    }

    for (Node* child : node->children) {
        sumAtLevelKHelper(child, currentLevel + 1, k, sum);
    }
}

int main() {

    Node* root = buildTree();
    int k;
    std::cin >> k;

    int sum = 0;
    sumAtLevelKHelper(root, 0, k, sum);

    std::cout << sum << std::endl;

    return 0;
}