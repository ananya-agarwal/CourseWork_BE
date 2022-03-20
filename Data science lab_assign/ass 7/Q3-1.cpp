#include <bits/stdc++.h>   //Won't work on Dev c++, works on online compilers
using namespace std;

void findElements(int arr1[],int arr2[],int n,int m)
{
    unordered_set<int> set;
    for(int i=0;i<m;i++)
    {
      set.insert(arr2[i]);   //make set of 2nd array
    }
    for(int i=0;i<n;i++)
    {
      if(set.find(arr1[i]) == set.end()) //means element not found in array 2
      {
          cout<<arr1[i]<<" ";
      }
    }
    cout<<endl;
}

int main()
{
    int n,m,i;
    cout<<"Enter size of 1st array: ";
    cin>>n;
    int arr1[n];
    cout<<"Enter elements of 1st array: ";
    for(i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter size of 2nd array: ";
    cin>>m;
    int arr2[m];
    cout<<"Enter elements of 2nd array: ";
    for(i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    cout<<"Elements present only in 1st array: ";
    findElements(arr1,arr2,n,m);
}
