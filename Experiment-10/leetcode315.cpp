#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0), idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;
        mergeSort(nums, idx, ans, 0, n - 1);
        return ans;
    }

    void mergeSort(vector<int>& nums, vector<int>& idx, vector<int>& ans, int l, int r) {
        if(l >= r) return;
        int m = (l + r) / 2;
        mergeSort(nums, idx, ans, l, m);
        mergeSort(nums, idx, ans, m + 1, r);
        merge(nums, idx, ans, l, m, r);
    }

    void merge(vector<int>& nums, vector<int>& idx, vector<int>& ans, int l, int m, int r) {
        vector<int> temp(r - l + 1);
        int i = l, j = m + 1, k = 0, rightCount = 0;

        while(i <= m && j <= r) {
            if(nums[idx[j]] < nums[idx[i]]) {
                temp[k++] = idx[j++];
                rightCount++;
            } else {
                ans[idx[i]] += rightCount;
                temp[k++] = idx[i++];
            }
        }

        while(i <= m) {
            ans[idx[i]] += rightCount;
            temp[k++] = idx[i++];
        }

        while(j <= r) {
            temp[k++] = idx[j++];
        }

        for(int i = l; i <= r; i++) {
            idx[i] = temp[i - l];
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    Solution s;
    vector<int> res = s.countSmaller(nums);

    for(int x : res) cout << x << " ";
}
