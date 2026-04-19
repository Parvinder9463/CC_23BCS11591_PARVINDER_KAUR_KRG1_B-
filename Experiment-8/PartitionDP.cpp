#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> dp(n + 1, 0);
    
    for(int i = n - 1; i >= 0; i--) {
        int mx = 0;
        int best = 0;
        
        for(int j = i; j < min(n, i + k); j++) {
            mx = max(mx, arr[j]);
            best = max(best, mx * (j - i + 1) + dp[j + 1]);
        }
        
        dp[i] = best;
    }
    
    cout << dp[0];
}
