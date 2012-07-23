//
//  main.cpp
//  DeckShuffle
//
//  Created by umut can genlik on 7/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*

 To shuffle a deck thats cards are represented by integers; solution would be create and array of integer with 52 elements. Fill the array with integers and shuffle it.
 
 However, shuffle function can be done by libraries that is provided by the c/c++ libraries we should use a manual shuffle to be sure.
 
 An improved algorithm of Fisher-Yates would be great for this task.Wee need to ensure that we asked the random number generator for log2(n!) bits of randomness. In other words, the product of all the n's given to the rand_int function must be n!.So below code is ensures the randomness.
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int size=52;
int array[size];

void fillarray(int* input){
    // fill the array numbers with range in sequence
    for (int i=0; i<52; i++) {
        array[i]=i;
    }
    
} 

static int rand_int(int n) {
    int limit = RAND_MAX - RAND_MAX % n;
    int rnd;
    
    do {
        rnd = rand();
    } while (rnd >= limit);
    return rnd % n;
}

void shuffle(int *array, int n) {
    int i, j, tmp;
    
    for (i = n - 1; i > 0; i--) {
        j = rand_int(i + 1);
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
    }
}

void print(int *input)
{
    //print out the array 
    for(int i=0; i<52; i++)
        cout <<"Card " <<i<<"  =" << array[i] << endl;
    
}

int main(int argc, const char * argv[])
{
    fillarray(array);//call function to fill array
    shuffle(array,size);//call the function that will shuffle the deck
    print(array);//print results
    
    return 0;
}

