#include<stdio.h>


void printarray(int * arr,int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
void bubblesortAdaptive( int * arr,int n){
    int flag =0,i,j,temp;
    for(i=0;i<n-1;i++){
        printf("working on pass no %d \n",i+1);
        flag=0;                     // HERE COMES THE ADAPTIVE PART
        for(j=i;j<n-1-i;j++ ){
            if(arr[j]>arr[j+1]){
                temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){return;}
    }
    
}

void bubbleSort(int * A, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // For number of pass
    {

        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }  
    } 
}

int main(){
    int n;
    printf("Enter array size : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array element : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr,5);
    printf("Printing Sorted array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}