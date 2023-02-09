#include <iostream>
#include "SortClass.h"

#include "vector" //TODO - put in own function? 
#include <cmath> //TODO - put in own function? 
#include <algorithm> //TODO - put in own function? 
//TODO - how will main work with the default code? 
// Function to sort an array using
// insertion sort
void insertionSortTest(int arr[], int n) //takes in array and size of array 
{
    int i, key, j; //create 3 integers 
    for (i = 1; i < n; i++)//outer for loop deals with i 
    {
        key = arr[i]; //key is set to element at specific i to compare to every single j element. 
        j = i - 1; //set j to one i before key so that you can compare key to arr[j]
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)//when arr[j] element is greater than key element 
        {
            arr[j + 1] = arr[j]; //changes the element after arr[j] to arr[j]. Moves your arr[j] up one element to take key's spot 
            j = j - 1; //decrement j by one so that j is pointing to one element before arr[j]. 
        }
        arr[j + 1] = key; //move key element to its sorted place in the array 
    }
}

void insertionSort(SortClass &s) //sort the items in s by insertion sort 
{
    //[20, 5, 40, 60, 10, 30] <-- array 
    for (int j = 1; j < s.count(); j++) 
	{
	   int i = j; //sets i = 1. Here, j and i both have index 1 [5]
	   while ((i >= 0) && (s.lessthan(i, i-1))) //less than takes in 1, and 0. comparing 5 to 20 and 5 < 20 true 
		{
		   s.swap(i-1, i); //0 and 1. Now array is: [5, 20, 40, 60, 10, 30]. just swapped 5 and 20. 
		   i--; //decrement i by 1 so that i is 0 and the while loop breaks in the less than comparison 
		}
	} 
}


int shellSortTest(int arr[], int n){
    for(int gap = n/2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i += 1){
            int temp = arr[i]; 

            int j; 
            for(j = i; j >= gap && arr[j-gap] > temp; j -= gap){
                arr[j] = arr[j-gap]; 
            }
            arr[j] = temp; 
        }
    }

    return 0; 
}

// int calculatedShellSortTest(int arr[], int n, int code){
//     int gap = 0; 
//     vector <int> hlist; 
//     if(code == 0){
//         hlist.push_back(1); 
//     }
//     if(code == 1){
//         int g = 1; 
//                 int l = 0; 
//                 while(l < n){
//                     l = g * g; 
//                     hlist.push_back(l); 
//                     g++; 
//                     l = g * g; //TODO - need this line? 
//                 }
//                  //print vector 
//                 reverse(hlist.begin(), hlist.end());
//     }
//     if(code == 2){
//          int l = 0; 
//         int g = 0; 
//         while(g < n){//stops at h = 31 //g = 7 stop at 7 
//                     //cout << "S: " << s.count() << endl; 
//                     l += 1; 
//                     //cout << "L: " << l << endl; 
//                     g = (pow(2, l)) - 1; 
//                     //cout << "\nG before push: " << g << endl; 
//                     hlist.push_back(g);
//                 }
//                 //print vector 
//                 reverse(hlist.begin(), hlist.end()); //7, 3, 1        
//     }
//     if(code == 3){
//         int l = 0; 
//                 int g = 0; 
//                 while(g < n){
//                     l += 1; 
//                     g = ((pow(3, l)) -1)/2; 

//                     hlist.push_back(g); 

//                 }
//                 //print vector 
//                 reverse(hlist.begin(), hlist.end());
//     }
//     for(int count = 0; count < hlist.size(); count++){
//         gap = hlist[count]; //assigns gap 
//         for(int i = gap; i < n; i += 1){
//             int temp = arr[i]; 

//             int j; 
//             for(j = i; j >= gap && arr[j-gap] > temp; j -= gap){
//                 arr[j] = arr[j-gap]; 
//             }
//             arr[j] = temp; 
//         }
//     } //end of hlist for loop 
//     return 0; 
// }


int ShellSortObject(SortClass& s, int code){
    int gap = 0; 
    vector <int> hlist; 
    if(code == 0){
        hlist.push_back(1); 
    }
    if(code == 1){
        int g = 1; 
                int l = 0; 
                while(l < s.count()){
                    l = g * g; 
                    hlist.push_back(l); 
                    g++; 
                    l = g * g; //TODO - need this line? 
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
    for(int count = 0; count < hlist.size(); count++){
        gap = hlist[count]; //assigns gap 
        for(int i = gap; i < s.count(); i += 1){
            // int temp = arr[i]; 

            // int j; 
            // for(j = i; j >= gap && arr[j-gap] > temp; j -= gap){
            //     arr[j] = arr[j-gap]; 
            // }
            // arr[j] = temp; 
            //TODO - replace the above main logic code for swapping with the below and debug 
            cout << "GAP: " << gap << endl; 
            int j = i; //sets i = 1. Here, j and i both have index 1 [5]
            cout << "J: " << j << endl; 
                while ((j >= 0) && (s.lessthan(j, j-gap))) //less than takes in 1, and 0. comparing 5 to 20 and 5 < 20 true 
                    {
                        s.swap(j-gap, j); //0 and 1. Now array is: [5, 20, 40, 60, 10, 30]. just swapped 5 and 20.
                        cout << "SWAPPED." << " List is now: " << s << endl;  
                        j = j - gap; //decrement i by 1 so that i is 0 and the while loop breaks in the less than comparison 
                    }
        }
    } //end of hlist for loop 
    return 0; 
}

int main()
{

    SortClass st(80); //call SortClass 
    SortClass unsorted = st; //stores unsorted st 

    // cout << "Calculated SHELL SORT TEST: " << endl; 
    // int array[] = {88, 9, 12, 14, 56, 90, 2, 1}; 
    // calculatedShellSortTest(array, 8, 0); 
    // for(int i = 0; i < 8; i++){
    //     cout << array[i] << " "; 
    // }

    cout << "Shell Sort Object: " << endl; 
    cout << "Unsorted: " << unsorted << endl; 
    ShellSortObject(unsorted, 0); 
    cout << "Sorted: " << unsorted << endl; 
    cout << "Swap count : " << unsorted.getSwapCount() << endl; 




    cout << "\nUNSORTED: " << st << endl; 
    insertionSort(st); //call insertion sort 
    cout << "------\n";
    cout << "Insertion sort: " << endl; 
    cout << st << endl; 
    cout << "Swap count : " << st.getSwapCount() << endl; 

    // cout << "------\n";
    // cout << "UNSORTED: " << unsorted << endl; 
    // ShellSort(unsorted, 1); 
    // cout << "------\n";
    // cout << "Shell sort: " << endl; 
    // cout << unsorted << endl; 
    // cout << "Swap count : " << unsorted.getSwapCount() << endl;
   
    return 0;
}
