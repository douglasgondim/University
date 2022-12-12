#include <iostream>
using namespace std;

int X(int* A, int i, int j){
    if(A[i] > A[j]){
        swap(A[i], A[j]);
    }

    if(i+1 >= j){
        return -1;
    }

    int k = j-i+1/3;

    X(A, i, j-k);
    X(A, i+k, j);
    X(A, i, j-k);
    return -1;


}

int main(){

    int arr[9] = {15, 42, 21, 50, 33, 65, 40, 43, 20 };

    X(arr, 0, 9);

    for(int i=0; i < 9; i++){
        cout << arr[i] << " ";
    }
}
