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
    int numCourses, prerequisites;
    cin>>numCourses>>prerequisites;

    vector<int> adj[numCourses];
    for(int i=0;i<prerequisites;i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
    }

    vector<bool> visited(numCourses, false);
    stack<int> st;

    for(int i=0;i<numCourses;i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }

    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    for(auto it: topo){
        cout<<it<<" ";
    }
    cout<<endl;
}