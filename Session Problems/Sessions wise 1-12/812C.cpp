#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll S;
vector<ll> a, b;

ll cost(int k) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i] + (i + 1) * k;
    }

    sort(b.begin(), b.end());

    ll sum = 0;
    for (int i = 0; i < k; i++) {
        sum += b[i];
    }

    return sum;
}

int main() {
    cin >> n >> S;

    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n, ans = 0;
    ll total = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        ll c = cost(mid);

        if (c <= S) {
            ans = mid;
            total = c;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << " " << total;

    return 0;
}
