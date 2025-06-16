#include <iostream>
#include <vector>
using namespace std;

// TreeNode definition
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }

    void addLeftBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addRightBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        // Add in reverse
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }

    void addLeaves(TreeNode* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }

    vector<int> boundary(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

// Helper to create a sample tree
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right->left->left = new TreeNode(10);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;
    vector<int> result = sol.boundary(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

//         1
//       /   \
//      2     3
//     / \   / \
//    4   5 6   7
//       / \ /
//      8  9 10

// output: 
// Boundary Traversal: 1 2 4 8 9 10 6 7 3

