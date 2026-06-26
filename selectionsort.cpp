#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the array elements";
    cin>>n;
    int arr[n];
    cout<<"enter the array element";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    swap(arr[min],arr[i]);
    
}
    
    cout<<"after selction sort";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}