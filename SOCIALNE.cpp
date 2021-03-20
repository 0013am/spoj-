#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin>>t;
  while(t--){
      string line,mat[10005];
      int dp[10005]={0};
      cin>>line;
      mat[0]=line;
      int l=line.size();
      for(int i=1;i<l;i++){
          cin>>mat[i];
      }
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                if(mat[i][j]=='N'){
                    for(int k=0;k<l;k++){
                        if(mat[i][k]=='Y'&& mat[k][j]=='Y'){
                            dp[i]++;
                            dp[j]++;
                            break;
                        }
                    }
                }
            }
        }
        int ml=0,e=0;
        for(int i=0;i<l;i++){
            if(dp[i]>ml){
                ml=dp[i];
                e=i;
            }
        }
        cout<<e<<" "<<ml<<endl;;
  }
}
