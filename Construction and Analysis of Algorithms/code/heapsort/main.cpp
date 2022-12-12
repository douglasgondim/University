#include <iostream>
#include <chrono>
using namespace std;

#include "heapsort.h"

template <typename T, typename P>
void printArray(T arr[], P array_len){
    for(P i=0; i < array_len; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int array_len = 10000000;
    int *arr = new int[array_len];
    // long long int array_len = sizeof(arr)/sizeof(arr[0]);
    auto start = chrono::high_resolution_clock::now();
    for(long long int i=0; i < array_len; i++){
        arr[i] = rand() % array_len;
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Time to Populate Array: " << duration.count() << " milliseconds." << endl;
    // printArray(arr, array_len);
    start = chrono::high_resolution_clock::now();

    heapsort(arr, array_len);

    // sort(arr, arr + array_len);


    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Time to Sort: " << duration.count() << " milliseconds." << endl;
    // printArray(arr, array_len);
    delete[] arr;
    return 0;
}


