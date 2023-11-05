#include <iostream>


using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {12, 5, 99, 34, 23, 19, 33, 2, 90, 15, 45};
    int n = 11;

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        
    }
    cout << endl;
    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// Code Ouput:  Original array: 12 5 99 34 23 19 33 2 90 15 45 
//Sorted array: 2 5 12 15 19 23 33 34 45 90 99