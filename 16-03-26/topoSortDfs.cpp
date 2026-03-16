#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st){
    visited[node] = true;

    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, adj, visited, st);
        }
    }

    st.push(node);
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<bool> visited(n, false);
    stack<int> st;

    

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}