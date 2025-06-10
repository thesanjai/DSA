//sum of n natural numbers
#include <stdio.h>

long int sum(int n){
    if(n==0){
        return 0;
    }
    return sum(n-1)+n;
}
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);

    printf("Sum of %d natural numbers is %ld\n",n,sum(n));
    return 0;
}