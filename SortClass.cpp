#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SortClass.h"

using namespace std;


SortClass::SortClass(int n, bool genRandom) //create a sortclass object that stores n items. Every # randomly gen if genRandom is set to true. Otherwise every # is 0.0 
{
    swapCount = 0;
    if (genRandom) 
	{
            srand(time(0));
	    for (int i = 0; i < n; i++)
		array.push_back((rand() % 1000) * 1.0);
	}
    else
	{
	    for (int i = 0; i < n; i++)
		array.push_back(0.0);
	}
}

SortClass::SortClass(const SortClass& st) //copy constructor 
{
   swapCount = st.swapCount;
   for (int i = 0 ; i < st.array.size(); i++)
	array.push_back(st.array[i]);

}

int SortClass::count() //returns the number of items in the array 
{
   return array.size();
}

int SortClass::getSwapCount() //returns the current value of swapCount 
{
   return swapCount;
}

void SortClass::clear(bool genRandom) //if genRandom is true, than assign a random value to each itme of the SortClass array. Otherwise, sets every item of the array to be 0. Reset swapCount to 0
{
    swapCount = 0;
    if (genRandom) 
	{
            srand(time(0));
	    for (int i = 0; i < array.size(); i++)
		array[i] = rand() * 1.0;
	}
    else
	{
	    for (int i = 0; i < array.size(); i++)
		array[i] = 0.0;
	}
}

bool SortClass::lessthan(int i, int j) //returns true iff array[i] < array[j]
{
   return (array[i] < array[j]);
}

void SortClass::swap(int i, int j) //swap array[i] with array[j]; increment swapCount by 1
{
    float temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    swapCount++;
}

ostream& operator<<(ostream& os, SortClass& s) //output the content of the array. Add a newline character for every 10 items output 
{
    for (int i = 0; i < s.array.size(); i++)
	{
	    if (!(i % 10))
		os << endl;
	    os << s.array[i] << " ";
	}
    return os;
}

istream& operator>>(istream& is, SortClass& s)//read the value of the items from the input stream (items are stored from the first item to the last)
{
    for (int i = 0; i < s.array.size(); i++)
	{
	    is >> s.array[i];
	}
    return is;
}
