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
    ShellSort(st, 1); 
   
    return 0;
}
