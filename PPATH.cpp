#include <bits/stdc++.h>
using namespace std;
vector<int>primes;
vector<int>g[100005];
int dis[100001];
bool vis[100001];
bool isp(int x){
     for(int i=2;i*i<=x;i++){
         if(x%i==0){
             return false;
         }
     }
     return true;
}
bool isn(int x,int y){
    int cnt=0;
    while(x>0){
        if(x%10 != y%10){
            cnt++;
        }
        x=x/10;
        y=y/10;
    }
    if(cnt==1){
        return true;
    }
    return false;
}
void pm(){
    for(int i=1000;i<=9999;i++){
        if(isp(i)==true){
            primes.push_back(i);
        }
    }
     for(int i=0;i<primes.size();i++){
        for(int j=i+1;j<primes.size();j++){
            int a=primes[i];
            int b=primes[j];
            if(isn(a,b)==true){
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
    }
}


int  bfs(int src,int des){
  for(int i=1000;i<=9999;i++){
      dis[i]=-1;
      vis[i]=false;
  }
    queue<int>q;
    q.push(src);
    dis[src]=0;
    vis[src]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto p:g[node]){
            if(vis[p]==false){
                vis[p]=true;
                dis[p]=1+dis[node];
                q.push(p);
            }
        }
    }
   return dis[des];
}
int main() {
   int t; cin>>t;
   pm();
   while(t--){
       int a,b; cin>>a>>b;
       cout<<bfs(a,b)<<endl;
   }
}
