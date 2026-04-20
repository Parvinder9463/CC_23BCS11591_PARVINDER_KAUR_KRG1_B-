#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
      
      
        int n;
        cin>>n;
        
        

        vector<long long>a(n+1),b(n+1);
        
        
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];


        vector<long long>pref(n+1);
        
        
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]+b[i];


        vector<long long>cnt(n+2,0),extra(n+2,0);
        

        for(int i=1;i<=n;i++){
          
          
            long long target=a[i]+pref[i-1];
            

            int pos= upper_bound(pref.begin(),pref.end(),target)-pref.begin()-1;
            

            if(pos>=i){
              
                cnt[i]++;
                
                cnt[pos+1]--;
                
            }
            
            

            if(pos+1<=n) extra[pos+1] += a[i]-(pref[pos] -pref[i-1]);
            
            
        }
        
        

        for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
        

        for(int i=1;i<=n;i++) cout<<cnt[i]*b[i]+extra[i]<<" ";
        
        

        cout<<endl;
    }
}
