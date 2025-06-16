int findCeil(BinaryTreeNode<int> *root, int key){
    int ceil = -1;
    while(root){
        if(root->val == key){
            ceil = root->data;
            return ceil;
        }
        if(key > root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return ceil;
}