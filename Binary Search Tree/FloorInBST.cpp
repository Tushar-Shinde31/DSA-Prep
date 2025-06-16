int floorInBST(TreeNode<int> *root, int key){
    int floor = -1;
    while(root){
        if(root->val == key){ // Fixed assignment to comparison
            floor = root->val;
            return floor;     // Return the value, not the node
        }
        if(key > root->val){
            floor = root->val;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
}