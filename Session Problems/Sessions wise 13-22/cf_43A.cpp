#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> m;
    string a = "", b = "";
    int c = 0;

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;

        m[x]++;

        if (m[x] == 1) {
            if (c == 0) a = x;
            else if (c == 1) b = x;
            c++;
        }
    }

    if (m[a] > m[b]) cout << a;
    else cout << b;

    return 0;
}
