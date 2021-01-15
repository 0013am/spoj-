#include <bits/stdc++.h>
using namespace std;
#define int long long
int k;
#define MOD 1000000000
vector<int> b,c;
vector<vector<int>> multiply(vector<vector<int>>A,vector<vector<int>>B){
    vector<vector<int >> C(k+1,vector<int>(k+1));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int v=1;v<=k;v++){
                C[i][j]=(C[i][j]+(A[i][v]*B[v][j])%MOD)%MOD;
            }
        }
    }
    return C;
}
vector<vector<int>> fun(vector<vector<int>>A,int p){
       if(p==1){
           return A;
       }
       if(p&1){
           return multiply(A,fun(A, p-1));
       }else{
           vector<vector<int>> h=fun(A,p/2);
           return multiply(h,h);
       }
}
int go(int n){
    if(n==0){
        return 0;
    }
    if(n<=k){
        return b[n-1];
    }
    vector<int>F1(k+1);
    for(int i=1;i<=k;i++){
        F1[i]=b[i-1];
    }
    vector<vector<int>> T(k+1,vector<int>(k+1));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(i<k){
               if(j==i+1){
                   T[i][j]=1;
               }else{
                   T[i][j]=0;
               }
               continue;
            }
            T[i][j]=c[k-j];
        }
    }
     T=fun(T,n-1);
    int ans=0;
    for(int i=1;i<=k;i++){
        ans=(ans+(T[1][i]*F1[i])%MOD)%MOD;
    }
    return ans;
}
int32_t main() {
   int t;
   cin>>t;
   while(t--){
       cin>>k;
       for(int i=0;i<k;i++){
           int num;cin>>num;
           b.push_back(num);
       }
        for(int i=0;i<k;i++){
           int num;cin>>num;
           c.push_back(num);
       }
       int n; cin>>n;
       cout<<go(n)<<endl;
       b.clear();
       c.clear();
   }
}
