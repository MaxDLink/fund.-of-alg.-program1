#include <iostream>
#include "SortClass.h"


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

    cout << "ShellSort: " << endl; 
    //ShellSort(st, 1); //HOW TO CALL? 

    cout << "-----ShellSort Test------" << endl; 

    int arr[] = {12, 34, 54, 2, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    cout << "Array before sorting: " << "\n"; 
    printArray(arr, n); 

    shellSortTest(arr, n); //shellsort function above 

    cout << "\narray after sorting \n"; 

    printArray(arr, n); 
   
    return 0;
}
