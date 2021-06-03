#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define pbds tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int32_t main() {
    int n,t;
    cin>>t;
    while(t--){
    cin>>n;
    int a[n];
    pbds pb;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
int cnt=0;
for(int i=0;i<n;i++){
    cnt+=(pb.size()-pb.order_of_key(a[i]));
    pb.insert(a[i]);
}
cout<<cnt<<endl;
    }
}