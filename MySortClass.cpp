#include <iostream> 
#include "SortClass.h"

#include "vector" //TODO - put in own function? 
#include <cmath> //TODO - put in own function? 
#include <algorithm> //TODO - put in own function? 

using namespace std; 


void printVector(vector <int> vect){
	cout << "HList: " << endl; 
    for(int i = 0; i < vect.size(); i++){
        cout << vect.at(i) << " "; 
    }
	cout << endl; 
}

void ShellSort(SortClass& s, int code){//implementation of ShellSort - s: the SortClass object, code: an integer denoting how the hlist array is to be formed (0, 1, 2, 3, print error message & exit program)
 if(code > 3){//exits program if code is not 0, 1, 2, 3
        cout << "Code was not 0, 1, 2, or 3. Exiting program!" << endl; 
        return; //returns to exit function; 
    }
    else{//runs if code is 0, 1, 2, 3 
            //[20, 5, 40, 60, 10, 30] <-- array 
       for (int k = 0; k < s.count(); k++){ //loops through code int. 
            vector <int> hlist; //empty hlist vector
			int h = 0;  
            if(code == 0){//h = 1 
                int g = 1; 
                while(g <= s.count()){//pushes a 1 to every array spot 
                    hlist.push_back(1); //h is 1 so program does insertion sort 
                    g++; 
                }
            }if(code == 1){//h = k^2 //works because you are always guaranteed 6 unique numbers 
                int g = 1; 
                int l = 0; 
                while(g <= s.count()){
                    l = g * g; 
                    hlist.push_back(l); 
                    g++; 
                }
                 //print vector 
                reverse(hlist.begin(), hlist.end());	

            }if(code == 2){//h = 2^k -1. hibbard sequence. 1, 3, 7, 15, 31 //TODO - fix code == 2. Moves up in multiples so you are not guaranteed 6 unique numbers 
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
		
            }if(code == 3){//h = (3^k-1)/2
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

			h = hlist[k]; //sets your h value for swap below
            if(h == 0){
                h = 1; 
            }
			cout << "H: " << h << endl;  
       
        for (int j = 1; j < s.count(); j++) {
            int i = j; //sets i = 1. Here, j and i both have index 1 [5]
            while ((i >= 0) && (s.lessthan(i, i-h))) //less than takes in 1, and 0. comparing 5 to 20 and 5 < 20 true 
                {
                    s.swap(i-h, i); //0 and 1. Now array is: [5, 20, 40, 60, 10, 30]. just swapped 5 and 20. 
                    i = i - h; //decrement i by 1 so that i is 0 and the while loop breaks in the less than comparison 
                }
        } 
      } //end of for loop for hlist array 
    }
    

}

