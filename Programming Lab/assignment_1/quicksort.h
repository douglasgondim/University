#include "2.h"
using std::swap;
using std::cout;
using std::endl;

template <typename T>
int partition(T* array, int i, int j){
    T pivot = array[pivo(i, j)];
    int beginning = i;
    swap(array[beginning], array[pivo(i, j)]);
    ++i;
    while(i <= j){
        if(array[i] > pivot && array[j] < pivot){
            swap(array[i], array[j]);
            ++i;
            --j;
        }else if(array[i] <= pivot) ++i;
        else if(array[j] >= pivot) --j;
    }
    swap(array[beginning], array[i-1]);
    return i-1;
    
}

template <typename T>
void quicksortRec(T* array, int i, int j){
    if(i < j){
        int pivot = partition(array, i, j);
        quicksortRec(array, i, pivot-1);
        quicksortRec(array, pivot+1, j);
    }
}

template <typename T>
void quicksort(T* array, int n){
    quicksortRec(array, 0, n-1);
}



