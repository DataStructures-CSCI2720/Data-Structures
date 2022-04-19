#ifndef SORTING_H
#define SORTING_H
#include <string>

class Sorting {
    
    private:
        //int values[10000];
        long comparisons = 0;
        //int* values;
        int length = 0;
    
    public:
        //int values[10000];
        int* values; // gonna leave it but public arrays are DUMB

        Sorting(int size);

        void printList();

        void createList(char argv[]);

        void createRList();

        int minIndex(int arr[], int start, int end);

        void sSort();

        void Merge(int arr[], int leftFirst, int leftLast, int rightFirst, int rightLast);

        void mSort(int arr[], int first, int last);

        void ReheapDown(int arr[], int root, int bottom);

        void hSort(int arr[], int numValues);

        int Split(int arr[], int first, int last);
        
        void qSortf(int arr[], int first, int last);

        int randomSplit(int arr[], int first, int last);

        void qSortr(int arr[], int first, int last);

        long getCom() const;

        int getLength() const;
};

#endif