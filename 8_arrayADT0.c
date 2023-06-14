#include<stdio.h>
#include<stdlib.h>
// creating new structure with struct
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};
// creating new array with struct data
void createArray(struct myArray * a,int tSize,int uSize){
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize*sizeof(int));
}
// creating show() for getting data from array
void show(struct myArray *a){
    for(int i = 0; i< a->used_size; i++){
        printf("%d\n",(a->ptr)[i]);
    }
}
// creating setVal() for setting data into array
void setVal(struct myArray *a){
    int n;
    for(int i = 0; i< a->used_size; i++){
        printf("Enter Element %d",i);
        scanf("%d", &n);
        (a->ptr)[i]=n;
    }
}
// main() function
int main(){
    struct myArray marks;
    createArray(&marks,10,5);
    printf("we are running setVal now\n");
    setVal(&marks);
    printf("we are running show now\n");
    show(&marks);
    return 0;
}
