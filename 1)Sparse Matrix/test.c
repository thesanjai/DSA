#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct points{
    int x,y;
}point;

void create(point* p){
    p->x=10;
    p->y=20;
}

int main(int argc,char** argv){

    printf("%ld\n",strlen("ip_matrix_A.txt"));
     printf("%ld\n",sizeof("ip_matrix_A.txt"));


     printf("%d %c",48,48);

    return 0;
}