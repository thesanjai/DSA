#include<iostream>
using namespace std;

int f(int n)

{

static int i = 1;

if(n>=5)return n;

n = n+i;

i++;

return f(n);

}

int main(){

    cout<<f(1);
    return 0;
}