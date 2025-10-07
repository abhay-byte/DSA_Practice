/*

//https://hack.codingblocks.com/app/contests/7857/459/problem

Replace each node with the sum of all greater nodes in a given BST
Input Format

Enter the number of nodes N and add N more numbers to the BST
Constraints

None
Output Format

Display the resulting tree
Sample Input

3
2
1
3

Sample Output

5 => 3 <= 0
END => 5 <= END
END => 0 <= END


*/

#include <iostream>
#include <string>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void replaceWithSumHelper(Node* node, int& sum) {
    if (node == nullptr) {
        return;
    }

    replaceWithSumHelper(node->right, sum);

    int original_data = node->data;
    node->data = sum;
    sum += original_data;
    
    replaceWithSumHelper(node->left, sum);
}

void display(Node* node) {
    if (node == nullptr) {
        return;
    }

    std::string leftStr = "END";
    if (node->left != nullptr) {
        leftStr = std::to_string(node->left->data);
    }

    std::string rightStr = "END";
    if (node->right != nullptr) {
        rightStr = std::to_string(node->right->data);
    }

    std::cout << leftStr << " => " << node->data << " <= " << rightStr << std::endl;

    display(node->left);
    display(node->right);
}

int main() {

    int n;
    std::cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        root = insert(root, val);
    }

    int sum = 0;
    replaceWithSumHelper(root, sum);
    display(root);

    return 0;
}