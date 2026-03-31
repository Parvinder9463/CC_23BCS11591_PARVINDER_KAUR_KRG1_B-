#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 

    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v, price;
        cin >> u >> v >> price;
        adj[u].push_back({v, price});
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    queue<tuple<int,int,int>> q;
    q.push({0, src, 0});

    while(!q.empty()) {
        auto [stops, node, cost] = q.front();
        q.pop();

        if(stops > k) continue;

        for(auto it : adj[node]) {
            int next = it.first;
            int price = it.second;

            if(cost + price < dist[next]) {
                dist[next] = cost + price;
                q.push({stops + 1, next, dist[next]});
            }
        }
    }

    if(dist[dst] == 1e9) cout << -1;
    else cout << dist[dst];

    return 0;
}
