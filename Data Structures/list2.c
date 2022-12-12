// Jose Douglas Gondim Soares, 416753


#include <stdio.h>
int vector[10], len=0; // len == length


// adds integer to list
void add(int element, int position){
	if(len<10){
		if(position>=0 && position<=len){
			for(int i=len;i>position;i--){
				vector[i] = vector[i-1];
			}
			vector[position] = element;
			len++;
		}else
			printf("Invalid position\n");
	}

}


/* 
deletes integer from list if position is populated
and returns the deleted value
 */
int delete(int position){
	int aux;
	if(len>0){
		if(position>=0 && position<len){
			aux = vector[position];
			for(int i=position;i<len-1;i++){
				vector[i] = vector[i+1];
			}
			len--;
			return aux;
		}	
	}else{
		printf("Invalid Position\n");
		return -1;
	}
}


// updates a given position from list
void updatePosition(int position, int newElement){
	if(position>=0 && position<len){
		vector[position] = newElement;
	}else
		printf("Invalid position\n");

}

// updates some given element from list
int updateElement(int element, int newElement){
	for(int i=0;i<len;i++){
		if(vector[i]==element){
			vector[i] = newElement;
			return 0;
		}
	}printf("Invalid Position\n");
	return 0;
}

// searches list for element and prints its position
void search(int element){
	for(int i=0;i<len;i++){
		if(vector[i] == element){
			printf("Element in position %d\n", i);
		}
	}
}

int main(){
	// Main Function


	// for(int i=0;i<10;i++)
	// 	printf("%d ", vector[i]);

	return 0;
}