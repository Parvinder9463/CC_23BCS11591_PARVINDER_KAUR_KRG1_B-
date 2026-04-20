#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;

        ll lenS = 1, lenT = 1;
        int cntS[26] = {0}, cntT[26] = {0};

        cntS[0] = 1;
        cntT[0] = 1;

        while (q--) {
            int d, k;
            string x;
            cin >> d >> k >> x;

            if (d == 1) {
                lenS += (ll)k * x.size();
                for (char c : x) {
                    cntS[c - 'a'] += k;
                }
            } else {
                lenT += (ll)k * x.size();
                for (char c : x) {
                    cntT[c - 'a'] += k;
                }
            }

            bool t_has_big = false;
            for (int i = 1; i < 26; i++) {
                if (cntT[i] > 0) t_has_big = true;
            }

            if (t_has_big) {
                cout << "YES\n";
                continue;
            }

            bool s_has_big = false;
            for (int i = 1; i < 26; i++) {
                if (cntS[i] > 0) s_has_big = true;
            }

            if (!s_has_big && lenS < lenT) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
