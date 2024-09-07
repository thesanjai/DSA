#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;

    for(size_t i=0;i<n;i++){
        int number = 1;
        for(size_t j=0;j<=i;j++){
            cout<<" "<<number;
            number = number * (i-j) / (j+1);
        }
        cout<<endl;
    }
}