#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<ll> c(n, 0), d(n, 0);

    ll ans = 0;
    ll u = 0, a = 0;

    for (int i = n - 1; i >= 0; i--) {
        u += c[i];
        a += d[i];

        b[i] += u * i + a;

        ll len = min(i + 1, k);

        if (b[i] > 0) {
            ll t = (b[i] + len - 1) / len;

            ans += t;

            u -= t;
            a -= t * (len - i);

            if (i - len >= 0) {
                c[i - len] += t;
                d[i - len] += t * (len - i);
            }
        }
    }

    cout << ans;

    return 0;
}
