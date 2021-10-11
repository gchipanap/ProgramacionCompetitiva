#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
int t;
cin>>t;
while(t--){
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int ans=INT_MIN;
    multiset<int> second;
    for(int i=1; i<=n; ++i)cin>>a[i];
    for(int i=1; i<=min(n,k+2); ++i){
        second.insert(a[i]);
        ans=max(ans,*second.rbegin()-*second.begin());
    }
    for(int i=k+3; i<=n; ++i){
        second.erase(second.find(a[i-k-2]));
        second.insert(a[i]);
        ans=max(ans,*second.rbegin()-*second.begin());
    }
    cout<<ans<<"\n";
}
return 0;
}