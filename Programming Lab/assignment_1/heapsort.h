template <typename T>
void swapPos(T arr[], int a, int b){
    T aux = arr[a];
    arr[a] = arr[b];
    arr[b] = aux;
}

template <typename T>
void heapifyMax(T arr[], int i, int j, int index){
    int largestChild = index, leftChild = (2 * (index-i)) + i + 1, rightChild = leftChild + 1;

    if(rightChild <= j && arr[rightChild] > arr[index]){
        largestChild = rightChild;
    }
    if(leftChild <= j && arr[leftChild] > arr[largestChild]){
        largestChild = leftChild;
    }
    if(arr[largestChild] != arr[index]){
        swapPos(arr, index, largestChild);
        heapifyMax(arr, i, j, largestChild);
    }
}

template <typename T>
void buildHeap(T arr[], int i, int j){
    for(int k=j; k >=i; --k){
        heapifyMax(arr, i, j, k);
    }
}

template <typename T>
void heapsortRec(T arr[], int i, int j){
    buildHeap(arr, i, j);
    
    for(int k=j; k >= i; --k){
        swapPos(arr, i, k);
        j--;
        heapifyMax(arr, i, j, i);
    }
}

template <typename T>
void heapsort(T array[], int arrayLen){
    heapsortRec(array, 0, arrayLen-1);
}