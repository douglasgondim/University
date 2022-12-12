// Jose Douglas Gondim Soares, 416753

#include <stdio.h>
int vector[10], len=0; // len == lenght


// adds element to end of list
void addEnd(int element){   
	vector[len] = element;
	len++;
}

// adds element to beggining of list
void addBeggining(int element){
	for(int i=len;i>0;i++)
		vector[len] = vector[len-1];
	vector[0]=element;
	len++;
}

// adds element to list on a given position
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

		}else
			printf("Invalid Position\n");
	}else{
		printf("Vector Full\n");
	}

}


/* searches list for an element and returns its order on the list
	or "Element not found".
*/
void search(int element){
	int count=0;
	for(int i=0;i<len;i++){
		if(vector[i] == element){
			printf("Order in list: %d\n", i+1);
			count++;
		}
	}
	if(count==0)
		printf("Element not found\n");
}


// searches position of a given element. (Not for the final user).
int searchPosition(int element){
	int count=0;
	for(int i=0;i<len;i++)
		if(vector[i]== element){
			count++;
			return i;
		}
	if(count==0)
		printf("Element not found\n");
		return -1;
}


// updates element on list
void update(int element, int newElement){
	int position = searchPosition(element);
		if(position != -1)
			vector[position] = newElement;
}


// deletes element from list
void delete(int element){
	int position = searchPosition(element);
	if(position!=-1){
		for(int i=position;i<len;i++){
			vector[i] = vector[i+1];
		}
		len--;
	}
}



int main(){



// MAIN FUNCTION

	// for(int i=0;i<10;i++)
	// 	printf("%d ", vector[i]);

	return 0;
}