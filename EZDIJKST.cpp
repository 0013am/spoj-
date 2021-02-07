#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<vector<pii>>adj;
void go(int src,int n,int des){
    vector<int>dist(n+1,INT_MAX);
	set<pii>s;
	dist[src]=0;
	s.insert({0,src});
	
	while(!s.empty()){
		auto it=s.begin();
		int node=it->second;
		//int w=it->first;
		s.erase(it);
		for(pii p:adj[node]){
		       int nb=p.first; int w=p.second;
			   if(dist[node]+w < dist[nb]){
                    s.erase({dist[nb],nb});
					dist[nb]=dist[node]+w;
					s.insert({dist[nb],nb});
			   }
		}
		
	}
	if(dist[des]!=INT_MAX){
        cout<<dist[des];
    }else{
        cout<<"NO";
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		 adj.clear();
		  adj.resize(n+1);
		while(m--){
			int x,y,z;
			cin>>x>>y>>z;
			adj[x].push_back({y,z});
			//adj[y].push_back({x,z});
		}
		int src,des; cin>>src>>des;
		go(src,n,des);
		cout<<endl;
	}
	return 0;
}