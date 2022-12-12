#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	printf("%d\n", fork());

	printf("%d\n", fork());
	

	printf("%d\n", fork());
	

	return 0;
}
