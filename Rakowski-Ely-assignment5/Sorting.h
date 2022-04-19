#ifndef SORTING_H
#define SORTING_H
#include <string>

/**
 * @brief Sorting object houses the list of numbers as well as the 
 * sorting algorithms able to be performed and compare their efficiencies
 * 
 */
class Sorting {
    
    private:
        long comparisons = 0;                           // number of comparisons made
        int length = 0;                                 // reference to length of list
    
    public:
        int* values;                                    // list of numbers

        Sorting(int size);                              // Sorting constructor

        void printList();                               // prints the entire list

        void createList(char argv[]);                   // creates a list from file

        void createRList();                             // creates a random list of variable size

        int minIndex(int arr[], int start, int end);    // returns the index of minimum value of list

        void sSort();                                   // selection sort

        void Merge(int arr[], int leftFirst, int leftLast, int rightFirst, int rightLast);  // merge values

        void mSort(int arr[], int first, int last);     // merge sort

        void ReheapDown(int arr[], int root, int bottom);   // reheaps value to bottom of list

        void hSort(int arr[], int numValues);           // heap sort

        int Split(int arr[], int first, int last);      // splits the list at middle point
        
        void qSortf(int arr[], int first, int last);    // quick sort

        int randomSplit(int arr[], int first, int last);    // splits the list at random point

        void qSortr(int arr[], int first, int last);    // quick sort with random pivot value

        long getCom() const;                            // returns the number of comparisons

        int getLength() const;                          // returns length value
};

#endif