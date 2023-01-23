#include <stdio.h>

void selectionsort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i], minind = i;

        for (int j = i + 1; j <= n - 1; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                minind = j;
                // printf("%d\n",min);
            }
        }
        if (i != minind)
        {
            int temp = arr[i];
            arr[i] = min;
            arr[minind] = temp;
        }
    }
}

int main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array element : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionsort(arr, n);
    printf("Printing Sorted array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}