#include<bits/stdc++.h>
using namespace std;

int findElemAppearsThreeTimes(vector<int>& nums) {
    int ans=0;
    for(int i=0;i<32;i++){
        int cnt=0;
        for(int j=0;j<nums.size();j++){
            if((nums[j]>>i)&1){
                cnt++;
            }
        }
        if(cnt%3!=0){
            ans|=(1<<i);
        }
    }
    return ans;
}

int main(){

    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int ans = findElemAppearsThreeTimes(nums);
    cout<<ans<<endl;
    
    return 0;

}