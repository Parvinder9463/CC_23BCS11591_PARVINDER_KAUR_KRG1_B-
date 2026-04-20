#include<bits/stdc++.h>
using namespace std;

int main(){
    long long k;
    cin>>k;


    string s;
    cin>>s;


    unordered_map<long long,long long>freq;
    
    
    freq[0]=1;

    long long pref=0, ans=0;

    for(char c:s){
        
        
        if(c=='1') pref++;


        if(freq.count(pref-k)) ans+=freq[pref-k];
        

        freq[pref]++;
        
        
    }


    cout<<ans<<endl;
    
    return 0;
}
