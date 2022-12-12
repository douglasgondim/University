#ifndef QUICKSORT_H 
#define QUICKSORT_H
#endif
#ifndef HEAPSORT_H 
#define HEAPSORT_H
#endif
#ifndef INSERTIONSORT_H 
#define INSERTIONSORT_H
#endif

template <typename T>
void introsortInsertionRec(T* array, int i, int j, int remainingLevels){
	if(j <= i) return;
	if((j-i) <= 8) insertionSort(array, i, j);
	else if(remainingLevels <= 0) heapsortRec(array, i, j);
	else{
		int pivot = partition(array, i, j);
		remainingLevels--;
		introsortInsertionRec(array, i, pivot-1, remainingLevels);
		introsortInsertionRec(array, pivot+1, j, remainingLevels);
	}

}

template <typename T>
void introsortInsertion(T* array, int n){
	int logn = 0, arrayLen = n;
	while(n > 1){
		n >>= 1;
		logn++;
	}

	introsortInsertionRec(array, 0, arrayLen-1, 2*logn);
}

