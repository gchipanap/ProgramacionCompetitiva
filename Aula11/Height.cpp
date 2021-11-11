#include<stdio.h>
#include<algorithm>
#include <bits/stdc++.h>
#include<iostream>

void merge(int arr[], int l, int m, int r) 
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[],int l,int r){ 
    if(l>=r)
	{
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void mergeSort(int arr[], int size)
{
	mergeSort(arr, 0, size-1);
}

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  

  int narrays, tamarrays;

  std::cin>>narrays;
  for(int i  = 0; i < narrays; i++)
  {
    std::cin>>tamarrays;
    int arr[tamarrays];
    for(int j = 0; j < tamarrays; j++)
    {
      std::cin>>arr[j];
    }
    mergeSort(arr,tamarrays);
    for(int j = 0; j < tamarrays; j++)
    {
      std::cout<<arr[j]<<" ";
    }
    std::cout<<"\n";
  }

  return 0;
}