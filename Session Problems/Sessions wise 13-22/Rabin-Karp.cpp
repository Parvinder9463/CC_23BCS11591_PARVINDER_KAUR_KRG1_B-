#include <bits/stdc++.h>
using namespace std;

int main() {
    string t = "ababcabcab", p = "abc";

    int n = t.size(), m = p.size();
    int d = 256, q = 101;

    int ph = 0, th = 0, h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        ph = (d * ph + p[i]) % q;
        th = (d * th + t[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (ph == th) {
            int j = 0;
            while (j < m && t[i + j] == p[j]) j++;

            if (j == m) cout << "Found at " << i << endl;
        }

        if (i < n - m) {
            th = (d * (th - t[i] * h) + t[i + m]) % q;
            if (th < 0) th += q;
        }
    }

    return 0;
}
