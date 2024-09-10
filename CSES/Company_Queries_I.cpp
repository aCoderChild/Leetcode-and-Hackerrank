#include<bits/stdc++.h>
using namespace std;

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