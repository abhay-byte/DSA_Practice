/*

//https://hack.codingblocks.com/app/contests/7856/449/problem

Given postorder and inorder traversal of a tree. Create the original tree on given information.
Input Format

Enter the size of the postorder array N then add N more elements and store in the array, then enter the size of the inorder array M and add M more elements and store in the array. here M and N are same.
Constraints

None
Output Format

Display the tree using the display function
Sample Input

3
1
3
2
3
1
2
3

Sample Output

1 => 2 <= 3
END => 1 <= END
END => 3 <= END

*/

#include <iostream>
#include <vector>
#include <unordered_map>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTreeHelper(const std::vector<int>& postorder, int& postIndex,
                      std::unordered_map<int, int>& inorderMap, int inStart, int inEnd) {
    if (inStart > inEnd) {
        return nullptr;
    }

    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);

    int inIndex = inorderMap[rootVal];

    root->right = buildTreeHelper(postorder, postIndex, inorderMap, inIndex + 1, inEnd);
    root->left = buildTreeHelper(postorder, postIndex, inorderMap, inStart, inIndex - 1);

    return root;
}

void display(Node* node) {
    if (node == nullptr) {
        return;
    }

    if (node->left != nullptr) {
        std::cout << node->left->data;
    } else {
        std::cout << "END";
    }

    std::cout << " => " << node->data << " <= ";

    if (node->right != nullptr) {
        std::cout << node->right->data;
    } else {
        std::cout << "END";
    }
    std::cout << std::endl;

    display(node->left);
    display(node->right);
}

int main() {

    int N;
    std::cin >> N;
    std::vector<int> postorder(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> postorder[i];
    }

    int M;
    std::cin >> M;
    std::vector<int> inorder(M);
    std::unordered_map<int, int> inorderMap;
    for (int i = 0; i < M; ++i) {
        std::cin >> inorder[i];
        inorderMap[inorder[i]] = i;
    }

    int postIndex = N - 1;
    Node* root = buildTreeHelper(postorder, postIndex, inorderMap, 0, M - 1);

    display(root);

    return 0;
}