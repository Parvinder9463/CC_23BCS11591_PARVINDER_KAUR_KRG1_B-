#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> v;

    for (int i = 0; i < n; i++) {
        long long a, d;
        cin >> a >> d;
        v.push_back({a, d});
    }

    sort(v.begin(), v.end()); 

    long long t = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        t += v[i].first;
        ans += (v[i].second - t);
    }

    cout << ans << endl;

    return 0;
}
