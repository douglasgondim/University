#include <stdio.h>
int array[100];
int len=0;

void addBeginning(int data){
	if(len<100){
		if(len>0){
			int i;
			for(i=len;i>0;i--){
				array[i] = array[i-1];
			}
		}
		array[0] = data;
		len++;
	}
}

void addEnd(int data){
	if(len<100){
		array[len] = data;
		len++;
	}

}

void addPosition(int position, int data){
	if(len<100){
		if(position==0){
			addBeginning(data);
		}else if(position==len){
			addEnd(data);
		}else{
			int i;
			for(i=len;i>position;i--){
				array[i] = array[i-1];
			}
			array[position] = data;
			len++;
		}
	}
}

void rmBeggining(){
	if(len>0){
		if(len>1){
			int i;
			for(i=0;i<len;i++){
				array[i] = array[i+1];
			}
		}
		len--;
	}
}

void rmEnd(){
	if(len>0){
		len--;
	}
}

void rmPosition(int position){
	if(len>0){
		if(position==0){
			rmBeggining();
		}else if(position==len-1){
			rmEnd();
		}else{
			int i;
			for(i=position;i<len;i++){
				array[i] = array[i+1];
			}
			len--;
		}
	}
}

void printArray(){
	int i;
	for(i=0;i<len;i++){
		printf("%d\n", array[i]);
	}
}

int list_size(){
	return len;
}


int main(){
	addBeginning(5);
	addBeginning(2);
	addBeginning(3);
	addBeginning(17);
	addEnd(47);
	addEnd(49);
	addBeginning(4);
	addPosition(0,1);
	addPosition(8,44);
	addPosition(1, 77);
	addPosition(4, 88);
	rmBeggining();
	rmBeggining();
	rmEnd();
	addEnd(45);
	rmPosition(0);
	rmPosition(7);
	rmPosition(1);
	rmPosition(4);


	printArray();
	printf("List size: %d\n", list_size());


	return 0;
}