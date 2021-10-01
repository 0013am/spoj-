#include <bits/stdc++.h>
using namespace std;
void up(vector<int>&v,int i,int val){
    while(i<=v.size()){
        v[i]+=val;
        i+=(i&(-i));
    }
}
int query(int i,vector<int>&v){
    int ans=0;
    while(i>=1){
        ans+=v[i];
        i-=(i&(-i));
    }
    return ans;
}
int main() {
	int t; cin>>t;
	while(t--){
	    int n,m; cin>>n>>m;
	    vector<int>v(n+1,0);
	    while(m--){
	        int l,r,val;
	        cin>>l>>r>>val;
	        up(v,l+1,val);
	        up(v,r+2,-val);
	    }
	    int q; cin>>q;
	    while(q--){
	        int idx; cin>>idx;
	        int res=query(idx+1,v);
	        cout<<res<<endl;
	    }
	}
	return 0;
}
