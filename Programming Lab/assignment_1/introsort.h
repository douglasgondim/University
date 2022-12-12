#ifndef QUICKSORT_H 
#define QUICKSORT_H
#endif
#ifndef HEAPSORT_H 
#define HEAPSORT_H
#endif


template <typename T>
void introsortRec(T* array, int i, int j, int remainingLevels){
	if(j <= i) return;
	if(remainingLevels <= 0) heapsortRec(array, i, j);
	else{
		T pivot = partition(array, i, j);
		remainingLevels--;
		introsortRec(array, i, pivot-1, remainingLevels);
		introsortRec(array, pivot+1, j, remainingLevels);
	}

}

template <typename T>
void introsort(T* array, int n){
	int logn = 0, arrayLen = n;
	while(n > 1){
		n >>= 1;
		logn++;
	}

	introsortRec(array, 0, arrayLen-1, 2*logn);
}

