#include <bits/stdc++.h>
using namespace std;
vector<int>v[10005];
int n;
void fun(int src,bool*vis){
              vis[src]=true;
              for(auto nbr:v[src]){
                            if(vis[nbr]==false){
                                          fun(nbr,vis);
              }
             
    }
}
bool go(){
              bool*vis=new bool[n+1];
              for(int i=1;i<=n;i++){
                            vis[i]=false;
              }
              int cnt=0;
              for(int i=1;i<=n;i++){
                            if(vis[i]==false){
                                          fun(i,vis);
                                          cnt++;
                            }
              }
              if(cnt==1){
                            return true;
              }
              return false;
}
int main() {
    int k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
                  int a,b;
                  cin>>a>>b;
                  if(a==b){
                                cout<<"NO";
                                return 0;
                  }
                  v[a].push_back(b);
                  v[b].push_back(a);
    }
   
    
                  if(go() && k==n-1){
                                cout<<"YES"<<endl;
                  }else{
                                cout<<"NO"<<endl;
                  }
    
	return 0;
}
