#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int data;
    struct Node *next;
}NODE;

NODE *first =NULL;

void CreateLL(){
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);

    NODE *p,*last;

    first = (NODE*)malloc(sizeof(NODE));
    first->data = rand()%10;
    first->next = NULL;
    last=first;

    for(int i=1;i<n;i++){
      p = (NODE*)malloc(sizeof(NODE));
      p->data = rand()%20;
      p->next = NULL;
      last->next = p;
      last = p;
    }
    
}
void DisplayLL(NODE *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    srand(time(NULL));
    CreateLL();
    DisplayLL(first);

    putchar('\n');
    return 0;
}