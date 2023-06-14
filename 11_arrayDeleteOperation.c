#include<stdio.h>
void display(int arr[], int n){
    // code for traversal
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int indDeletion(int arr[], int size, int index)
{ // code for Deletion
    for(int i=index; i<size-1; i++) /* start shifting elements from the index element and continue shifting the elements till the end of the array */
    {
        arr[i]=arr[i+1]; // shift 4th index to next 3rd index
    }
    return 1;
}
int main(){
    int arr[100] = {7,8,12,27,88};
    int size=5, index=2;
    display(arr,size);
    indDeletion(arr,size,index);
    printf("Deleted successfully!");
    printf("\n");
    size-=1;
    display(arr,size);
    return 0;
}
