/*

//https://hack.codingblocks.com/app/contests/7857/277/problem

For each node in a binary search tree, create a new duplicate node, and insert the duplicate as the left child of the original node.
Input Format

Enter the number of nodes N and add N more numbers to the BST
Constraints

None
Output Format

Display the tree
Sample Input

3
2
1
3

Sample Output

2 => 2 <= 3
1 => 2 <= END
1 => 1 <= END
END => 1 <= END
3 => 3 <=END
END => 3 <=END

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

void insertDuplicates(Node* node) {
    if (node == nullptr) {
        return;
    }

    insertDuplicates(node->left);
    insertDuplicates(node->right);

    Node* oldLeft = node->left;
    Node* duplicate = new Node(node->data);
    node->left = duplicate;
    duplicate->left = oldLeft;
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

    insertDuplicates(root);
    display(root);

    return 0;
}