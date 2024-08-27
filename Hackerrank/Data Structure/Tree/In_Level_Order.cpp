void levelOrder(Node * root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* top = q.front();
            q.pop();
            cout << top->data << " ";
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
        }
    }