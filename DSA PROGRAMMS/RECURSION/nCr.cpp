#include<bits/stdc++.h>
using namespace std;

#define fact(n) ({ \
    int ans = 1; \
    for (size_t i = 1; i <= (n); i++) { \
        ans *= i; \
    } \
    ans; \
})


/*
nCr =  n!
      ------
       r!(n-r)!
*/

int nCr_iterative(int n,int r){
    int t1 = fact(n);
    int t2 = fact(r);
    int t3 = fact(n-r);
    return t1/(t2*t3);
}

//nCr is exact similar to the Pascal's Trianle

int nCr(int n,int r){
    if(r==0 || r==n){
        return 1;
    }else{
        return nCr(n-1,r-1)+ nCr(n-1,r);
    }
}

int main(){

    cout<<nCr_iterative(5,5)<<endl;
    cout<<nCr(5,5)<<endl;
    return 0;
}