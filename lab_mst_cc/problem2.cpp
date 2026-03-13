#include<bits/stdc++.h>
using namespace std;
int findMaxScore(vector<int>& tokens, int power){
    sort(tokens.begin(), tokens.end());
    int sc=0, maxi =0;;
    int l=0,r=tokens.size()-1;
    while(l<=r){
        if(power>=tokens[l]){
            power-=tokens[l];
            sc++;
            l++;
            maxi = max(maxi, sc);
        }
        else if(sc>=1){
            power+=tokens[r];
            sc--;
            r--;
        }
        else{
            break;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;

    vector<int> tokens(n);
    for(int i=0;i<n;i++){
        cin>>tokens[i];
    }

    int power;
    cin>>power;

    int ans=findMaxScore(tokens, power);
    cout<<ans<<endl;

    return 0;

}