#include <bits/stdc++.h> 
using namespace std;  
#define n 1000002 
#define int long long 
int phi[n+2],ans[n+2]; 
void ETF(){ 
    for (int i=1;i<= n;i++){ 
        phi[i]=i; 
    } 
    for (int i=2;i<=n;i++){ 
        if (phi[i]==i) { 
            phi[i]=i-1; 
            for (int j=2*i;j<=n;j+=i) { 
                phi[j]=(phi[j]*(i-1))/i; 
            } 
        } 
    } 
} 
void fun(){ 
    ETF(); 
    for (int i=1;i<=n;i++){ 
        for (int j=i;j<=n;j+=i){ 
            ans[j]+=(i*phi[i]); 
        } 
    } 
}
int32_t main() { 
    int t; cin>>t;
    fun();
    while(t--){
        int m; cin>>m;
        int res=ans[m]; 
        res=(res+1)*m; 
        res=res/2; 
    cout<<res<<endl; 
    }
    return 0; 
} 