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

// Function to find the median of three and return the index of the pivot
int findMedian(int arr[], int left, int right) {
    int mid = (right + left) / 2;

    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);
    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);

    return mid;
}

// Function to partition the array and return the index of the pivot
int partition(int arr[], int left, int right) {
    int pivotIndex = findMedian(arr, left, right);
    int pivotValue = arr[pivotIndex];
    
    // Move pivot to the end after finding the median so that we can start switching and making the two sides of the partition.
    swap(arr[pivotIndex], arr[right]); 
    int i = left;
    
    for (int j = left; j < right; j++) 
    {
        if (arr[j] < pivotValue) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    
    swap(arr[i], arr[right]); // Move pivot to its final place
    return i;
}

// Function to perform quicksort with insertion sort for small subarrays
void quickSort(int arr[], int left, int right, int k) {
    if (right - left + 1 <= k) 
    {
        insertionSort(arr, left, right);
    } 
    else
    {
        if (left < right) 
        {
            int pivotIndex = partition(arr, left, right);
            // this code will only have one pivot being 23 before it reaches the condition for each suba rray to be sorted
            //details will be found in the hand written version.
            quickSort(arr, left, pivotIndex - 1, k);
            quickSort(arr, pivotIndex + 1, right, k);
        }
    }
}

int main() {
    int arr[] = {12, 5, 99, 34, 23, 19, 33, 2, 90, 15, 45};
    int n = 11;
    int k = 10; // Threshold for using insertion sort

    quickSort(arr, 0, 10, k);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// Code Ouput: Sorted array: 2 5 12 15 19 23 33 34 45 90 99