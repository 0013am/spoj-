#include <bits/stdc++.h>
using namespace std;
vector<int>l[2001];
int mark[2001];
bool dfs(int node,int parent,int clr){
    mark[node]=clr;
    for(auto p:l[node]){
        if(mark[p]==0){
            bool res=dfs(p,node,3-clr);
            if(res==true){
                return true;
            }
        }else if(p!=parent and clr==mark[p]){
            return true;
        }
    }
return false;
}
int main() {
    int t; cin>>t;
    for(int tc=1;tc<=t;tc++){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            l[i].clear();
            mark[i]=0;
        }
        while(m--){
            int a,b;
            cin>>a>>b;
            a--,b--;
            l[a].push_back(b);
            l[b].push_back(a);
        }
       bool flag =true;
       for(int i=0;i<n;i++){
           if(mark[i]==0){
               bool res=dfs(i,-1,1);
               if(res==true){
                   flag=false;
               }
           }
       }
        if(flag==true){
            cout<<"Scenario #"<<tc<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        }else{
             cout<<"Scenario #"<<tc<<":"<<endl;
            cout<<"Suspicious bugs found!"<<endl;
        }
    }
}
 