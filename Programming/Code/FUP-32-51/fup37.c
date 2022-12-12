
#include <stdio.h>

int main(){
	int num = 10;
	float flt = 20.3;
	
	int *p_num;
	float *p_flt;
	
	//PONTEIRO GENERICO	
	void *p;
	
	p = &num;
	
	p_num = (int *) p;
	
	printf("%d\n", *p_num);
	
	p = &flt;
	p_flt = (float *) p;
	printf("%.1f\n", *p_flt);
	
	
	
	
	
	
	return 0;
}
