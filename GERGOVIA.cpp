#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main() {
	
	while(1){
	    int n; cin>>n;
	    if(n==0){
	        break;
	    }
	    int cs=0,x=0,ans=0;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        cs+=x;
	        ans+=(abs(cs));
	    }
	    cout<<ans<<endl;
	   
	}
	return 0;
}
