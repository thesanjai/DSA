#include<stdio.h>
#include<stdlib.h>


typedef struct Element{
    int i;//row
    int j;//col
    int x;//non-zero value
}Element;

typedef struct Sparse_Matrix{
    int m; //matrix row
    int n; //matrix col
    int num; // no. of non zero elements
    Element* ele;
}Sparse_Matrix;

void Create_Sparse_Matrix(Sparse_Matrix* s){
    printf("Enter the Diemenions of the matrix(m x n): ");
    scanf("%d%d",&s->m,&s->n);

    printf("Enter the no. of non zero elements: ");
    scanf("%d",&s->num);

    s->ele =(Element*) calloc(s->num,sizeof(Element));
    for(int i=0;i<s->num;i++){
        printf("Enter the row, col and value of element %d: ",i+1);
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }
}

void Create_Sparse_Matrix_from_file(Sparse_Matrix *s) {

    char choice[16];// 15 for filename & 1 space for null character
    printf("Choose the Available input file: \n");
    printf("1. ip_matrix_A.txt\n");
    printf("2. ip_matrix_B.txt\n");
    printf("(or)Enter your own input file:-\n");
    printf("[Enter]>>>");
    scanf("%15s",choice); //to prevent bufferoverflow

    //printf("choice => %s\n",choice);
    char* filename;

    switch(choice[0]-'0'){
        case 1:
                filename="ip_matrix_A"; //ip_matrix_A.txt & ip_matrix_A both are different files
                break;
        case 2:
                filename="ip_matrix_B";
                break;
        default:
                if(choice[0]> 57){// 57 is ASCII of 9 to check given input is not a integer number
                    filename=choice;
                }else if(choice[0] >=47 && choice[0] <= 58){//USING ASCII 47 -> 0 && 58 -> 9
                    printf("Invalid choice\n");
                    return;
                }
    }
    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found\n");
        return;
    }
    fscanf(fp, "%d%d%d", &s->m, &s->n, &s->num);
    s->ele = (Element*) calloc(s->num, sizeof(Element));
    for (int i = 0; i < s->num; i++) {
        fscanf(fp, "%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
    fclose(fp);
}


void display(Sparse_Matrix s){

    int k=0;
    printf("The Sparse Matrix is:\n");
    for(int i=1;i<=s.m;i++){
        for(int j=1;j<=s.n;j++){
            if(i==s.ele[k].i && j==s.ele[k].j){
                printf("%d ",s.ele[k].x);
                k++;
            }else{
                printf("0 ");
            }
        }
        putchar('\n');
    }
}
int main(int argc,char** argv){

    
    Sparse_Matrix A;

    char c;
    printf("Do you want to create your own matrix?(y/n): ");
    //c=getchar(); dont use getchar it leads to  stack smashing , because The getchar() function reads a character from the standard input, but it does not consume the newline character (\n) that is entered after the character.  
    scanf("%c",&c);
    if(c=='y' || c=='Y'){
        Create_Sparse_Matrix(&A);
    }else if(c=='n' || c=='N'){
        Create_Sparse_Matrix_from_file(&A);
    }else{
        printf("Invalid Input\n");
        return 1;
    }
    
    display(A);
    return 0;
}