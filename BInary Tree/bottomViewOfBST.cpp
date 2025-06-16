#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    vector<int> bottomView(TreeNode *root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        map<int, int> mpp; // horizontal distance -> node data
        queue<pair<TreeNode*, int>> q; // node, horizontal distance

        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int line = it.second;

            // Overwrite the value at the same horizontal distance
            mpp[line] = node->data;

            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    /*
        Construct the following binary tree:
                 20
                /  \
              8     22
             / \      \
            5   3      25
               / \
              10 14
    */

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    Solution sol;
    vector<int> result = sol.bottomView(root);

    cout << "Bottom view of the binary tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
