#include <bits/stdc++.h>
using namespace std;
#define int long long 
int go(int n,int k){
    if(k>n-k){
		k=n-k;
	}
	int ans=1;
	for(int i=1;i<=k;i++){
		ans*=(n-i+1);
		ans/=i;
	}
	return ans;
}
int32_t main() {
    int t;
    cin>>t;
 
    while(t--){
   int n,k;
   cin>>n>>k;
   cout<<go(n-1,k-1)<<endl;
    }
} 