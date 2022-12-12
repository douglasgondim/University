#include <iostream>
using namespace std;

template <class T>
void sortArray(T array[], int size){
    
    sort(array, array + size);

}




int main(){
    int arr[4] = {4,3,2,1};

    for(int i =0; i < 4; ++i){
        cout << arr[i];
    }
    cout << endl;

    sortArray(arr, 4);

     for(int i =0; i < 4; ++i){
        cout << arr[i];
    }
    cout << endl;


    return 0;
}
