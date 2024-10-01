bool isBinaryLeft(Node* root, Node* left) {
        if (root->data > left->data) return true;
        else return false;
    }

    bool isBinaryRight(Node* root, Node* right) {
        if (root->data < right->data) return true;
        else return false;
    }

	bool checkBST(Node* root) {
        if (root == NULL) return true;
		if (root->left && !isBinaryLeft(root, root->left)) return false;
        if (root->right && !isBinaryRight(root, root->right)) return false;
        return checkBST(root->left) && checkBST(root->right);
	}
    //Analyse: 6/14 test cases FAIL

//Alternative:
bool isBSTUtil(Node* node, int minValue, int maxValue) {
    // Base case: An empty tree is a valid BST
    if (node == NULL) {
        return true;
    }

    // Check if the current node's value is within the valid range
    if (node->data <= minValue || node->data >= maxValue) {
        return false;
    }

    // Recursively check the left and right subtrees
    // Left subtree: all values should be less than the current node's value
    // Right subtree: all values should be greater than the current node's value
    return isBSTUtil(node->left, minValue, node->data) &&
           isBSTUtil(node->right, node->data, maxValue);
}

bool checkBST(Node* root) {
    // Start with the full range of integer values
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
