void topView(Node * root) {
        vector<int> ans = {};
        if (root == NULL) return;
        map<int, int> mp; //top view of node based on their vertical position
        //<vertical index, node data>
        queue<pair<Node*, int>> q; //node and the position (vertical)
        q.push({root, 0});
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            Node* node = top.first;
            int line = top.second;
            
            if (mp.find(line) == mp.end()) {
                mp[line] = node->data;
            }
            
            if (node->left) {
                q.push({node->left, line - 1});
            }
            
            if (node->right) {
                q.push({node->right, line + 1});
            }
        }
        
        for (auto i : mp) {
            cout << i.second << " ";
        }
    }
    
    //map: to store the Node data and the line vertical
    //using queue<pair<Node*, int>>: store the node and the vertical line