#include<stdio.h>

void display(int arr[], int n){
    // code for traversal
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    // code for insertion
    if(size>=capacity){
        return 0;
    }
    for(int i=size-1; i>=index; i--)
    /*
        start shifting elements from the last element and
        run the element till the end of the
    */
    {
        arr[i+1]=arr[i]; // shift 4th index to next 5th index
    }
    arr[index]=element;
    return 1;
}


int main(){
    int arr[100] = {7,8,12,27,88};
    int size=5, element=45, index=3;
    display(arr,size);
    int result = indInsertion(arr,size,element,100,index);
    if(result){
        printf("Inserted successfully!");
        printf("\n");
        size+=1;
        display(arr,size);
    }else{
        printf("failed!");
    }
    return 0;
}
