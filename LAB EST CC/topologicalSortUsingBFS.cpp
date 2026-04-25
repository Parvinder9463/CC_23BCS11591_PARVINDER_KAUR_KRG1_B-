#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    
    vector<int>indegree(n,0);
    vector<int>vis(n, 0);
    vector<int>ans;
    queue<int>q;
    for(int i =0 ;i < n; i++) {
        for(auto& it : adj[i]) {
            indegree[it]++;
        }
    }
    
    for(int i = 0; i < n; i ++) {
        if(indegree[i] == 0) {
            q.push(i);
            
        }
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(auto& it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
        
        ans.push_back(node);
    }
    return ans;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v);

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans = topologicalSort(adj);
    for(auto& it : ans) {
        cout << it << " ";
    }   
    
}