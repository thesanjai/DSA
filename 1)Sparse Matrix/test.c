#include<stdio.h>
#include<stdlib.h>
#include<string.h>


enum var{SUCCESS,SCANF_FALIURE};

int main(){

    char name[7];
    printf("Enter the name: ");
  if( scanf("%s",name)==0){

    perror("Error in scanf");
    
    exit(257);
  }

   printf("name => %s\n",name);

   printf("%d\n%d\n",SUCCESS,SCANF_FALIURE);

    
   
    return 0;
}