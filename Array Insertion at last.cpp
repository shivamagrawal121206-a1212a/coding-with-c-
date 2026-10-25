#include<iostream>
using namespace std;
int main()
{
    int arr[100],n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter "<<n<<" values";
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"You had entered the following values: ";
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nInsert new values: ";
    int val;
    cin>>val;
    arr[n]=val;
    cout<<"After insertion of new value array is: ";
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}