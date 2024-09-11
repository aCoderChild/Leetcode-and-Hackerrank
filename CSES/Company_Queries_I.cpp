/*
#include<bits/stdc++.h>
using namespace std;

// must initialise the vectors
void input(int &n, int &q, vector<int> &parent, vector<vector<int> > &queries) {
    cin >> n >> q;
    parent.resize(n-1);
    queries.resize(q, vector<int>(2));

    for (int i = 0; i < n - 1; i++) {
        cin >> parent[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0];
        cin >> queries[i][1];
    }
}

int findParent(int a, int k, map<int, int> par) {
    int parent = a;
    for (int i = 0; i < k; i++) {
        if(par.find(parent) != par.end()) parent = par[parent];
        else {
            return -1;
        }
    }
    return parent;
}

void solution(int n, vector<int> parent, vector<vector<int> > queries) {
    map<int, int> par;
    for (int i = 2; i <= n; i++) {
        par[i] = parent[i-2]; 
    }

    for (auto query : queries) {
        cout << findParent(query[0], query[1], par) << endl;
    }
}

int main() {
    int n, q;
    vector<int> parent;
    vector<vector<int> > queries;

    input(n, q, parent, queries);
    solution(n, parent, queries);

    return 0;
}
*/

// time complexity: O(N)
// => time complexity in worst case and include all the queries: approximately 10^10
// => takes: 10^10 / 10^8  = 100s >> 1.00s => not efficient for extreme cases

// --- Another Approach: BINARY LIFTING ---
#include <bits/stdc++.h>
using namespace std;

//constants
const int MAXN = 200011; //prime number which is larger the 2.10^5
const int M = 20; //log2(MAXN) - approxmately 17

vector<vector<int> > up (MAXN, vector<int>(M, 0)); //dp table
vector<int> level (MAXN, 0); //MAXN bigger than the largest possible integer in the constraints

//dfs traversal of the tree
void dfs(int node, int par, vector<int> adj[], int lvl) { //vector<int> adj[]: adjaciency list
    up[node][0] = par;
    level[node] = lvl;

    for (auto child : adj[node]) {
        if (child != par) {
            dfs(child, node, adj, lvl+1); //level ++ doesnt mean anything...
        }
    }
}

void preprocess() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < M; j++) {
            if(up[i][j-1] != -1) {
                int par = up[i][j-1]; // the j-1 ancestor of the node
                up[i][j] = up[par][j-1]; // fill in the table
            }
        }
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> adj[n+1];
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i); //adjaciency list initialise
    }

    dfs(1, -1, adj, 0);
    preprocess();

    //print the table
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            cout << up[i][j] << " ";
        }
        cout << endl;
    }
    

    while (q--) {
        int x, k;
        cin >> x >> k;

        if (level[x] < k) {
            cout << -1 << endl;
            continue;
        }

        while(k) {
            int i = log2(k);
            x = up[x][i];
            if (x == -1) break;
            k -= (1 << i); // 1 << i: 2 to the power of i - SHIFT LEFT operation
        }
        cout << x << endl;
    }
}