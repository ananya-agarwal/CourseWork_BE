#include<iostream>
using namespace std;
void display(int a[],int n)
{
 int i;
 cout<<"\nArray elements are : \n";
 for(i=0;i<n;i++)
 cout<<a[i]<<" ";
 cout<<endl;
}
void SelectionSort(int a[],int n)
{
 for(int i=0,j=n-1;i<j;i++,j--)
 {
 int min = a[i], max = a[i];
 int min_i = i, max_i = i;
 for (int k = i; k <= j; k++)
 {
 if (a[k] > max)
 {
 max = a[k];
 max_i = k;
 }
 else if (a[k] < min)
 {
 min = a[k];
 min_i = k;
 }
 }
 swap(a[i], a[min_i]);
 if (a[min_i] == max)
 swap(a[j], a[min_i]);
 else
 swap(a[j], a[max_i]);
 }
}
int main()
{
 int i,n;
 cout<<"Enter the number of elements : ";
 cin>>n;
 int *a = new int[n];
 cout<<"Enter array elements : \n";
 for(i=0;i<n;i++)
 cin>>a[i];
 SelectionSort(a,n);
 display(a,n);
 delete[] a;
 return 0;
}
