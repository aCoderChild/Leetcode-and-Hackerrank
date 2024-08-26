void preOrder(Node *root) {
        if (root) {
            cout << root->data << " "; //check if the root is NULL or NOT 
            preOrder(root->left);
            preOrder(root->right);
        }
    }