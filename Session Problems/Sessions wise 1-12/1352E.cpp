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

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }

        vector<int> ok(n + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j <= n; j++) {
                int s = pref[j] - pref[i];
                if (s <= n) ok[s] = 1;
            }
        }

        int ans = 0;
        for (int x : a) {
            if (ok[x]) ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}
