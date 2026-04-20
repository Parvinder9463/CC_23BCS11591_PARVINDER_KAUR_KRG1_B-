#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<ll, vector<ll>> mp;

    for (int i = 0; i < n; i++) {
        ll x = a[i];
        for (ll p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                if (isPrime(p)) {
                    mp[p].push_back(a[i]);
                }
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) {
            mp[x].push_back(a[i]);
        }
    }

    vector<ll> ans;

    for (auto &it : mp) {
        if (it.second.size() >= k) {
            for (int i = 0; i < k; i++) {
                ans.push_back(it.second[i]);
            }
            break;
        }
    }

    if (ans.size() < k) {
        cout << 0;
    } else {
        for (ll x : ans) cout << x << " ";
    }

    return 0;
}
