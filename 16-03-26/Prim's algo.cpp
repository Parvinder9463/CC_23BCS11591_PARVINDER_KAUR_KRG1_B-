#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> vis(n + 1, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 1});

    int cost = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int w = it.first;
        int u = it.second;

        if (vis[u]) continue;

        vis[u] = 1;
        cost += w;

        for (auto x : adj[u]) {
            int v = x.first;
            int wt = x.second;

            if (!vis[v]) {
                pq.push({wt, v});
            }
        }
    }

    cout << cost;

    return 0;
}
