#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[n];
    vector<int> indegree(n, 0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    for(auto it: topo){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}

// t.c -> O(n+m)
// s.c -> O(n) for queue + O(n) for indegree + O(n) for topo vector + O(n) for adjacency list = O(4n) ~ O(n)