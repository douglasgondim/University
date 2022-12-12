#include <time.h>
using std::swap;
using std::cout;
using std::endl;

template <typename T>
int partitionRQ(T* array, int i, int j){
    srand(time(NULL));
    int randomPos = rand() % (j-i+1) + i, beginning = i;
    T pivot = array[randomPos];
    swap(array[i], array[randomPos]);
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
void randomQuicksortRec(T* array, int i, int j){
    if(i < j){
        T pivot = partitionRQ(array, i, j);
        randomQuicksortRec(array, i, pivot-1);
        randomQuicksortRec(array, pivot+1, j);
    }
}

template <typename T>
void randomQuicksort(T* array, int n){
    randomQuicksortRec(array, 0, n-1);
}

