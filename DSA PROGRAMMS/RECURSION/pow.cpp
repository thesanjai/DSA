#include<iostream>
using namespace std;

int pow(int m,int n){
    if(n==0){
        return 1;
    }
    return m*pow(m,n-1);

}

//efficient code

int pow1(int m,int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return pow1(m*m,n/2);
    }else{
        return m*pow1(m*m,(n-1)/2);
    }
}

int main(){

    cout<<pow(2,10)<<endl;
    cout<<pow1(2,10);
    return 0;
}