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
 if(code > 3){//exits program if code is not 0, 1, 2, 3
        cout << "Code was not 0, 1, 2, or 3. Exiting program!" << endl; 
        return; //returns to exit function; 
    }
    else{//runs if code is 0, 1, 2, 3 
            //[20, 5, 40, 60, 10, 30] <-- array 
        for (int k = 0; k <= code; k++){ //loops through code int. 
            // int h = 3 * k + 1; //TODO - what is hlist? Knuth's formula
            int h = 1; 
            if(code == 0){//h = 1 
                cout << "H: " << h << endl; 
            }if(code == 1){//h = k^2
                h = k*k;  
                cout << "H: " << h << endl; 
            }if(code == 2){//h = 2^k -1 
                for(int p = 1; p <= k; p++){
                    h *= 2; //multiply h by 2 until get to k 
                }
                h = h-1;
                cout << "H: " << h << endl; 
            }if(code == 3){//h = (3^k-1)/2
               for(int p = 1; p <= k; p++){
                    h *= 2; //multiply h by 2 until get to k 
                }
                h = h-1;
                h = h/2; 
                cout << "H: " << h << endl; 
            }
            for (int j = 1; j < s.count(); j++) 
        {
        int i = j; //sets i = 1. Here, j and i both have index 1 [5]
        while ((i >= 0) && (s.lessthan(i, i-h))) //less than takes in 1, and 0. comparing 5 to 20 and 5 < 20 true 
            {
            s.swap(i-h, i); //0 and 1. Now array is: [5, 20, 40, 60, 10, 30]. just swapped 5 and 20. 
            i = i - h; //decrement i by 1 so that i is 0 and the while loop breaks in the less than comparison 
            }
        } 
        }
    }
    

}

// void printArray(int arr[], int n){
//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " "; 
//     }
// }

int main()
{

    SortClass st(20); //call SortClass 

    SortClass ss(20); //call SortClass 
    cout << "UNSORTED: " << st << endl; 
    insertionSort(st); //call insertion sort 
    cout << "------\n";
    cout << "Insertion sort: " << endl; 
    cout << st << endl; 
    cout << "Swap count : " << st.getSwapCount() << endl;

    cout << "UNSORTED: " << ss << endl; 
    ShellSort(ss, 3); 
    cout << "------\n";
    cout << "Shell sort: " << endl; 
    cout << ss << endl; 
    cout << "Swap count : " << ss.getSwapCount() << endl;
   
    return 0;
}
