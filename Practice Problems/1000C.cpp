#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<ll, ll> mp;

    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        mp[l]++;
        mp[r + 1]--;
    }

    vector<ll> ans(n + 1, 0);

    ll cur = 0;
    auto it = mp.begin();

    while (it != mp.end()) {
        cur += it->second;
        auto nxt = next(it);

        if (nxt != mp.end() && cur > 0) {
            ll len = nxt->first - it->first;
            if (cur <= n) ans[cur] += len;
        }

        it = nxt;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
