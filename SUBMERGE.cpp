#include <bits/stdc++.h>
using namespace std;
vector<int>g[100000];
int disc[100000],low[100000],tme,ml;
set<int>s;
void dfs(int curr,int par){
    disc[curr]=low[curr]=tme++;
    int cnt=0;
    for(auto p:g[curr]){
        if(disc[p]==0){
            cnt++;
            dfs(p,curr);
            low[curr]=min(low[curr],low[p]);
            if(par!=-1 && low[p]>=disc[curr]){
               s.insert(curr);
            }
        }else if(p!=par){
            low[curr]=min(low[curr],disc[p]);
        }
    }
    if(par==-1 && cnt>=2){
       s.insert(curr);
    }
}
int main() {
    int a,b;
    cin>>a>>b;
    while(a!=0 && b!=0){
        for(auto& v:g) {
            v.clear();
        }
        while(b--){
            int x,y; cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        s.clear();
        memset(disc,0,sizeof(disc));
        memset(low,0,sizeof(low));
        tme=1,ml=0;
        dfs(1,-1);
        cout<<s.size()<<endl;
        cin>>a>>b;
    }
	return 0;
}
