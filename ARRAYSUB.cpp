#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i,k; cin>>k;

    deque<int>q;
    for(i=0;i<k;i++){
        while(!q.empty() and a[i]>a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(;i<n;i++){
        cout<<a[q.front()]<<" ";
        while(!q.empty() and q.front()<=i-k){
            q.pop_front();
        }
        while(!q.empty() and a[i]>a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<a[q.front()];

}
