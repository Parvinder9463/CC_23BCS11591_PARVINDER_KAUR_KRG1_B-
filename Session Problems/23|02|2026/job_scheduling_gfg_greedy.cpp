#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    
    int find(int d, vector<int>& par){
        
        if(par[d]==d) return d;
        
        return par[d] = find(par[d],par);
    }
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        int n=deadline.size();
        priority_queue<pair<int, int>> pq;
        
        for(int i =0;i<n;i++){
            pq.push({profit[i], deadline[i]});
        }
        
        vector<int> v(n, 0);
        vector<int> parent(n+1);
        
        for(int i=0;i<=n;i++) parent[i] = i;
        
        int sum=0, cnt=0;

        while(!pq.empty()){
            int pro = pq.top().first;
            int dead=pq.top().second;
            pq.pop();
            
            int ind = find(dead, parent);
            
            if(ind>0){
                sum+=pro;
                cnt++;
                
                parent[ind] = find(ind-1, parent);
            }
        }
        
        
        
        return {cnt, sum};
    }
};

int main(){
    int n;
    cin>>n;

    vector<int>deadline(n), profit(n);

    for(int i=0;i<n;i++) cin>>deadline[i];
    for(int i=0;i<n;i++) cin>>profit[i];

    Solution obj;
    vector<int>ans = obj.jobSequencing(deadline, profit);

    cout<<ans[0]<<" "<<ans[1]<<endl;

  return 0;
}
