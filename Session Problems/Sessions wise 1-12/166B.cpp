#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct P {
    ll x, y;
};

ll cross(P o, P a, P b) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

int main() {
    int n;
    cin >> n;

    vector<P> a(n + 1);
    for (int i = n; i >= 1; i--) {
        cin >> a[i].x >> a[i].y;
    }

    int m;
    cin >> m;

    int cnt = 0;

    while (m--) {
        P p;
        cin >> p.x >> p.y;

        int l = 2, r = n;

        while (l < r) {
            int mid = (l + r) / 2;
            if (cross(a[1], a[mid], p) <= 0) r = mid;
            else l = mid + 1;
        }

        if (l == 2 || cross(a[1], a[n], p) >= 0) continue;

        if (cross(a[l], a[l - 1], p) < 0) cnt++;
    }

    if (cnt == 0) cout << "NO";
    else cout << "YES";

    return 0;
}
