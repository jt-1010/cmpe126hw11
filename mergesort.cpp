#include <iostream>

using namespace std;


void merge(int sArr[], int l, int m, int r)
{
    int i = l; //left array starting index
    int j = m+1; //right array starting index
    int k = l; //temp
    int temp[11];
    while(i <= m && j <= r)
    {
        //if the value in the left array is bigger than the one in the right array, then it will put it in the array, if not, it will put the other one in the array
        if(sArr[i] <= sArr[j])
        {
            temp[k] = sArr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = sArr[j];
            j++;
            k++;
        }
    }
    //here, we will make sure that there are no value that are left out making sure both sides of the array are emptied.
    //There is only one side (right or left) that will ever be left out, meaning that the order in which we check does not matter
    while(i <= m)
    {
        temp[k] = sArr[i];
        i++;
        k++;
    }
    while(j <= r)
    {
        temp[k] = sArr[j];
        j++;
        k++;
    }
    //we now put it back into the original array
     for(int z = l; z <= r; z++)
     {
        sArr[z] = temp[z];
     }
}

void mergesort(int mArr[], int l, int r)
{
    if(l < r)
    {
        //gets mid point by dividing the left most index and right most index by 2
        int m  = (l+r)/2;
        //this gets the left sub array
        mergesort(mArr, l, m);
        //this gets the right sub array
        mergesort(mArr, m+1, r);
        //we then call the merge function where we pass in the array, the 
        merge(mArr , l , m, r);
    }
}

int main()
{
    int arr[11] = {12, 5, 99, 34, 23, 19, 33, 2, 90, 15, 45};
    cout << "Sorted array is: ";

    mergesort(arr, 0 ,10);
    for(int i = 0; i < 11; i++)
    {
        cout <<  arr[i] << " ";
    }
    return 0;
}

// Code Output: Sorted array is: 2 5 12 15 19 23 33 34 45 90 99