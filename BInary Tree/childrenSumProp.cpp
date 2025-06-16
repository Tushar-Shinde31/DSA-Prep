class Solution {
public:
    void changeTree(BinaryTreeNode<int>* root) {
        if (root == nullptr)
            return;

        // Step 1: Top-down modification
        int childSum = 0;
        if (root->left) {
            childSum += root->left->data;
        }
        if (root->right) {
            childSum += root->right->data;
        }

        if (childSum >= root->data) {
            root->data = childSum;
        } else {
            if (root->left) root->left->data = root->data;
            if (root->right) root->right->data = root->data;
        }

        // Step 2: Recur for left and right subtree
        changeTree(root->left);
        changeTree(root->right);

        // Step 3: Bottom-up correction
        int total = 0;
        if (root->left) total += root->left->data;
        if (root->right) total += root->right->data;

        // If node has at least one child, set its data to the sum of its children
        if (root->left || root->right) {
            root->data = total;
        }
    }
};

