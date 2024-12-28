// Program to count the number of leaf nodes in a binary tree using an in-order traversal.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void inorderCount(Node* root, int& cnt) {
    if (root == NULL) {
        return;
    }
    inorderCount(root->left, cnt);
    if (root->left == NULL && root->right == NULL) {
        cnt++;
    }
    inorderCount(root->right, cnt);
}

int countLeaves(Node* root) {
    int cnt = 0;
    inorderCount(root, cnt);
    return cnt;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Number of leaf nodes: " << countLeaves(root) << endl;

    return 0;
}
