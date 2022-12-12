using std::swap;
int partition(int arr[], int i, int k){
    int pivot = arr[i];
    while(i < k){
        if(arr[i] < pivot){
            i++;
        }
        if(arr[k] > pivot){
            k--;
        }
        if(arr[i] > pivot && arr[k] < pivot){
            swap(arr[i], arr[k]);
        }
    }
}


/*

        ik
 {5, 2, 1, 8, 6};

 */