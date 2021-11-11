#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i,n;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(i=0; i<n; i++)
    {
        if(arr[i]%2 == 0)
            cout<<arr[i]<<endl;
    }
    for(i=n-1; i>=0; i--)
    {
        if(arr[i]%2 != 0)
            cout<<arr[i]<<endl;
    }
    return 0;
}