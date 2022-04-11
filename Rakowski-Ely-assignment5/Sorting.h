#ifndef SORTING_H
#define SORTING_H
#include <string>

class Sorting {
    // literally nothing done here
    private:
        int val; // temporary
    
    public:
        Sorting();
        
        ~Sorting();

        void sSort();

        void mSort();

        void hSort();

        void qSortf();

        void qSortr();
};

#endif