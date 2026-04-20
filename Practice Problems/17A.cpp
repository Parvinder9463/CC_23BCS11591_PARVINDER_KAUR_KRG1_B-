#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> prime(n + 1, 1);
    prime[0] = prime[1] = 0;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }

    vector<int> p;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) p.push_back(i);
    }

    int cnt = 0;

    for (int i = 1; i < p.size(); i++) {
        int x = p[i - 1] + p[i] + 1;

        if (x <= n && prime[x]) {
            cnt++;
        }
    }

    if (cnt >= k) cout << "YES";
    else cout << "NO";

    return 0;
}
