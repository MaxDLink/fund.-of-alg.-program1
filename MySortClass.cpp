#include <iostream> 
#include "SortClass.h"

void ShellSort(SortClass& s, int code){//implementation of ShellSort - s: the SortClass object, code: an integer denoting how the hlist array is to be formed (0, 1, 2, 3, print error message & exit program)
    //shellsort pseudo code 
    int gap = code / 2; 

    while(gap > 0){

        int j = 0; 

        //TODO - get s to be the array. look through the object functions 

        for(int i = gap; i < code; i++){

            int temp = s[i]; 

            for(j = i; j >= gap && s[i-gap] > temp; j-=gap){

                s[j] = s[j - gap]; 

            }

            s[j] = temp; 

        }


        gap = gap / 2; 



    }


}