#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[5] = { -2, 45, 0, 11, -9 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    return 0;
}
