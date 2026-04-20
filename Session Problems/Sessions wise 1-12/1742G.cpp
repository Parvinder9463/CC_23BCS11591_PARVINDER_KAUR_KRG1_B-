#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> res;
        vector<int> vis(n, 0);

        int cur = 0;

        for (int i = 0; i < n; i++) {
            int best = 0, idx = -1;

            for (int j = 0; j < n; j++) {
                if (vis[j]) continue;

                int val = a[j] & (~cur);

                if (val > best) {
                    best = val;
                    idx = j;
                }
            }

            if (idx == -1) break;

            vis[idx] = 1;
            res.push_back(a[idx]);
            cur |= a[idx];
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) res.push_back(a[i]);
        }

        for (int x : res) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
