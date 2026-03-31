#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    if(n <= 2) {
        cout << n;
        return 0;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        map<pair<int,int>, int> mp;
        int same = 1;

        for(int j = i + 1; j < n; j++) {
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;

            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;

            mp[{dx, dy}]++;
            ans = max(ans, mp[{dx, dy}] + same);
        }
    }

    cout << ans;
    return 0;
}
