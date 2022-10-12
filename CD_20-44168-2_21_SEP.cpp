#include<iostream>
using namespace std;
int main(){

///ODD or EVEN
/*int x;
cout<<"Take the input to check ODD/EVEN : ";
cin>>x;

if(x%2==0)
{
    cout<<"\nThe NUMBER is EVEN\n";
}
else
    cout<<"\nThe NUMBER is ODD\n";*/


///Largest Number from an array

    /*int i,n, arr[100];
    cout<<"Enter the size: ";
    cin>>n;

    for(i=0; i<n; i++){
    cout<<"Take input "<< i+1<< " to check the highest number : ";
    cin>>arr[i];}

    for(i=1; i<n; i++){
        if(arr[0]<arr[i]){
        arr[0]=arr[i];}
    }
    cout<<"Largest No : "<<arr[0];*/


///Smallest Number from an array

    /*int i,n, arr[100];
    cout<<"Enter the size: ";
    cin>>n;

    for(i=0; i<n; i++){
    cout<<"Take input "<< i+1<< " to check the smallest number : ";
    cin>>arr[i];}

    for(i=1; i<n; i++){
        if(arr[0]>arr[i]){
        arr[0]=arr[i];}
    }
    cout<<"Smallest No : "<<arr[0];*/


///Function
int x=10;
int y=20;

cout<<"Value of x before : "<<x;
cout<<"\nValue of y before : "<<y;

swap(x,y);
cout<<"\nValue of x after  : "<<x;
cout<<"\nValue of y after  : "<<y;





}
