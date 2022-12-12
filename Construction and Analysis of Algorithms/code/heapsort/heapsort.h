template <typename T, typename P>
void swapPos(T arr[], P a, P b){
    T aux = arr[a];
    arr[a] = arr[b];
    arr[b] = aux;
}

template <typename T, typename P>
void heapifyMax(T arr[], P array_len, P index){
    P largestChild = index, leftChild = 2 * index + 1, rightChild = 2 * index + 2;
    if(rightChild < array_len && arr[rightChild] > arr[leftChild]){
        largestChild = rightChild;
    }
    if(leftChild < array_len && arr[leftChild] > arr[largestChild]){
        largestChild = leftChild;
    }
    if(arr[largestChild] != arr[index]){
        swapPos(arr, index, largestChild);
        heapifyMax(arr, array_len, largestChild);
    }
}

template <typename T, typename P>
void buildHeap(T arr[], P array_len){
    for(P i=(array_len/2)-1; i >=0; --i){
        heapifyMax(arr, array_len, i);
    }
}

template <typename T, typename P>
void heapsort(T arr[], P array_len){
    buildHeap(arr, array_len);
    
    for(P i=array_len-1; i >= 0; --i){
        swapPos(arr, (P) 0, i);
        array_len--;
        heapifyMax(arr, array_len, (P) 0);
    }
}