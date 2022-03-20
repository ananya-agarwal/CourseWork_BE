#include <bits/stdc++.h>   //Won't work on Dev c++, works on online compilers
using namespace std;

int mostFrequent(int arr[],int n)
{
    unordered_map<int,int> hashMap;
    for(int i=0;i<n;i++)
    {
        hashMap[arr[i]]++;   //Storing key and value pair where arr[i] is key
    }
    int max_freq=0, most_frequent_element=-1;
    for(auto i : hashMap)
    {
        if(max_freq<i.second)  //i.first is key and i.second is value
        {
            max_freq = i.second;
            most_frequent_element = i.first;
        }
    }
    return most_frequent_element;
}

int main()
{
    int n,i;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Most frequent element is "<<mostFrequent(arr,n)<<endl;
}
