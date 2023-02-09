#include <iostream>
#include "SortClass.h"

#include "vector" //TODO - put in own function? 
#include <cmath> //TODO - put in own function? 
#include <algorithm> //TODO - put in own function? 
//TODO - how will main work with the default code? 
// Function to sort an array using
// insertion sort
void insertionSort(SortClass &s) //sort the items in s by insertion sort 
{
    //[20, 5, 40, 60, 10, 30] <-- array 
    for (int j = 1; j < s.count(); j++) 
	{
	   int i = j; //sets i = 1. Here, j and i both have index 1 [5]
	   while ((i >= 0) && (s.lessthan(i, i-1))) //less than takes in 1, and 0. comparing 5 to 20 and 5 < 20 true 
		{
		   s.swap(i-1, i); //0 and 1. Now array is: [5, 20, 40, 60, 10, 30]. just swapped 5 and 20. 
          // cout << "SWAPPED." << " List is now: " << s << endl;  //TODO - take out once done comparing shellsort & insertion sort 
		   i--; //decrement i by 1 so that i is 0 and the while loop breaks in the less than comparison 
		}
	} 
}

int main()
{   
  //testOneHundredCases(); 
  //TODO - generate 100 lists of n = 500 and make each list unique with .clear? 
    SortClass st(6); 
    cout << "ST: " << st << endl; 
    //TODO - how to change st to a different set of numbers? 
    st.clear(true); 
    cout << "ST after clear: " << st << endl; 
//     SortClass st(500); //call SortClass 

//     for(int i = 1; i <= 100; i++){//generate 100 different sets of n 500 
        
//         SortClass temp = st; //stores unsorted st //TODO - use copy constructor in MySortClass.cpp with another sortclass object
//         cout << "Unsorted --- Shell Sort ----: " << st << endl; 
//         for(int code = 0; code < 4; code++){//applies code 0-3 for each of the 100 cases 
//             cout << "Shell Sort for case: " << i << " with code: " << code << endl; 
//             //cout << "Case " << i << " is: " << st << endl; 
//             ShellSort(temp, code); 
//             //cout << "Sorted: " << st << endl; 
//             cout << "Swap count : " << temp.getSwapCount() << endl; 
//         }
//         SortClass st(500); //randomizes each value in st array 
//    }
  return 0;
}

//TODO - can create multiple sort classes in program 
//TODO - can use copy constructor to copy sort class to another object? 
//TODO - have to sort the same set 4 different times with code 0, 1, 2, 3 
    //SortClass st(20); 
    // SortClass unsortedShell = st; 
    // cout << "\nUNSORTED --- Shell Sort ----: " << unsortedShell << endl; 
    // ShellSort(unsortedShell, 0); //call insertion sort 
    // cout << "------\n";
    // cout << "ShellSort: " << endl; 
    // cout << unsortedShell << endl; 
    // cout << "Swap count : " << unsortedShell.getSwapCount() << endl;

    // cout << "\nUNSORTED --- Insertion Sort ----: " << st << endl; 
    // insertionSort(st); //call insertion sort 
    // cout << "------\n";
    // cout << "Insertion sort: " << endl; 
    // cout << st << endl; 
    // cout << "Swap count : " << st.getSwapCount() << endl;