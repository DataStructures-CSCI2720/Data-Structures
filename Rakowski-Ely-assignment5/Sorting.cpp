#include "Sorting.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

Sorting::Sorting(int size) {
    length = size;
    values = new int[size];
} // Sorting

void Sorting::printList() { // DONE for now
    for (int i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
}

void Sorting::createList(char argv[]) { // DONE
    ifstream input(argv);
    int num;
    for (int i = 0; i < length; i++) {
        input >> num;
        values[i] = num;
    } // while
} // createList

void Sorting::createRList() {
    srand(time(0));
    for (int i = 0; i < length; i++) {
        values[i] = rand() % 10000;
    } // for
} // createRList

int Sorting::minIndex(int arr[], int start, int end) { // used in selection sort 
    int indexOfMin = start;
    for(int i = start + 1; i <= end; i++) {
        if (values[i] < values[indexOfMin]) {
            indexOfMin = i;
            
        }
        comparisons++;
    }
    return indexOfMin;
}

void Sorting::sSort() { 
    int endIndex = length - 1;
    for (int current = 0; current < endIndex; current++) {
       std::swap(values[current] , values[minIndex(values, current, endIndex)]);
    } // for
    printList(); // print is fine right here
    cout << "\t#Selection-sort comparisons: " << comparisons << endl; // class var comparisons
} // sSort

void Sorting::Merge(int arr[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
    int temp[length];
    int i = leftFirst;
    int saveFirst = leftFirst;

    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
        if (arr[leftFirst] < arr[rightFirst]) {
            temp[i] = arr[leftFirst];
            leftFirst++;
        } else {
            temp[i] = arr[rightFirst];
            rightFirst++;
        } // else
        i++;
        comparisons++; // comparisons made
    } // while
    while (leftFirst <= leftLast) {
        temp[i] = arr[leftFirst];
        leftFirst++;
        i++;
    }
    while (rightFirst <= rightLast) {
        temp[i] = arr[rightFirst];
        rightFirst++;
        i++;
    }
    for (i = saveFirst; i <= rightLast; i++) {
        arr[i] = temp[i];
    }

}

void Sorting::mSort(int arr[], int first, int last) {
    if (first < last) {
        int middle = (first + last) / 2;
        mSort(arr, first, middle);
        mSort(arr, middle + 1, last);
        Merge(arr, first, middle, middle + 1, last);
    }
} // mSort

void Sorting::ReheapDown(int arr[], int root, int bottom) {
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;
    if (leftChild  <=  bottom) {
        if  (leftChild  ==  bottom) {
	        maxChild  = leftChild; 
        } else {
	        if (values[leftChild] <=  values [rightChild]) {
	            maxChild  =  rightChild ;
            } else {
                maxChild  =  leftChild ;
            }
        }
        comparisons++;
        if  (values[ root ] < values[maxChild]) {
	        comparisons++;
            swap(values[root], values[maxChild]);
	        ReheapDown(arr, maxChild, bottom);
            
        }
    }
} // reheapdown

void Sorting::hSort(int arr[], int numValues) { // i think comparison value is right or close.
    int i;
    for(i = numValues/2-1; i >= 0; i--) {
        ReheapDown(arr, i, numValues - 1);
    } // for

    for(i = numValues - 1; i >= 1; i--) {
        std::swap(arr[0], arr[i]);
        ReheapDown(arr, 0, i - 1);
    } // for
} // hSort

int Sorting::Split(int arr[], int first, int last) { // worried the pivot is not done correctly
    return 1;
}

void Sorting::qSortf(int arr[], int first, int last) { // this method works but not the sub method
    if (first < last) {
        int splitPoint = Split(arr, first, last);
        qSortf(arr, first, splitPoint - 1);
        qSortf(arr, splitPoint + 1, last);    
    }

} // qSortf

int Sorting::randomSplit(int arr[], int first, int last) { // does not work correctly
    int pivot = arr[4269]; // pivot is this number that i picked
    int splitPoint = first;
    int i;
    int t;

    for(i = first; i < last; i++) {
        if(arr[i] <= pivot) {
            t = arr[i];
            arr[i] = arr[splitPoint];
            arr[splitPoint] = t;
            splitPoint++;
        }
    }
    t = arr[last];
    arr[last] = arr[splitPoint];
    arr[splitPoint] = t;
    
    return splitPoint;
}

void Sorting::qSortr(int arr[], int first, int last) { // works correctly
    if (first < last) {
        int splitPoint = Split(arr, first, last);
        qSortf(arr, first, splitPoint - 1);
        qSortf(arr, splitPoint + 1, last);    
    }
} // qSortr

long Sorting::getCom() const {
    return comparisons;
} // getCom

int Sorting::getLength() const {
    return length;
} // getLength