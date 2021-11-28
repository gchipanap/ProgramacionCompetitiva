/*
P2. Broken Keyboard
https://www.beecrowd.com.br/judge/en/problems/view/1642
*/

#include <stdio.h>   
#include<cstring>  
#include<iostream>  
using namespace std;  

char a[1000005];  
int t1,t2,l,r,n,res,len;  
int b[500];  

int main()
{  
  while(scanf("%d",&n) && n)
  {  
    memset(b,0,sizeof(b));  
    getchar();  
    gets(a);  
    len=strlen(a);  
    t1=t2=res=0;  
    l=r=0;  
    while(l<=r && r<len)
    {
      while(t1<=n && r<len)
      {
        if(b[a[r]]==0) 
        {
          b[a[r]]=1; t1++;  
          if(t1>n)     
            break;  
        }  
        else 
          b[a[r]]++;  
        r++;
        t2++;
    }  
    if(t2>res) 
      res=t2;
    if(r>=len) 
      break;
    while(1)
    {  
      b[a[l]]--;  
      if(b[a[l]]==0) 
        break;  
      l++; 
      t2--;  
    }  
    l++; t1--; r++;  
    }  
    printf("%d\n",res);  
}  
return 0;  
}  