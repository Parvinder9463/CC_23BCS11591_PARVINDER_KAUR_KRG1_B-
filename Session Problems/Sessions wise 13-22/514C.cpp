#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> st;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }

    while (m--) {
        string s;
        cin >> s;

        bool ok = false;

        for (int i = 0; i < s.size(); i++) {
            char old = s[i];

            for (char ch = 'a'; ch <= 'c'; ch++) {
                if (ch == old) continue;

                s[i] = ch;

                if (st.count(s)) {
                    ok = true;
                    break;
                }
            }

            s[i] = old;
            if (ok) break;
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
