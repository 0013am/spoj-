#include <bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2;
 int a[26];
 int dp[2001][2001];
int go(int i,int j){
   if(i==n || j==m){
       return 0;
   }
   if(dp[i][j]!=-1){
       return dp[i][j];
   }
   if(s1[i]==s2[j]){
       return a[s1[i]-'a']+go(i+1,j+1);
   }
   return dp[i][j]=max(go(i+1,j),go(i,j+1));
}
int main() {
  
  cin>>n>>m;
 memset(dp,-1,sizeof(dp));
  for(int i=0;i<26;i++){
      cin>>a[i];
  }
  cin>>s1>>s2;
  cout<<go(0,0);
}