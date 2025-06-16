class Solution {
public:
    void reverseInorder(TreeNode* root, vector<int> &v) {
        if (!root) return;
        reverseInorder(root->right, v); 
        v.push_back(root->val);         
        reverseInorder(root->left, v);  
    }

    int kthLargest(TreeNode* root, int k) {
        vector<int> v;
        reverseInorder(root, v);
        return v[k - 1];
    }
};
