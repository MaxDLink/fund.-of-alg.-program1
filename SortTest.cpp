#include <iostream>
#include "SortClass.h"
#include <cstdlib> //for random number gen srand here in sorttest 
#include <ctime> //for random number gen srand here in sorttest 

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
  //TODO - disable this if random # gen does not work? 
  srand(time(0)); //added here for random # gen and srand in sort class disabled 
  //testOneHundredCases(); 
  //TODO - generate 100 lists of n = 500 and make each list unique with .clear? 

  // for(int i = 0; i < 2; i++){

  //   SortClass st(6, true); //generate random # when called everytime 
  //   cout << "ST with case: " << i << ": " << st << endl; 
  //   //TODO - how to change st to a different set of numbers? 
  //   //st.clear(false); 
  //   //st.clear(true); 
  //   //cout << "ST after clear: " << st << endl; 

  // }
    
  

    for(int i = 1; i <= 100; i++){//generate 100 different sets of n 500 

        //  SortClass st(20, true); //call SortClass & generate a unique list of numbers 
        
        //cout << "Unsorted --- Shell Sort ----: " << st << endl; 
        for(int code = 0; code < 4; code++){//applies code 0-3 for each of the 100 cases 
            SortClass st(20, true); //call SortClass & generate a unique list of numbers 
            //cout << "Shell Sort for case: " << i << " with code: " << code << endl; 
            //cout << "Case " << i << " is: " << st << endl; 
            ShellSort(st, code); 
            //cout << "Sorted: " << st << endl; 
            cout << "Swap count for case: " << i << " With code: " << code << " is: " << st.getSwapCount() << endl; //TODO - swap amounts shouldnt be the same for different code entries. check shellsort algo for correctness? 
            st.clear(true); //sets everything to zero and resets swap count to zero 
        }
        //randomize next set of numbers in st array 
        // st.clear(false); //clears existing numbers in list 
        // st.clear(true);  //generates new random numbers in list 
   }
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