#include <iostream> 
#include "SortClass.h"

void ShellSort(SortClass& s, int code){//implementation of ShellSort - s: the SortClass object, code: an integer denoting how the hlist array is to be formed (0, 1, 2, 3, print error message & exit program)
    //shellsort pseudo code 
    for code = 1 to p 
        h = hlist[code]
        for j = 2 to n 
            i = j 
            while (i > 1) and (A[i-h] > A[i])
                swap(A[i], A[i-h])
                i = i - h 


}