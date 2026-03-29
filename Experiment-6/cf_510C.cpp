#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> words(n);
    for(int i = 0; i < n; i++) cin >> words[i];

    vector<vector<int>> adj(26);
    vector<int> indeg(26, 0);
    vector<int> present(26, 0);

    for(auto &w : words)
        for(auto c : w)
            present[c - 'a'] = 1;

    for(int i = 0; i < n - 1; i++) {
        string a = words[i];
        string b = words[i + 1];
        int len = min(a.size(), b.size());

        bool found = false;
        for(int j = 0; j < len; j++) {
            if(a[j] != b[j]) {
                adj[a[j]-'a'].push_back(b[j]-'a');
                indeg[b[j]-'a']++;
                found = true;
                break;
            }
        }

        if(!found && a.size() > b.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    queue<int> q;
    for(int i = 0; i < 26; i++)
        if(indeg[i] == 0 && present[i])
            q.push(i);

    string ans = "";

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans += char(u + 'a');

        for(int v : adj[u]) {
            indeg[v]--;
            if(indeg[v] == 0)
                q.push(v);
        }
    }

    if(ans.size() != count(present.begin(), present.end(), 1)) {
        cout << "Impossible\n";
        return 0;
    }

    for(int i = 0; i < 26; i++)
        if(!present[i])
            ans += char(i + 'a');

    cout << ans << "\n";
}
