#include<bits/stdc++.h>
using namespace std;

void TOH(int n,char A,char B,char C){
    if(n>0){
        TOH(n-1,A,C,B);
        cout<<"Move disk "<<n<<" from rod "<<A<<" to rod "<<C<<endl;
        TOH(n-1,B,A,C);
    }
}

int main(){
    TOH(3,'A','B','C');
    return 0;
}