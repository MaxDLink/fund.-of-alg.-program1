#include <iostream> 
#include "SortClass.h"

#include "vector" //TODO - put in own function? 
#include <cmath> //TODO - put in own function? 
#include <algorithm> //TODO - put in own function?; 

using namespace std; 

void ShellSort(SortClass& s, int code){//implementation of ShellSort - s: the SortClass object, code: an integer denoting how the hlist array is to be formed (0, 1, 2, 3, print error message & exit program)
 if(code > 3){//exits program if code is not 0, 1, 2, 3
        cout << "Code was not 0, 1, 2, or 3. Exiting program!" << endl; 
        return; //returns to exit function; 
    }
    else{
         int gap = 0; 
    vector <int> hlist; //Can Hlist be a vector or does it have to be an array? start at 1 or keep at 0 for initial index? 
    if(code == 0){
        hlist.push_back(1); 
    }
    if(code == 1){//sequence: 1, 4, 9
        int g = 1; 
                int l = 0; 
                while(l < s.count()){
                    l = g * g; 
                    hlist.push_back(l); 
                    g++; 
                }
                 //print vector 
                reverse(hlist.begin(), hlist.end());
    }
    if(code == 2){
        int l = 0; 
        int g = 0; 
        while(g < s.count()){//stops at h = 31 //g = 7 stop at 7 
                    //cout << "S: " << s.count() << endl; 
                    l += 1; 
                    //cout << "L: " << l << endl; 
                    g = (pow(2, l)) - 1; 
                    //cout << "\nG before push: " << g << endl; 
                    hlist.push_back(g);
                }
                //print vector 
                reverse(hlist.begin(), hlist.end()); //7, 3, 1        
    }
    if(code == 3){
        int l = 0; 
                int g = 0; 
                while(g < s.count()){
                    l += 1; 
                    g = ((pow(3, l)) -1)/2; 

                    hlist.push_back(g); 

                }
                //print vector 
                reverse(hlist.begin(), hlist.end());
    }
    for(size_t count = 0; count < hlist.size(); count++){
        gap = hlist[count]; //assigns gap 
        for(int i = gap; i < s.count(); i += 1){
            // int temp = arr[i]; 

            // int j; 
            // for(j = i; j >= gap && arr[j-gap] > temp; j -= gap){
            //     arr[j] = arr[j-gap]; 
            // }
            // arr[j] = temp; 
            //TODO - replace the above main logic code for swapping with the below and debug 
            //cout << "GAP: " << gap << endl; //TODO - take out when done analyzing shellsort 
            int j = i; //sets i = 1. Here, j and i both have index 1 [5]
            //cout << "J: " << j << endl; //TODO - take out when done analyzing shellsort 
                while ((j >= 0) && (s.lessthan(j, j-gap))) //less than takes in 1, and 0. comparing 5 to 20 and 5 < 20 true 
                    {//TODO - swap causing malloc error 
                        s.swap(j-gap, j); //0 and 1. Now array is: [5, 20, 40, 60, 10, 30]. just swapped 5 and 20.
                        //cout << "SWAPPED." << " List is now: " << s << endl;  //TODO - take out when done analyzing shellsort 
                        j = j - gap; //decrement i by 1 so that i is 0 and the while loop breaks in the less than comparison 
                    }
        }
    } //end of hlist for loop  

    }
    

}
