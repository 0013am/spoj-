#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int go(int x,int y,int cnt,bool f){
    if(x<=0 || y<=0){
        return cnt;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    if(f){
        dp[x][y]=max(dp[x][y],go(x+3,y+2,cnt+1,!f));
    }
    return dp[x][y]=max(dp[x][y],max(go(x-20,y+5,cnt+1,!f),go(x-5,y-10,cnt+1,!f)));
    
}
int main() {
	int t; cin>>t;
	while(t--){
	    int x,y;
	    cin>>x>>y;
	    bool f=true;
	    memset(dp,-1,sizeof(dp));
	    cout<<go(x,y,-1,f)<<endl;
	}
	return 0;
}
