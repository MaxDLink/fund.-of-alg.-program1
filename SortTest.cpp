#include <iostream>
#include "SortClass.h"


// Function to sort an array using
// insertion sort
void insertionSortTest(int arr[], int n) //takes in array and size of array 
{
    int i, key, j; //create 3 integers 
    for (i = 1; i < n; i++)//outer for loop deals with i 
    {
        key = arr[i]; //key is set to element at specific i to compare to every single j element. 
        j = i - 1; //set j to one i before key so that you can compare key to arr[j]
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)//when arr[j] element is greater than key element 
        {
            arr[j + 1] = arr[j]; //changes the element after arr[j] to arr[j]. Moves your arr[j] up one element to take key's spot 
            j = j - 1; //decrement j by one so that j is pointing to one element before arr[j]. 
        }
        arr[j + 1] = key; //move key element to its sorted place in the array 
    }
}

void insertionSort(SortClass &s) //sort the items in s by insertion sort 
{
    //[20, 5, 40, 60, 10, 30] <-- array 
    for (int j = 1; j < s.count(); j++) 
	{
	   int i = j; //sets i = 1. Here, j and i both have index 1 [5]
	   while ((i >= 0) && (s.lessthan(i, i-1))) //less than takes in 1, and 0. comparing 5 to 20 and 5 < 20 true 
		{
		   s.swap(i-1, i); //0 and 1. Now array is: [5, 20, 40, 60, 10, 30]. just swapped 5 and 20. 
		   i--; //decrement i by 1 so that i is 0 and the while loop breaks in the less than comparison 
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

void ShellSort(SortClass& s, int code){//implementation of ShellSort - s: the SortClass object, code: an integer denoting how the hlist array is to be formed (0, 1, 2, 3, print error message & exit program)

//TODO - make shellsort function here modelled after above shellsort 

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
