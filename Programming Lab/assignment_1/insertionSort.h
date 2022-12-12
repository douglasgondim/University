void insertionSort(int array[], int i, int j){
	for(int k=i+1; k<=j;++k){
		for(int m=k-1; m >= i; --m){
			if(array[m] > array[m+1]){
				swap(array[m+1], array[m]);
			}else{
				break;
			}
			
		}
	}

}

