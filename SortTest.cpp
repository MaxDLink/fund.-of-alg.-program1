#include <iostream>
#include "SortClass.h"


// Function to sort an array using
// insertion sort
void insertionSortTest(int arr[], int n) //takes in array and size of array 
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSort(SortClass &s) //sort the items in s by insertion sort 
{
    for (int j = 1; j < s.count(); j++)
	{
	   int i = j;
	   while ((i >= 0) && (s.lessthan(i, i-1)))
		{
		   s.swap(i-1, i);
		   i--;
		}
	} 
}


int shellSortTest(int arr[], int n){
    for(int gap = n/2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i += 1){
            int temp = arr[i]; 

            int j; 
            for(j = i; j >= gap && arr[j-gap] > temp; j -= gap){
                arr[j] = arr[j-gap]; 
            }
            arr[j] = temp; 
        }
    }

    return 0; 
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " "; 
    }
}

int main()
{

    SortClass st(20); //call SortClass 

    cout << "UNSORTED: " << st << endl; 
    insertionSort(st); //call insertion sort 
    cout << "------\n";
    cout << "Insertion sort: " << endl; 
    cout << st << endl; 
    cout << "Swap count : " << st.getSwapCount() << endl;

    // cout << "ShellSort: " << endl; 
    //ShellSort(st, 1); //HOW TO CALL? 

    // cout << "-----ShellSort Test------" << endl; 

    int arr[] = {12, 34, 54, 2, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    // cout << "Array before sorting: " << "\n"; 
    // printArray(arr, n); 

    // shellSortTest(arr, n); //shellsort function above 

    // cout << "\narray after sorting \n"; 

    // printArray(arr, n); 

    cout << "Insertion Sort Test: " << endl; 
    cout << "Array Before sorting: " << endl; 
    printArray(arr, n); 
    cout << "\narray after sorting \n"; 
    insertionSortTest(arr, n); 
    printArray(arr, n); 
   
    return 0;
}
