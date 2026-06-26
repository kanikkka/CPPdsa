#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enetr the number of n";
    cin>>n;
    int arr[n];
    cout<<"enetr the array element";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n-1; i++){
    for(int j=0; j<n-i-1; j++){
        if(arr[j]>arr[j+1]){
         swap(arr[j],arr[j+1]);
        }
    }
}
   cout<<"after sorting";
   for(int i=0; i<n; i++){
   cout<<arr[i]<<" ";
   }
   return 0;
}