/*

//https://hack.codingblocks.com/app/contests/7856/80/problem

Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left.
Input Format

Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL
Constraints

None
Output Format

Display the values in zigzag level order in which each value is separated by a space
Sample Input

10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

Sample Output

10 30 20 40 50 60 73 

*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree() {
    int data;
    std::string hasChild;

    if (!(std::cin >> data)) {
        return nullptr;
    }

    Node* root = new Node(data);

    std::cin >> hasChild;
    if (hasChild == "true") {
        root->left = buildTree();
    }

    std::cin >> hasChild;
    if (hasChild == "true") {
        root->right = buildTree();
    }

    return root;
}

void zigzagLevelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        std::vector<int> currentLevelValues(levelSize);

        for (int i = 0; i < levelSize; ++i) {
            Node* currentNode = q.front();
            q.pop();

            int index = leftToRight ? i : (levelSize - 1 - i);
            currentLevelValues[index] = currentNode->data;

            if (currentNode->left != nullptr) {
                q.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                q.push(currentNode->right);
            }
        }
        
        for (int i = 0; i < levelSize; ++i) {
            std::cout << currentLevelValues[i] << " ";
        }
        
        leftToRight = !leftToRight;
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Node* root = buildTree();
    zigzagLevelOrder(root);

    return 0;
}