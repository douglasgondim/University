#include <stdio.h>
#include <string.h>
int main(){
	char shape[20];
	char animal[20];
	char food[20];

	scanf("%s %s %s", shape, animal, food);

	if(strcmp(shape, "vertebrado")==0){
		if(strcmp(animal, "ave")==0){
			if(strcmp(food, "carnivoro")==0)
				printf("aguia\n");
			else if(strcmp(food, "onivoro")==0)
				printf("pomba\n");
		}else{
			if(strcmp(food, "onivoro")==0)
				printf("homem\n");
			else
				printf("vaca\n");
		}
	}else{
		if(strcmp(animal, "inseto")==0){
			if(strcmp(food, "hematofago")==0)
				printf("pulga\n");
			else
				printf("lagarta\n");
		}else{
			if(strcmp(food, "hematofago")==0)
				printf("sanguessuga\n");
			else
				printf("minhoca\n");
		}
	}
	return 0;
}