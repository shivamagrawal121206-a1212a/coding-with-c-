#include<iostream>4
using namespace std;
int main()
{
int arr[100],n;
cout<<"Enter the size of array";
cin>>n;
cout<<"Enter "<<n<<" elements";
for(int i=0;i<n;i++)
cin>>arr[i];
cout<<"Enter the new value";
int val;
cin>>val;
cout<<"Enter the position";
int pos;
cin>>pos;
for(int i=n-1; i>=pos-1; i--)
arr[i+1]=arr[i];
arr[pos-1]=val;
cout<<"Elements after insertion";
for(int i=0; i<=n; i++)
cout<<arr[i]<<" ";
return 0;
}