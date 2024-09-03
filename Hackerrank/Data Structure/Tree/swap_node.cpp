class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(NULL), right(NULL) {}
};

void inorder(Node* root, vector<int>& res_value) {
    if (!root) return;
    if (root->left) inorder(root->left, res_value);
    res_value.push_back(root->data);
    if(root->right) inorder(root->right, res_value);
}

void swapNodeUtil(Node* root, int level, int k) {
    if (!root || (!root->left && !root->right)) return;
    if (level % k == 0) {
        swap(root->left, root->right);
    }
    swapNodeUtil(root->left, level + 1, k);
    swapNodeUtil(root->right, level + 1, k);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    Node* root = new Node(1);
    
    //build tree from indexes;
    queue<Node*> q;
    q.push(root);
    for (auto index : indexes) {
        Node* current = q.front();
        q.pop();
        if(index[0] != -1) {
            current->left = new Node(index[0]);
            q.push(current->left);
        }
        if (index[1] != -1) {
            current->right = new Node(index[1]);
            q.push(current->right);
        }
    }
    
    vector<vector<int>> res;
    for (int i = 0; i < (int) queries.size(); i++) {
        vector<int> res_value;
        swapNodeUtil(root, 1, queries[i]);
        inorder(root,res_value);
        res.push_back(res_value);
    }
    return res;
}