#include<iostream>
using namespace std;
int main(){
    int day;
    cout<<"enetr the day";
    cin>>day;
       switch(day){
        case 1:
        cout<<"today is monday";
        break;
        case 2:
        cout<<"today is tuesday";
        break;
        case 3:
        cout<<"today ie wednesday";
        break;
        default:
        cout<<"default is matched";
        break;
       } 
}