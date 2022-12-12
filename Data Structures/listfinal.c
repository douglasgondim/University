#include <stdio.h>
int vector[10], len=0; // len == lenght

void addEnd(int element){
	vector[len] = element;
	len++;
}

void addBeggining(int element){
	for(int i=len;i>0;i++)
		vector[len] = vector[len-1];
	vector[0]=element;
	len++;
}

void add(int element, int position){
	if(len<10){
		if(position>=0 && position<=len){
			if(position==0){
				addBeggining(element);
			}else if(position == len){
				addEnd(element);
			}else{
				for(int i=len;i>position;i--){
					vector[len] = vector[len-1];
				}
				vector[position] = element;
				len++;

			}

		}
	}else{
		printf("Vector Full\n");
	}

}

void search(int element){
	int count=0;
	for(int i=0;i<len;i++){
		if(vector[i] == element){
			printf("Elemento na Posicao: %d\n", i);
			count++;
		}
	}
	if(count==0)
		printf("Element not found\n");
}

void update(int element, int newElement){
	int count=0;
	for(int i=0;i<len;i++){
		if(vector[i] == element){
			vector[i] = newElement;
			count++;
		}
	}
	if(count==0){
		printf("Element not found\n");
	}
}

void delete(int element){
	int count=0;
	for(int i=0;i<len;i++){
		if(vector[i] == element){
			for(i;i<len;i++){
				vector[i] = vector[i+1];
			}
			len--;
			count++;
		}
	}
	if(count==0)
		printf("Element not found\n");
}



int main(){
	add(1, 0);
	add(2, 1);
	add(3, 2);
	add(4, 3);
	add(5, 4);
	add(1, 5);
	add(2, 6);
	add(3, 7);
	add(4, 8);
	add(5, 9);

	for(int i=0;i<10;i++){
		printf("%d ", vector[i]);
	}

	return 0;
}