#include <bits/stdc++.h>   //Won't work on Dev c++, works on online compilers
using namespace std;

void printPairs(int arr[],int n,int sum)
{
    unordered_set<int> set;
    for(int i=0;i<n;i++)
    {
       int saathi = sum - arr[i];  // if saathi is found, we have a pair of arr[i] and saathi
       if(set.find(saathi) != set.end()) 
       {
           cout<<"Pair of elements whose sum is "<<sum<<" is: "<<"("<<arr[i]<<","<<saathi<<")";
       }
       set.insert(arr[i]);  //set is always empty at start, so insert will surely work on 1st iteration
    }
}

int main()
{
    int n,i,sum;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter required sum: ";
    cin>>sum;
    printPairs(arr,n,sum);
}
