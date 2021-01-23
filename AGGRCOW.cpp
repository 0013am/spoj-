#include<bits/stdc++.h>
using namespace std;
bool go(int *a,int n,int k,int mid){
	int cow=1;
	int lc=0;
	int i=1;
	while(i<n){
		if(a[i]-a[lc]>=mid){
			cow++;
			lc=i;
		}
		i++;
	}
	if(cow<k){
		return false;
	}
	return true;
}
int main() {
	int t; cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int ans=0;
	int l=0;
	int r=a[n-1];
	while(l<=r){
		int mid=l+r;
		mid>>=1;
		if(go(a,n,k,mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	}
	return 0;
} 