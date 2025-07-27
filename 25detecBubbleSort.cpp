#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; ++j)
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
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = { -2, 45, 0, 11, -9 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, 5);
    return 0;
}
