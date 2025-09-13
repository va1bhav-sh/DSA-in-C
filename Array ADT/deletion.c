#include <stdio.h>
void delete(int arr[],int*size,int index){
        for (int i =index; i <*size-1; i++)
        {
            arr[i]=arr[i+1];
        }
        
        (*size)--;
        
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
    int index=2;
    
    //Before deletion
    traverse(arr,size);
    delete(arr,&size,index);
    //After deletion
    traverse(arr,size);
    
    return 0;
}