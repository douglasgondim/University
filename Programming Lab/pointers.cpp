#include <iostream>
using namespace std;

// int printFunc(int* &p){ cout << p[0] << endl;}

// int main(){
//     int arr[6] = {1, 2, 3 , 4, 5, 6};
//     printFunc(&(arr[0]));
//     // int* p = &arr[0];
//     // cout << p[2] << endl;

//     return 0;
// }

int main(int argc, String* argv){

    for(int i=0; i < argc; i++){
        cout << argv[i] << endl;
    }

    return 0;
}