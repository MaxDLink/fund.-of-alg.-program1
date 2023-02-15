#include <iostream>
#include "SortClass.h"
#include <cstdlib> //for random number gen srand here in sorttest 
#include <ctime> //for random number gen srand here in sorttest 

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
      //TODO- >= causes memory leak for insertion sort and should be changed to > 
		   s.swap(i-1, i); //0 and 1. Now array is: [5, 20, 40, 60, 10, 30]. just swapped 5 and 20. 
		   i--; //decrement i by 1 so that i is 0 and the while loop breaks in the less than comparison 
		}
	} 
}



int main()
{   
  srand(time(0)); //added here for random # gen and srand in sort class disabled 
  //testOneHundredCases(); 

  for(int i = 1; i <= 100; i++){

       SortClass st(4000); //generate random # when called everytime 
       SortClass unsorted = st; //unsorted holds st list 

   for(int code = 0; code < 4; code++){//applies code 0-3 for each of the 100 cases 
            st = unsorted; //gives st the unsorted list to resort 
            //cout << "Shell Sort for case: " << i << " with code: " << code << endl; 
            //cout << "Case " << i << " is: " << st << endl; 
            ShellSort(st, code);
            //insertionSort(st); //TODO - have to clear the memory. He will add memory clearing? 
        
            //Use a table to record the average/standard derivation of number of swaps of each case for each different N. Those 100 cases of N are averaged. 
            //cout << "Sorted: " << st << endl; 
            cout << "case: " << i << ", code: " << i << ", SwapCount: " << st.getSwapCount() << endl;
    }
      //destroy the st object vector and unsorted object vector to avoid overloading memory 
      // st.~SortClass();
      // unsorted.~SortClass(); 

  //   //cout << "ST with case: " << i << ": " << st << endl; 
    
  }
  
  return 0;
}


//TODO - he wont care about getting the analysis data himself. all he cares about is that your shellsort is programmed correctly. check shellsort for correctness and get data with csv file and analyse. He will add a destructor for a sort class. can run program once with n = 100 then n = 1000 and collect the results with passes. Comparison must be fair so all 4 cases must sort the same #'s. 
//TODO - to resolve memory problem easily run program with a different N each time 
//TODO - output results to csv and move csv to excel 
//TODO - formula for standard deviation is the statistic formula that can be found online. For average, add up all the cases and divide by how many there are (n). 