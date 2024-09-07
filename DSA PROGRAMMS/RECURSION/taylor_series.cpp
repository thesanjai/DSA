#include <iostream>
using namespace std;

int e(int x,int n){
    static int S =1;
    if(n==0){
        return S;
    }

    S *= 1+(x/n);
    return e(x,n-1);
}
int main(){
    cout<<e(10,20);
}