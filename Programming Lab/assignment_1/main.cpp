// José Douglas Gondim Sores, 485347
#include <iostream>
#include "heapsort.h"
#include "quicksort.h"
#include "randomQuicksort.h"
#include "insertionSort.h"
#include "introsort.h"
#include "introsortInsertion.h"
#include "3.h"

using std::cout;
using std::endl;
using std::stoi;

template <typename T>
void printArray(T arr[], int array_len){
    for(int i=0; i < array_len; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int** generateArrays(char arrayMode, int arrayLen, int arrayInstances){
    int **arrays = new int*[arrayInstances];

    for(int i=0; i < arrayInstances; ++i){
        arrays[i] = new int[arrayLen];
    }

    for(int i=0; i < arrayInstances; ++i){
            for(int j=0; j < arrayLen; ++j){
                switch (arrayMode){
                    case 'C':
                        arrays[i][j] = j;
                        break;
                    case 'D':
                        arrays[i][j] = arrayLen-1-j;
                        break;
                    case 'P':

                        break;
                    default:
                        arrays[i][j] = rand() % arrayLen;
                        break;
                }

            }
        }
    
    return arrays;

}

bool arraySortedCheck(int array[], int arrayLen){
    for(int i=0; i < arrayLen-1; ++i){
        if(array[i] > array[i+1]) return false;
    }
    return true;
}

int** duplicateArrays(int *arrays[], int arrayInstances, int arrayLen){
    int **arraysCopy = new int*[arrayInstances];
    for(int i=0; i < arrayInstances; ++i){
        arraysCopy[i] = new int[arrayLen];
    }

    for(int i=0; i < arrayInstances; ++i){
        for( int j =0; j < arrayLen; ++j){
            arraysCopy[i][j] = arrays[i][j];
        }
    }
    return arraysCopy;

}

void deleteArrays(int *arrays[], int arrayInstances){
    for(int i=0; i < arrayInstances; ++i){
        delete[] arrays[i];
    }
    delete[] arrays;
    
}

int main(int, char *argv[]){
    char arrayMode = *argv[1];
    int arrayLen = stoi(argv[2]);
    int arrayInstances = stoi(argv[3]);

    int **arrays = generateArrays(arrayMode, arrayLen, arrayInstances);


    // ------------------------------------- HEAPSORT -------------------------------------

    int **arraysCopy = duplicateArrays(arrays, arrayInstances, arrayLen);
    auto start = std::chrono::high_resolution_clock::now();

    for(int i=0; i < arrayInstances; ++i){
        heapsort(arraysCopy[i], arrayLen);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "Heapsort: " << duration.count()/1000.0 << " seconds." << endl;


    for(int i=0; i < arrayInstances; ++i){
        if(!arraySortedCheck(arraysCopy[i], arrayLen)){
            cout << "Array [" << i << "] is NOT sorted." << endl;;

        }

    }

    // ------------------------------------- QUICKSORT FIXED PIVOT -------------------------------------

    deleteArrays(arraysCopy, arrayInstances);

    arraysCopy = duplicateArrays(arrays, arrayInstances, arrayLen);

    start = std::chrono::high_resolution_clock::now();

    for(int i=0; i < arrayInstances; ++i){
        quicksort(arraysCopy[i], arrayLen);
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "Quicksort Fixed Pivot: " << duration.count()/1000.0 << " seconds." << endl;


    for(int i=0; i < arrayInstances; ++i){
        if(!arraySortedCheck(arraysCopy[i], arrayLen)){
            cout << "Array [" << i << "] is NOT sorted." << endl;;

        }

    }

    deleteArrays(arraysCopy, arrayInstances);


    // ------------------------------------- QUICKSORT RANDOM PIVOT -------------------------------------


    arraysCopy = duplicateArrays(arrays, arrayInstances, arrayLen);

    start = std::chrono::high_resolution_clock::now();

    for(int i=0; i < arrayInstances; ++i){
        randomQuicksort(arraysCopy[i], arrayLen);
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "Quicksort Random Pivot: " << duration.count()/1000.0 << " seconds." << endl;


    for(int i=0; i < arrayInstances; ++i){
        if(!arraySortedCheck(arraysCopy[i], arrayLen)){
            cout << "Array [" << i << "] is NOT sorted." << endl;;

        }

    }

    deleteArrays(arraysCopy, arrayInstances);


    // ------------------------------------- INTROSORT WITHOUT INSERTIONSORT -------------------------------------

    arraysCopy = duplicateArrays(arrays, arrayInstances, arrayLen);

    start = std::chrono::high_resolution_clock::now();

    for(int i=0; i < arrayInstances; ++i){
        introsort(arraysCopy[i], arrayLen);
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "introsort Without insertionSort: " << duration.count()/1000.0 << " seconds." << endl;


    for(int i=0; i < arrayInstances; ++i){
        if(!arraySortedCheck(arraysCopy[i], arrayLen)){
            cout << "Array [" << i << "] is NOT sorted." << endl;;

        }

    }

    deleteArrays(arraysCopy, arrayInstances);

    // ------------------------------------- INTROSORT WITH INSERTIONSORT -------------------------------------


    arraysCopy = duplicateArrays(arrays, arrayInstances, arrayLen);

    start = std::chrono::high_resolution_clock::now();

    for(int i=0; i < arrayInstances; ++i){
        introsortInsertion(arraysCopy[i], arrayLen);
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "introsort With insertionSort: " << duration.count()/1000.0 << " seconds." << endl;


    for(int i=0; i < arrayInstances; ++i){
        if(!arraySortedCheck(arraysCopy[i], arrayLen)){
            cout << "Array [" << i << "] is NOT sorted." << endl;;

        }

    }

    deleteArrays(arraysCopy, arrayInstances);





    deleteArrays(arrays, arrayInstances);

    cout << "-----------" << endl;


    return 0;
}
