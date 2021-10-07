#include <iostream>
#include <vector>
#include <cmath>

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

int igualar(std::vector<int> arr, int target, int i)
{
  int min = arr[i], max = arr[i+target-1];
  int posmin = i, posmax=i+target-1;
  int* tmp = new int [target];
  for(int j = i; j < i+target; j++)
  {
    tmp[j-i] = arr[j];
  }

  mergeSort(tmp, target);

  int cost = 0;
  int mid = abs((tmp[target]-tmp[0])/2);
  cost += mid*2;
  tmp[target-1] -= mid;
  tmp[0] += mid;

  int reference = tmp[target/2];
  for(int j = 0; j < target; j++)
  {
    if(tmp[j] != reference)
      if(tmp[j] > reference)
        cost += tmp[j] - reference;
      else if (tmp[j] < reference)
        cost += reference - tmp[j];
  }

  std::cout<<cost<<"\n";
  return cost;

}

std::vector<int> slidingCost(std::vector<int> arr, int target)
{
  int cost;
  std::vector<int> tmp;
  for(int i = 0; i < arr.size()-target+1; i++)
  {
    cost = igualar(arr, target, i);
    tmp.push_back(cost);
  }
  return tmp;
}

int main() {
  std::vector<int> data{2, 4, 3, 5, 8, 1, 2, 1};
	int target{3};

  slidingCost(data, target);
  
  return 0;
}