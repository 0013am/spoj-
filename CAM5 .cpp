#include <bits/stdc++.h>
using namespace std;
int n; vector<int>v[100005];
void dfs(int src,bool*vis){
    vis[src]=true;
    for(auto nbr:v[src]){
        if(vis[nbr]==false){
            dfs(nbr,vis);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,k;cin>>t;
    while(t--){
    cin>>n>>k;
   for(int i=0;i<=n;i++){
       v[i].clear();
   }
    for(int i=0;i<k;i++){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt=0;
    bool *vis=new bool[n];
    for(int i=0;i<n;i++){
        vis[i]=false;
    }

    for(int i=0;i<n;i++){
        if(vis[i]==false){
            cnt++;
            dfs(i,vis);
        }
    }
   cout<<cnt<<endl;
}
 
    
   
}
