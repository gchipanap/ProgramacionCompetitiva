/*
2. How Many Digits?
https://open.kattis.com/problems/howmanydigits
*/

#include<bits/stdc++.h>
using namespace std;
double ans[1000000]={0};
int main(){
    int n;
    for(int i=1;i<=1000000;i++){
            ans[i]+=ans[i-1]+log10(i);
        }
    while(cin>>n){
        cout<<int(ans[n]+1)<<endl; 
    }
}