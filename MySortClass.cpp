#include <iostream> 
#include "SortClass.h"

#include "vector"
#include <cmath> 
#include <algorithm>  

using namespace std; 

void ShellSort(SortClass& s, int code){//implementation of ShellSort - s: the SortClass object, code: an integer denoting how the hlist array is to be formed (0, 1, 2, 3, print error message & exit program)
 if(code < 0 || code > 3){//exits program if code is not 0, 1, 2, 3
        cout << "Code was not 0, 1, 2, or 3. Exiting program!" << endl; 
        return; //returns to exit function; 
    }
    else{
         int gap = 0; //gap for shellsort 
    vector <int> hlist; //empty hlist vector to store hlist values 
    if(code == 0){// when code == 0 push back 1 for hlist so that shellsort does insertion sort 
        hlist.push_back(1); 
    }
    if(code == 1){//sequence: 1, 4, 9
        int g = 1; //g starts as one 
                int l = 0; 
                while(l < s.count()){//l starts at zero and while it is less than s.count l gets increases according to the sequence 
                    l = g * g; //l increases according to sequence 
                    if(l <= s.count()){//only push back values less than or equal to the amount of elements 
                        hlist.push_back(l);  //push l back to hlist 
                    }else{//breaks out of the while loop if l is bigger than s.count. This ensures that gap will never be bigger than list of elements 
                        break; 
                    }
                    //cout << "L: " << l << endl; 
                    g++; //increments g 
                }
                //reverse the vector so that the vector starts with big sequence #'s and ends at 1 
                reverse(hlist.begin(), hlist.end());
    }
    if(code == 2){//runs if code == 2 
        int l = 0; //start l at 0 
        int g = 0; //start g at 0 
        while(g < s.count()){//ensures that g never exceeds s.count amount 
        //cout << "S: " << s.count() << endl; 
            l += 1; //add 1 to l 
            //cout << "L: " << l << endl; 
            g = (pow(2, l)) - 1; //The Sequence: set g to 2 to the power of l minus 1
            //cout << "\nG before push: " << g << endl; 
            if(g <= s.count()){//only push back values for amount of elements in vector 
                 hlist.push_back(g); //push g into hlist 
                 //cout << "S.count: " << s.count() << endl;
                 //cout << "G: " << g << endl;  

            }else{//if g is greater than s.count then do not push g to hlist and exit the while loop to stop increasing g 
                break; 
            }
    }
        //reverse the vector so that the vector starts with big sequence #'s and ends at 1 
        reverse(hlist.begin(), hlist.end()); //7, 3, 1        
    }
    if(code == 3){//runs if code == 2 
        int l = 0; //start l at 0 
        int g = 0; //start g at 0 
        while(g < s.count()){//ensures that g never exceeds s.count amount 
            l += 1; //add 1 to l 
            g = ((pow(3, l)) -1)/2; //The Sequence: set g to 2 to the power of l minus 1 divided by 2 
            if(g<=s.count()){//only push back values for amount of elements in vector 
                hlist.push_back(g); //push g into hlist 
                //cout << "G: " << g << endl;  
            }else{//if g is greater than s.count then do not push g to hlist and exit the while loop to stop increasing g 
                break; 
            }
        }
                //reverse the vector so that the vector starts with big sequence #'s and ends at 1 
                reverse(hlist.begin(), hlist.end());
    }
    for(size_t count = 0; count < hlist.size(); count++){//loops through hlist 
        gap = hlist[count]; //assigns gap based on hlist 
        for(int i = gap; i < s.count(); i += 1){//now that gap assigned, loop through s.count 
           
            int j = i; //sets i = gap. 
                while ((j >= gap) && (s.lessthan(j, j-gap))) //only runs if j is greater than or equal to the gap and if j-gap is greater than j 
                    {
                        s.swap(j-gap, j); //swaps j-gap with j 
                        j = j - gap; //decrement i by gap 
                    }
        }
    }   
    }
    

}
