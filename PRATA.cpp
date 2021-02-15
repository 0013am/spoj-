#include <bits/stdc++.h>
using namespace std;
 
bool can(int *a,int n,int p,int mid){
	int cnt=0;
	for(int i=0;i<n;i++){
        int c=0;
	int pp=a[i];
        int time=mid;
	while(time>0){
		time-=pp;
          if(time>=0){
              c+=1;
              pp+=a[i];
            }
	}
        cnt+=c;
        if(cnt>=p){
            return true;
          }
        }
	return  false;
}
int go(int *a,int n,int p){
	int l=0,r=10000007,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(can(a,n,p,mid)){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	int t; cin>>t;
	while(t--){
		int p; cin>>p;
		int n; cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<go(a,n,p)<<endl;
	}
} 
