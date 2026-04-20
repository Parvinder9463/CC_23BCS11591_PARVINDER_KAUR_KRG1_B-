#include <bits/stdc++.h>
using namespace std;

vector<int> lps(string p) {
    int m = p.size();
    vector<int> l(m, 0);

    int i = 1, j = 0;
    while (i < m) {
        if (p[i] == p[j]) {
            l[i] = j + 1;
            i++; j++;
        } else {
            if (j != 0) j = l[j - 1];
            else i++;
        }
    }
    return l;
}

int main() {
    string t = "ababcabcab", p = "abc";

    vector<int> l = lps(p);

    int i = 0, j = 0;
    while (i < t.size()) {
        if (t[i] == p[j]) {
            i++; j++;
        }

        if (j == p.size()) {
            cout << "Found at " << i - j << endl;
            j = l[j - 1];
        } else if (i < t.size() && t[i] != p[j]) {
            if (j != 0) j = l[j - 1];
            else i++;
        }
    }

    return 0;
}
