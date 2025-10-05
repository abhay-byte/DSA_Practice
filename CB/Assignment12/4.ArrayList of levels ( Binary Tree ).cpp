/*

//https://hack.codingblocks.com/app/contests/7856/151/problem

Given a Binary tree, write code to create a separate array list for each level. You should return an arraylist of arraylist.
Input Format

Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL
Constraints

None
Output Format

Display the resulting arraylist of arraylist according to given sample examples.
Sample Input

50 true 12 true 18 false false true 13 false false false

Sample Output

[[50], [12], [18, 13]]

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

std::vector<std::vector<int>> createLevelLists(Node* root) {
    std::vector<std::vector<int>> result;
    if (root == nullptr) {
        return result;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        std::vector<int> currentLevel;

        for (int i = 0; i < levelSize; ++i) {
            Node* currentNode = q.front();
            q.pop();
            
            currentLevel.push_back(currentNode->data);

            if (currentNode->left != nullptr) {
                q.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                q.push(currentNode->right);
            }
        }
        result.push_back(currentLevel);
    }
    return result;
}

int main() {

    Node* root = buildTree();
    std::vector<std::vector<int>> levels = createLevelLists(root);

    std::cout << "[";
    for (size_t i = 0; i < levels.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < levels[i].size(); ++j) {
            std::cout << levels[i][j];
            if (j < levels[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i < levels.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}