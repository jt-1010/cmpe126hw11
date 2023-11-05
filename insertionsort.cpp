#include <iostream>

using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int left, int right) 
{
    for (int i = left + 1; i <= right; i++) 
    {
        //unsorted
        int key = arr[i];
        int j = i-1;

         while (j >= left && arr[j] > key) 
         {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}

int main() {
    int arr[] = {12, 5, 99, 34, 23, 19, 33, 2, 90, 15, 45};
    int n = 11;
    // this is like the quicksort, but we won't partition, and just go to the insertion sort directly.
    insertionSort(arr, 0, 10);

    cout << "Insertion Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }

    return 0;
}

//Code Output: Insertion Sorted array: 2 5 12 15 19 23 33 34 45 90 99