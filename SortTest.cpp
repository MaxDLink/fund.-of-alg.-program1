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

    SortClass st(20); //call SortClass //TODO - array start at 1 instead of 0 so that size of array and gap # line up?
    SortClass unsorted = st; //stores unsorted st //TODO - use copy constructor in MySortClass.cpp with another sortclass object 

    cout << "Shell Sort Object: " << endl; 
    cout << "Unsorted --- Shell Sort ----: " << unsorted << endl; 
    ShellSort(unsorted, 3); 
    cout << "Sorted: " << unsorted << endl; 
    cout << "Swap count : " << unsorted.getSwapCount() << endl; 

//TODO - can create multiple sort classes in program 
//TODO - can use copy constructor to copy sort class to another object? 
//TODO - have to sort the same set 4 different times with code 0, 1, 2, 3 

    cout << "\nUNSORTED --- Insertion Sort ----: " << st << endl; 
    insertionSort(st); //call insertion sort 
    cout << "------\n";
    cout << "Insertion sort: " << endl; 
    cout << st << endl; 
    cout << "Swap count : " << st.getSwapCount() << endl; 
   
    return 0;
}
