#include<iostream>
using namespace std;
int main() {
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size+1];
    cout<<"Enter the values: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for(int i=size;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    int val;
    cout<<"Enter the new value: ";
    cin>>val;
    arr[0]=val;
    for(int i=0;i<=size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}