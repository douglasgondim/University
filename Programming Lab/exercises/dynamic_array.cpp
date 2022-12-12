#include <iostream>
using namespace std;

int* increaseArraySize(int* array, int currentSize, int newSize){
    if(newSize <= currentSize){
        cout << "[Error] The new size should be bigger than the current size." << endl;
        return nullptr;
    }
    int* newArr;
    try{
        newArr = new int[newSize];
    }catch(exception &e){
        cout << "[Error] " << e.what() << endl;
        return nullptr;

    }
    for(int i=0; i < currentSize; ++i){
        newArr[i] = array[i];
    }
    delete[] array;

    return newArr;


}
int main(){
    int n, arraySize = 1, numOfElements = 0;
    int *arr = nullptr;
    arr = increaseArraySize(arr, 0, arraySize);

   if(arr == nullptr){
       cout << "[Error] There was a problem creating the array." << endl;
       return 1;
   }
    
    do {
        cout << "Enter an integer number: ";
        cin >> n;
        arr[numOfElements] = n;
        numOfElements++;
        if(numOfElements >= arraySize){
            arr =increaseArraySize(arr, arraySize, arraySize*2);
            if(arr == nullptr){
                cout << "[Error] There was a problem increasing the size of the array." << endl;
                return 1;
            }
            arraySize *= 2;
        }

        // code to check array growing in real time

        // cout << "Current Array: ";
        // for(int i =0; i < arraySize; ++i){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;


    } while(n != 0);

    sort(arr, arr + numOfElements-1);

    for(int i = 0; i < numOfElements-1; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}