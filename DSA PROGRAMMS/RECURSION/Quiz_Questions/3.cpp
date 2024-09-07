/*What is the return value of f(p, p), if the value of p is initialised to 5 before the call?
 Note that the first parameter is passed by reference, whereas the second parameter is passed by value. */
#include<iostream>
using namespace std;

int f (int &x, int c) 

{
c = c - 1; 
if (c == 0) return 1; 
x = x + 1; 
return f(x,c) * x;
}

int main(){
    int a=5;
    cout<<f(a,5);
    return 0;
}