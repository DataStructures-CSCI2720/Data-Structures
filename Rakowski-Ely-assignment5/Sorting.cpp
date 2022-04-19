#include "Sorting.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**
 * @brief Construct a new Sorting object with user defined size.
 * Default size is 10000 for provided files.
 * 
 * @param size size of list
 */
Sorting::Sorting(int size) {
    length = size;
    values = new int[size];
} // Sorting

/**
 * @brief Prints the items in the list
 * 
 */
void Sorting::printList() {
    for (int i = 0; i < length; i++) {
        cout << values[i] << " ";
    } // for
    cout << endl;
} // printList

/**
 * @brief Creates a 10000 long list with values from file
 * 
 * @param argv 
 */
void Sorting::createList(char argv[]) {
    ifstream input(argv);
    int num;
    for (int i = 0; i < length; i++) {
        input >> num;
        values[i] = num;
    } // for
} // createList

/**
 * @brief Creates a list with random values at each position
 * 
 */
void Sorting::createRList() {
    srand(time(0));
    for (int i = 0; i < length; i++) {
        values[i] = rand() % length;        // each value is between 0 and # of values
    } // for
} // createRList

/**
 * @brief Finds the index of minimum value in a list
 * 
 * @param arr reference of array
 * @param start beginning location
 * @param end ending location
 * @return int index of minimum value
 */
int Sorting::minIndex(int arr[], int start, int end) { 
    int indexOfMin = start;
    for (int i = start + 1; i <= end; i++) {
        if (values[i] < values[indexOfMin]) {
            indexOfMin = i;   
        } // if
        comparisons++;
    } // for
    return indexOfMin;
} // minIndex

/**
 * @brief Selection sort works at O(N^2) and iterates through the entire list
 * 
 */
void Sorting::sSort() { 
    int endIndex = length - 1;
    for (int current = 0; current < endIndex; current++) {
       std::swap(values[current] , values[minIndex(values, current, endIndex)]);
    } // for
    printList(); // print is fine right here
    cout << "\t#Selection-sort comparisons: " << comparisons << endl; // class var comparisons
} // sSort

/**
 * @brief Merge combines two parts of an array into one helping the merge sort function
 * 
 * @param arr reference to array
 * @param leftFirst first value of left part
 * @param leftLast last value of left part
 * @param rightFirst first value of right part
 * @param rightLast last value of right part
 */
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
        } // if
        i++;
        comparisons++;
    } // while
    while (leftFirst <= leftLast) {
        temp[i] = arr[leftFirst];
        leftFirst++;
        i++;
    } // while
    while (rightFirst <= rightLast) {
        temp[i] = arr[rightFirst];
        rightFirst++;
        i++;
    } // while
    for (i = saveFirst; i <= rightLast; i++) {
        arr[i] = temp[i];
    } // for

} // Merge

/**
 * @brief Merge Sort works at O(Nlog(N)) complexity and uses
 * divide and conquer to sort a list
 * 
 * @param arr reference of array
 * @param first first value
 * @param last last value
 */
void Sorting::mSort(int arr[], int first, int last) {
    if (first < last) {
        int middle = (first + last) / 2;
        mSort(arr, first, middle);
        mSort(arr, middle + 1, last);
        Merge(arr, first, middle, middle + 1, last);
    } // if
} // mSort

/**
 * @brief Takes root value and heaps down to bottom of tree
 * 
 * @param arr reference of array
 * @param root root of tree index
 * @param bottom bottom of tree index
 */
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
            } // if
        } // if
        comparisons++;
        if  (values[ root ] < values[maxChild]) {
	        comparisons++;
            swap(values[root], values[maxChild]);
	        ReheapDown(arr, maxChild, bottom);   
        } // if
    } // if
} // reheapdown

/**
 * @brief Heap Sort works at O(Nlog(N)) complexity and heaps values down 
 * the tree until values are properly sorted
 * 
 * @param arr reference of array
 * @param numValues number of values
 */
void Sorting::hSort(int arr[], int numValues) {
    int i;
    for (i = numValues/2-1; i >= 0; i--) {
        ReheapDown(arr, i, numValues - 1);
    } // for

    for (i = numValues - 1; i >= 1; i--) {
        std::swap(arr[0], arr[i]);
        ReheapDown(arr, 0, i - 1);
    } // for
} // hSort

/**
 * @brief Helper to Quick Sort splits the middle of the list
 * 
 * @param arr reference to array
 * @param first first value in sub array
 * @param last last value of sub array
 * @return int middle of list
 */
int Sorting::Split(int arr[], int first, int last) { 
    int pivot, index, i;
    index = last;
    pivot = first;
    for (i=last; i > first; i--) {
        comparisons++;
        if (arr[i] > arr[pivot]) {
            std::swap(arr[i], arr[index]);
            index--;
        } // if
    } // for
    std::swap(arr[pivot], arr[index]);
    return index;
} // Split

/**
 * @brief Quick Sort works at O(Nlog(N)) complexity and uses
 * divide and conquer to sort find split points and sorts the left
 * and right sides of the split
 * 
 * @param arr reference of array
 * @param first first value of sub array
 * @param last last value of sub array
 */
void Sorting::qSortf(int arr[], int first, int last) {
    if (first < last) {
        int splitPoint = Split(arr, first, last);
        qSortf(arr, first, splitPoint - 1);
        qSortf(arr, splitPoint + 1, last);    
    } // if
} // qSortf

/**
 * @brief Helper to Quick Sort with random pivot value
 * 
 * @param arr reference of array
 * @param first first value of sub array
 * @param last last value of sub array
 * @return int random split point
 */
int Sorting::randomSplit(int arr[], int first, int last) { 
    int pivot, index, i;
    index = last;
    srand(time(0));
    int random = first + (rand() % (last - first + 1));
    pivot = first;
    std::swap(arr[pivot], arr[random]); // swaps first value with a random value
    for (i=last; i > first; i--) {
        comparisons++;
        if (arr[i] > arr[pivot]) {
            std::swap(arr[i], arr[index]);
            index--;
        } // if
    } // for
    std::swap(arr[pivot], arr[index]);
    return index;
} // randomSplit

/**
 * @brief Quick Sort with random pivot works at O(Nlog(N)) complexity
 * and applies similar Quick Sort function but with a random split point
 * 
 * @param arr reference of array
 * @param first first value of sub array
 * @param last last value of sub array
 */
void Sorting::qSortr(int arr[], int first, int last) { 
    if (first < last) {
        int splitPoint = randomSplit(arr, first, last);
        qSortf(arr, first, splitPoint - 1);
        qSortf(arr, splitPoint + 1, last);    
    } // if
} // qSortr

/**
 * @brief Returns number of comparions completed while sorting
 * a list
 * 
 * @return long number of comparisons
 */
long Sorting::getCom() const {
    return comparisons;
} // getCom

/**
 * @brief Returns the length of the list
 * 
 * @return int length of list
 */
int Sorting::getLength() const {
    return length;
} // getLength