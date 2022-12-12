template <typename T>
void swapPos(T arr[], int a, int b){
    T aux = arr[a];
    arr[a] = arr[b];
    arr[b] = aux;
}

template <typename T>
void heapifyMax(T arr[], int arrayLen, int index){
    int largestChild = index, leftChild = 2 * index + 1, rightChild = 2 * index + 2;

    if(rightChild < arrayLen && arr[rightChild] > arr[index]){
        largestChild = rightChild;
    }
    if(leftChild < arrayLen && arr[leftChild] > arr[largestChild]){
        largestChild = leftChild;
    }
    if(arr[largestChild] != arr[index]){
        swapPos(arr, index, largestChild);
        heapifyMax(arr, arrayLen, largestChild);
    }
}

template <typename T>
void buildHeap(T arr[], int arrayLen){
    for(int i=(arrayLen/2)-1; i >=0; --i){
        heapifyMax(arr, arrayLen, i);
    }
}

template <typename T>
void heapsort(T arr[], int arrayLen){
    buildHeap(arr, arrayLen);
    
    for(int i=arrayLen-1; i >= 0; --i){
        swapPos(arr, 0, i);
        arrayLen--;
        heapifyMax(arr, arrayLen, 0);
    }
}
