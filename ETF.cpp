#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long 
int phi[10*MAX];
void cal_totient(){
    for(int i=1;i<=1000006;i++)
      phi[i]=i;
      for(int i=2;i<=1000006;i++){
        if(phi[i]==i){
          phi[i]=i-1;
          for(int j=2*i;j<=1000006;j+=i)
            phi[j]=(phi[j]/i)*(i-1);
        }
      }
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    int n;
    cal_totient();
    while(t--){
      cin>>n;
      cout<<phi[n]<<endl;
    }
    return 0;
}
