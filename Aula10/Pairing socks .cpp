#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stack>

using namespace std;

int main()
{
    int n;
    int a[100000];
    int b[100000];
    while(cin>>n)
    {
        int i;
        n*=2;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int k = -1;
       i = 0;
       while(i<n)
       {
           if(k==-1)
           {
               b[++k] = a[i];
               i++;
           }
           else
           {
               if(b[k]==a[i])
               {
                   i++;
                   k--;
               }
               else
               {
                   b[++k] = a[i];
                   i++;
               }
           }
       }
       if(k==-1)
        printf("%d\n",n);
       else
        printf("impossible\n");
    }
    return 0;
}