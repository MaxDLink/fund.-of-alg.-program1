#include <iostream>
#include "SortClass.h"
#include <cstdlib> //for random number gen srand here in sorttest 
#include <ctime> //for random number gen srand here in sorttest 
#include <chrono> //measure time of shellsort function 
using namespace std::chrono; //measure time of shellsort function 


// Function to sort an array using
// insertion sort
void insertionSort(SortClass &s) //sort the items in s by insertion sort 
{
    for (int j = 1; j < s.count(); j++) 
	{
	   int i = j; //sets i = 1. Here, j and i both have index 1 [5]
	   while ((i > 0) && (s.lessthan(i, i-1))) //less than takes in 1, and 0. comparing 5 to 20 and 5 < 20 true 
		{
		   s.swap(i-1, i); //0 and 1. Now array is: [5, 20, 40, 60, 10, 30]. just swapped 5 and 20. 
		   i--; //decrement i by 1 so that i is 0 and the while loop breaks in the less than comparison 
		}
	} 
}



int main()
{   


  srand(time(0)); //added here for random # gen and srand in sort class disabled 
   SortClass st(5000); 
   auto start = high_resolution_clock::now(); //starts the clock now 
   ShellSort(st, 3); 
   auto stop = high_resolution_clock::now(); 
   auto duration = duration_cast<microseconds> (stop - start); //difference between stop and start casted as microseconds 
   cout << "Duration: " << duration.count() << endl; 
//   for(int i = 1; i <= 100; i++){

//        SortClass st(8000); //generate random # when called everytime 
//        SortClass unsorted = st; //unsorted holds st list 

//    for(int code = 0; code < 4; code++){//applies code 0-3 for each of the 100 cases 
//             st = unsorted; //gives st the unsorted list to resort 
//             //cout << "Shell Sort for case: " << i << " with code: " << code << endl; 
//             //cout << "Case " << i << " is: " << st << endl; 
//             ShellSort(st, code);
//             //insertionSort(st); 
//             cout << st.getSwapCount() << endl;
//     }

    
//   }
  
  return 0;
}


