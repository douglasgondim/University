#include <stdio.h>
#include <time.h>
int main(){
	clock_t start_t, end_t, time;
	double total_t;
	start_t = clock();
	// for(long long j=0;j<100000000;j++){}
	end_t = clock();
	total_t = (double) (end_t-start_t)/CLOCKS_PER_SEC;
	time = start_t + CLOCKS_PER_SEC*0.001*1000;
	printf("%ld\n", start_t);
	start_t = clock();
	printf("%ld\n", start_t);
	start_t = clock();
	printf("%ld\n", start_t);
	start_t = clock();
	printf("%ld\n", start_t);
	start_t = clock();
	printf("%ld\n", start_t);
	// printf("%ld\n", start_t+2);
	// printf("%ld\n", time);
	// printf("%ld\n", CLOCKS_PER_SEC);
}