#include <bits/stdc++.h>
using namespace std;

vector<int> adj[26];
int vis[26];
string ans;

bool dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 0) {
            if (dfs(v)) return true;
        } else if (vis[v] == 1) {
            return true;
        }
    }
    vis[u] = 2;
    ans += char('a' + u);
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n - 1; i++) {
        string a = v[i];
        string b = v[i + 1];

        int len = min(a.size(), b.size());
        bool f = false;

        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                f = true;
                break;
            }
        }

        if (!f && a.size() > b.size()) {
            cout << "Impossible";
            return 0;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (vis[i] == 0) {
            if (dfs(i)) {
                cout << "Impossible";
                return 0;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}
