#include "Sorting.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

void Sorting::printList() { // DONE for now
    for (int i = 0; i < 10000; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
}

void Sorting::createList(char argv[]) { // DONE
    ifstream input(argv);
    int num;
    for (int i = 0; i < 10000; i++) {
        input >> num;
        values[i] = num;
    } // while
} // createList

int Sorting::minIndex(int arr[], int start, int end) { // used in selection sort 
    int indexOfMin = start;
    for(int i = start + 1; i <= end; i++) {
        if (values[i] < values[indexOfMin]) {
            indexOfMin = i;
        }
    }
    return indexOfMin;
}

void Sorting::sSort() { // STILL NEEDS COMPARISONS but works
    int endIndex = 10000 - 1;
    for (int current = 0; current < endIndex; current++) {
       std::swap(values[current] , values[minIndex(values, current, endIndex)]);
    } // for
    printList(); // THIS CAN PROBABLY BE MOVED SOMEWHERE ELSE FOR MORE EFFICIENCY
} // sSort

void Sorting::Merge(int arr[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
    int temp[10000];
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

void Sorting::ReheapDown(int arr[], int root, int bottom) { // Does not work
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;

    if (leftChild <= bottom) {  
        if (leftChild == bottom) {
                maxChild = leftChild;
        } else {
            if(values[leftChild <= values[rightChild]]) {
                maxChild = rightChild;
            } else {
                maxChild = leftChild;
            }
        }
        if (arr[root] < arr[maxChild]) {
                std::swap(arr[root], arr[maxChild]);
                ReheapDown(arr, maxChild, bottom);
        } // if
    }
} // reheapdown

void Sorting::hSort(int arr[], int numValues) {
    int i;
    for(i = numValues/2-1; i >= 0; i--) {
        ReheapDown(arr, i, numValues - 1);
    } // for

    for(i = numValues - 1; i >= 1; i--) {
        std::swap(arr[0], arr[i]);
        ReheapDown(arr, 0, i - 1);
    } // for
} // hSort

void Sorting::qSortf() {

} // qSortf

void Sorting::qSortr() {

} // qSortr