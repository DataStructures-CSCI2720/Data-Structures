#ifndef SORTING_H
#define SORTING_H
#include <string>

class Sorting {
    
    private:
        //int values[10000];
    
    public:
        int values[10000];

        void printList();

        void createList(char argv[]);

        int minIndex(int arr[], int start, int end);

        void sSort();

        void Merge(int arr[], int leftFirst, int leftLast, int rightFirst, int rightLast);

        void mSort(int arr[], int first, int last);

        void ReheapDown(int arr[], int root, int bottom);

        void hSort(int arr[], int numValues);

        void qSortf();

        void qSortr();
};

#endif