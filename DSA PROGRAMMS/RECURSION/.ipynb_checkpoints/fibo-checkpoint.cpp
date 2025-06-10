#include <bits/stdc++.h>
using namespace std;

#define max 100000
static int arr[max];

#define setNegative(arr){\
    for(size_t i=0;i<10000;i++) (arr[i]) = -1;\
}\

int fibo(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibo(n-2)+fibo(n-1);
}
//TIME COMPLEXITY = O(2^n)

/*
    some function call is called repeated its creates an exessive recursion
    to avoid this we can use dynamic programming (Memorization) approach
*/
//EFFICIENT CODE

int fibo_eff(int n){
    if(n==0 || n==1){
        arr[n] = n;
        return n;
    }

    if(arr[n-2] == -1){
        arr[n-2] = fibo_eff(n-2);
    }

     if(arr[n-1] == -1){
        arr[n-1] = fibo_eff(n-1);
    }

    return arr[n-2] + arr[n-1];
}


int main(){
    setNegative(arr);
    int n=6;
    cout<<fibo(n)<<endl;
    cout<<fibo_eff(n);
}