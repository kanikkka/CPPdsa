#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"enter the array elemnt";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(n==0 || n==1){
        cout<<-1<<endl;
    }
        sort(arr,arr+n); 
         int small=arr[1];
         int large=arr[n-2];        
    

    cout<<"slargest"<<large<<" ";

}
