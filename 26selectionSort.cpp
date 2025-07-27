#include<iostream>
using namespace std;

void selectionsort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int mainindex = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[mainindex])
                mainindex = j;
        }
        swap(arr[i], arr[mainindex]);
    }
    for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[5] = {5,2,-5,3,1};
    selectionsort(arr, 5);
    return 0;
}

