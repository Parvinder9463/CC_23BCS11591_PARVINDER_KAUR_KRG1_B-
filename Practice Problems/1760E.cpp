#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        ll inv = 0;
        int c1 = 0;

        int first0 = -1, last1 = -1;
        int c0 = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (a[i] == 1) {
                c1++;
                last1 = i;
            } else {
                inv += c1;
                c0++;
                if (first0 == -1) first0 = i;
            }
        }

        ll ans = inv;

        if (first0 != -1) {
            ll add = c0 - 1 - first0;
            ans = max(ans, inv + add);
        }

        if (last1 != -1) {
            ll add = c1 - 1 - (n - 1 - last1);
            ans = max(ans, inv + add);
        }

        cout << ans << "\n";
    }

    return 0;
}
