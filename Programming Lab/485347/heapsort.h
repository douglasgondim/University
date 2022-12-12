// [NOTE] This whole file was taken from my assignment 1 project (the sorting algorithms project).
// The only changes I have made were on the comparison operator on the heapifyMax function to
// turn it into heapifyMin and I also adapted the heapifyMin function to compare objects 
// of type struct Node. I have also commented some unused functions.

// I have now created the add and remove from heap functions as well

template <typename T>
void swapPos(T arr[], int a, int b){
    T aux = arr[a];
    arr[a] = arr[b];
    arr[b] = aux;
}


// template <typename T>
// void heapifyMax(T arr[], int i, int j, int index){
//     int largestChild = index, leftChild = (2 * (index-i)) + i + 1, rightChild = leftChild + 1;

//     if(rightChild <= j && arr[rightChild] > arr[index]){
//         largestChild = rightChild;
//     }
//     if(leftChild <= j && arr[leftChild] > arr[largestChild]){
//         largestChild = leftChild;
//     }
//     if(arr[largestChild] != arr[index]){
//         swapPos(arr, index, largestChild);
//         heapifyMax(arr, i, j, largestChild);
//     }
// }



template <typename T>
void heapifyMin(T arr[], int i, int j, int index){
    int largestChild = index, leftChild = (2 * (index-i)) + i + 1, rightChild = leftChild + 1;

    if(rightChild <= j && arr[rightChild]->weight < arr[index]->weight){
        largestChild = rightChild;
    }
    if(leftChild <= j && arr[leftChild]->weight < arr[largestChild]->weight){
        largestChild = leftChild;
    }
    if(arr[largestChild] != arr[index]){
        swapPos(arr, index, largestChild);
        heapifyMin(arr, i, j, largestChild);
    }
}
template <typename T>
void addToHeap(T arr[], int arraySize, int &heapSize, T data){
    if(arraySize == heapSize){
        cout << "Heap is full, cannot add more elements." << endl;
        return;
    }
    arr[heapSize] = data;
    int aux = heapSize;
    while(arr[(aux-1)/2] > arr[aux]){
        swapPos(arr, (aux-1)/2, aux);
        aux = (aux-1)/2;
    }
    ++heapSize;

}


template <typename T>
T removeFromHeap(T arr[], int &heapSize){
    if(heapSize < 1){
        cout << "Heap is empty" << endl;
        return (T) 0;
    }
    T aux = arr[0];
    swapPos(arr, 0, heapSize-1);
    --heapSize;
    heapifyMin(arr, 0, heapSize-1, 0);
    return aux;
}

template <typename T>
void buildHeap(T arr[], int i, int j){
    for(int k=j; k >=i; --k){
        heapifyMin(arr, i, j, k);
    }
}

template <typename T>
void heapsortRec(T arr[], int i, int j){
    buildHeap(arr, i, j);
    
    for(int k=j; k >= i; --k){
        swapPos(arr, i, k);
        j--;
        heapifyMin(arr, i, j, i);
    }
}

template <typename T>
void heapsort(T array[], int arrayLen){
    heapsortRec(array, 0, arrayLen-1);
}