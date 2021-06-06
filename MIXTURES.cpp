#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int a[1000];
int sum(int s,int e){
    int ans=0;
    for(int i=s;i<=e;i++){
        ans+=a[i];
        ans%=100;
    }
    return ans;
}
int go(int i,int j){
   if(i>=j){
       return 0;
   }
   if(dp[i][j]!=-1){
       return dp[i][j];
   }
          dp[i][j]=INT_MAX;
            for(int k=i;k<=j;k++){
                dp[i][j]=min(dp[i][j],go(i,k)+go(k+1,j)+sum(i,k)*sum(k+1,j));
            }
        return dp[i][j];
    
}
int main() {
    int n;
    while((scanf("%d",&n))!=EOF){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        memset(dp,-1,sizeof(dp));
       cout<< go(0,n-1)<<endl;
    }
}
