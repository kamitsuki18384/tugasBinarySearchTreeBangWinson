#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode *root;

    TreeNode *insertNode(TreeNode *node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    bool searchNode(TreeNode *node, int value) {
        if (node == nullptr) {
            return false;
        }

        cout << node->data << " ";

        if (node->data == value) {
            return true;
        }
        
        if (value < node->data) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }

    void preorderTraversal(TreeNode *node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void inorderTraversal(TreeNode *node) {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postorderTraversal(TreeNode *node) {
        if (node == nullptr)
            return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    TreeNode *findMinNode(TreeNode *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode *removeNode(TreeNode *node, int value) {
        if (node == nullptr)
            return node;

        if (value < node->data) {
            node->left = removeNode(node->left, value);
        } else if (value > node->data) {
            node->right = removeNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }

            TreeNode *temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void search(int value) {
        cout << "Jalur pencarian BST untuk nilai " << value << ": ";
        bool found = searchNode(root, value);
        if (found) {
            cout << "\nStatus: Data " << value << " DITEMUKAN." << endl;
        } else {
            cout << "\nStatus: Data " << value << " TIDAK DITEMUKAN." << endl;
        }
    }

    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        postorderTraversal(root);
        cout << endl;
    }

    void remove(int value) {
        root = removeNode(root, value);
    }
};

int main() {
    BinaryTree tree;

    // tree.insert(40);
    // tree.insert(20);
    // tree.insert(60);
    // tree.insert(10);
    // tree.insert(30);
    // tree.insert(50);
    // tree.insert(70);

    // cout << "Preorder Traversal: ";
    // tree.preorder();

    // cout << "Inorder Traversal: ";
    // tree.inorder();

    // cout << "Postorder Traversal: ";
    // tree.postorder();

    // tree.remove(30);
    // cout << "Inorder Traversal after removing 30: ";
    // tree.inorder();

    int dataSet[15] = {50, 25, 75, 10, 32, 60, 90, 5, 15, 28, 45, 55, 70, 77, 95};
    
    for(int i = 0; i < 15; i++) {
        tree.insert(dataSet[i]);
    }

    tree.search(77);

    return 0;
}
