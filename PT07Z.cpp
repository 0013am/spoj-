#include <bits/stdc++.h>
using namespace std;
int n; vector<int>v[10005];
int x,cnt;
pair<int,int> bfs(int src){
    cnt=0;
     int *vis=new int[n+1];
     for(int i=1;i<=n;i++){
         vis[i]=-1;
     }
     queue<int>q;
     q.push(src);
     vis[src]=0;
     while(!q.empty()){
         int node=q.front();
         x=node;
         q.pop();
         for(auto nbr:v[node]){
             if(vis[nbr]==-1){
                 vis[nbr]=vis[node]+1;
                 q.push(nbr);
             }
         }
     }
     int ml=0,idx=-1;
     for(int i=1;i<=n;i++){
         if(vis[i]>ml){
             ml=vis[i];
             idx=i;
         }
     }
     return {ml,idx};
}
int main() {
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<bfs(bfs(1).second).first;
 
    
   
}
