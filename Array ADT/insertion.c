#include <stdio.h>
void insert(int arr[],int*size,int capacity,int index,int value){
    if (*size>=capacity)
    {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    else{
        for (int i = *size; i >index; i--)
        {
            arr[i]=arr[i-1];
        }
        arr[index]=value;
        (*size)++;
        
    }
}
void traverse(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
        
    }
    
    printf("\n");
}

int main(){
    int arr[10]={23,34,56,78,90};
    int size=5;
    int capacity=10;
    int index=3;
    int value =45;
    
    //Before insertion
    traverse(arr,size);
    insert(arr,&size,capacity,index,value);
    //After insertion
    traverse(arr,size);
    
    return 0;
}