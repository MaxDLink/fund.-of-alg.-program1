#include <iostream> 
#include "SortClass.h"

void ShellSort(SortClass& s, int code){//implementation of ShellSort - s: the SortClass object, code: an integer denoting how the hlist array is to be formed (0, 1, 2, 3, print error message & exit program)
    //shellsort pseudo code 

for(int k = 1; k < s.count(); k++){
    int h = code; 
 //insertion sort 
    for (int j = 1; j < s.count(); j++)
	{
	   int i = j;
	   while ((i >= 0) && (s.lessthan(i, i-h)))
		{
		   s.swap(i-h, i);
		   i = i - h; 
		}
	} 
}
   

}