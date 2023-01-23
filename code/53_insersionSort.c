#include<stdio.h>

void insertionsort(int * arr,int n){
    for(int i=0;i<n-1;i++){
        int element = arr[i+1];
        for(int j=i;j>=0;j--){
            if(arr[j]>element){ //(cuz positino is changing)we cant use arr[i+1]
                arr[j+1]=arr[j];
                arr[j]=element;
                
            }
            else break;
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

    insertionsort(arr,n);
    printf("Printing Sorted array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}