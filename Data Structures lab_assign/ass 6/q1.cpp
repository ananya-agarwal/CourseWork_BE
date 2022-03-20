#include<iostream>
using namespace std;


void SelectionSort(int arr[],int n)
{
 int i,j,k;
 for(i=0;i<n;i++)
 {
 int min = arr[i];
 k = i;
 for(j=i+1;j<n;j++)
 {
 if(arr[j] < min)
 {
 min = arr[j];
 k = j;
 }
 }
 int t = arr[i];
 arr[i] = arr[k];
 arr[k] = t;
 }
}
void InsertionSort(int arr[],int n)
{
 int i,j;
 for(i=1;i<n;i++)
 {
 int temp = arr[i];
 for(j=i-1;j>=0 && arr[j]>temp;j--)
 arr[j+1] = arr[j];
 arr[j+1] = temp;
 }
}
void BubbleSort(int arr[],int n)
{
 int i,j;
 for(i=0;i<n-1;i++)
 {
 int flag = 0;
 for(j=0;j<n-i-1;j++)
 {
 if(arr[j] > arr[j+1])
 {
 int t = arr[j];
 arr[j] = arr[j+1];
 arr[j+1] = t;
flag = 1;
 }
 }
 if(flag == 0)
 break;
 }
}
void merge(int arr[],int l,int m,int r)
{
 int i,j,k;
 int n1 = m - l + 1;
 int n2 = r - m;
 int *arr1 = new int[n1];
 int *arr2 = new int[n2];
 for(i=0;i<n1;i++)
 arr1[i] = arr[l + i];
 for(j=0;j<n2;j++)
 arr2[j] = arr[m + j + 1];
 i = j = 0;
 k = l;
 while(i<n1 && j<n2)
 {
 if(arr1[i] <= arr2[j])
 {
 arr[k] = arr1[i];
 i++;
 }
 else
 {
 arr[k] = arr2[j];
 j++;
 }
 k++;
 }
 while(i<n1)
 {
 arr[k] = arr1[i];
 i++;
 k++;
 }
 while(j<n2)
 {
 arr[k] = arr2[j];
 j++;
 k++;
 }
 delete[] arr1;
 delete[] arr2;
}
void MergeSort(int arr[],int l,int r)
{
 if(r>l)
 {
 int m = (l + r)/2;
 MergeSort(arr,l,m);
 MergeSort(arr,m+1,r);
 merge(arr,l,m,r);
 }
}
void ShellSort(int arr[],int n)
{
 int gap,i,j;
 for(gap=n/2;gap > 0;gap/=2)
 {
 for(i=gap;i<n;i++)
 {
 int temp = arr[i];
 for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
 {
 arr[j] = arr[j - gap];
 }
 arr[j] = temp;
 }
 }
}
int Partition(int arr[],int p,int r)
{
 int x = arr[r];
 int i = p - 1;
 int j,t;
 for(j=p;j<r;j++)
 {
 if(arr[j]<=x)
 {
 i++;
 t = arr[i];
 arr[i] = arr[j];
 arr[j] = t;
 }
 }
 i++;
 t = arr[i];
 arr[i] = arr[r];
 arr[r] = t;
 return i;
}
void QuickSort(int arr[],int p,int r)
{
 if(p < r)
 {
 int q =Partition(arr,p,r);
 QuickSort(arr,p,q-1);
 QuickSort(arr,q+1,r);
 }
}
void CountingSort(int arr[],int n)
{
 int i,j,k;
 k = arr[0];
 for(i=1;i<n;i++)
 {
 if(arr[i] > k)
 k = arr[i];
 }
 int *c = new int[k+1];
 int *b = new int[n+1];
 for(i=0;i<=k;i++)
 c[i] = 0;
 for(i=0;i<n;i++)
 c[arr[i]]++;
 for(i=1;i<=k;i++)
 c[i] += c[i-1];
 for(i=n-1;i>=0;i--)
 {
 b[c[arr[i]]] = arr[i];
 c[arr[i]]--;
 }
 for(i=0;i<n;i++)
 arr[i] = b[i+1];
}
void display(int arr[],int n)
{
 int i;
 cout<<"\nArray elements are as follows : \n";
 for(i=0;i<n;i++)
 cout<<arr[i]<<" ";
 cout<<endl;
}
int main()
{
 int i,n;
 cout<<"Enter the required number of elements in the array: ";
 cin>>n;
 int *arr = new int[n];
 cout<<"Enter elements in array : \n";
 for(i=0;i<n;i++)
 cin>>arr[i];
 int arr_size = sizeof(arr) / sizeof(arr[0]);
 
 cout<<"SELECTION SORT:";
 SelectionSort(arr,n);
 display(arr,n);
 cout<<"\nINSERTION SORT:";
 InsertionSort(arr,n);
 display(arr,n);
 cout<<"\n BUBBLE SORT:";
 BubbleSort(arr,n);
 display(arr,n);
 cout<<"\n MERGE SORT:";
 MergeSort(arr,0,arr_size - 1);
 display(arr,n);
 cout<<"\n QUICK SORT:";
 QuickSort(arr,0,arr_size - 1);
 display(arr,n);
 cout<<"\n COUNTING SORT:";
 CountingSort(arr,n);
 display(arr,n);
 
 delete[] arr;
 return 0;
}
