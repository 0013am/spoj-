#include <bits/stdc++.h>
using namespace std;
#define MAX 100006
#define ll long long 
vector<int> adj[MAX];
int phi[10*MAX];
int dp[10*MAX];
int fun(int n){
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = 1 + fun(phi[n]);
}
void cal_totient(){
    for(int i=1;i<=1000006;i++)
      phi[i]=i;
      for(int i=2;i<=1000006;i++){
        if(phi[i]==i){
          phi[i]=i-1;
          for(int j=2*i;j<=1000006;j+=i)
            phi[j]=(phi[j]/i)*(i-1);
        }
      }
      memset(dp, -1, sizeof dp);
    for(int i=1; i<1000006; i++)
        adj[fun(i)].push_back(i);     
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    int n;
    cal_totient();
    while(t--){
      int l,r,k; cin>>l>>r>>k;
      int ans=0;
      ans = upper_bound(adj[k].begin(), adj[k].end(), r)-lower_bound(adj[k].begin(), adj[k].end(), l);
      cout<<ans<<endl;
    }
    return 0;
}
