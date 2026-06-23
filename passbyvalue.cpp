#include<iostream>
using namespace std;
void modify(int x){
    x=x+20;
}
int main(){
    int a=10;
    modify(a);
    cout<<a;
    return 0;
}
