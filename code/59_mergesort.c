#include <stdio.h>
#include<stdlib.h>
void merge(int A[], int mid, int low, int high)
{

    int i = low, j = mid, k = low;// B[high-low+1];  == we have to dynamically allocate memory
    int * B=(int *)malloc((high-low+1)*sizeof(int));
    while (i < mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i < mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int q = low; q <= high; q++)
    {
        A[q] = B[q];
    }
    free(B);
}

void mergesort(int A[], int low, int high)
{
    int mid;
    mid=(low +high)/2;
    if (low < high)
    {
        mergesort(A, low, mid);
        mergesort(A, mid+1, high);
        merge(A, mid, low, high);
        return;
    }
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    int * arr=(int *)malloc(sizeof(int));
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}
// #include <stdio.h>

// void printArray(int *A, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", A[i]);
//     }
//     printf("\n");
// }

// void merge(int A[], int mid, int low, int high)
// {
//     int i, j, k, B[100];
//     i = low;
//     j = mid + 1;
//     k = low;

//     while (i <= mid && j <= high)
//     {
//         if (A[i] < A[j])
//         {
//             B[k] = A[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             B[k] = A[j];
//             j++;
//             k++;
//         }
//     }
//     while (i <= mid)
//     {
//         B[k] = A[i];
//         k++;
//         i++;
//     }
//     while (j <= high)
//     {
//         B[k] = A[j];
//         k++;
//         j++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         A[i] = B[i];
//     }

// }

// void mergeSort(int A[], int low, int high){
//     int mid;
//     if(low<high){
//         mid = (low + high) /2;
//         mergeSort(A, low, mid);
//         mergeSort(A, mid+1, high);
//         merge(A, mid, low, high);
//     }
// }

// int main()
// {
//     // int A[] = {9, 14, 4, 8, 7, 5, 6};
//     int A[] = {9, 1, 4, 14, 4, 15, 6};
//     int n = 7;
//     // printArray(A, n);
//     int arr[] = {10, 20, 40, 50, 1, 15, 23, 34};
//     merge(arr,0,3,7);
//     // mergeSort(A, 0, 6);
//     printArray(arr, n);
//     return 0;
// }
