#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    unordered_set<string> st;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st.insert(s);
    }

    while(m--){
        string s;
        cin>>s;

        bool ok=false;

        for(int i=0;i<s.size();i++){
            char orig=s[i];

            for(char c:{'a','b','c'}){
                if(c==orig) continue;

                s[i]=c;

                if(st.count(s)){
                    ok=true;
                    break;
                }
            }

            s[i]=orig;

            if(ok) break;
        }

        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }

  return 0;
}
