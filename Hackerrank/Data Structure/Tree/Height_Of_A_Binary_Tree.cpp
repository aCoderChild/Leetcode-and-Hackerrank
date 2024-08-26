int height(Node* root) {
        // Write your code here.
        if(root == NULL) return -1; //because if there is no element, the level will be -1
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }