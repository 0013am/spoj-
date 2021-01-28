#include <bits/stdc++.h>
using namespace std;
vector<int>g[10001];
vector<int>ans;
int ind[10001];
bool go(int n){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int tp=pq.top();
        ans.push_back(tp);
        pq.pop();
        for(auto p:g[tp]){
           ind[p]--;
           if(ind[p]==0){
               pq.push(p);
           }
        }
    }
    return ans.size()==n;
}
int main() {
   int n,m;
   cin>>n>>m;
   while(m--){
       int a,b;
       cin>>a>>b;
       a--,b--;
       g[a].push_back(b);
       ind[b]++;
   }
   if(go(n)==false){
       cout<<"Sandro fails."<<endl;
   }else{
       for(auto x:ans){
           cout<<x+1<<" ";
       }
   }
}