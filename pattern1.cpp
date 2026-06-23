//uuter loops are for rows and inner loops are for coloumns and connect with rows
//print * inside the inner loop
// observe symmetry
// 3 step is optional but above 2 are mandotry
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enetr the n";
    cin>>n;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}