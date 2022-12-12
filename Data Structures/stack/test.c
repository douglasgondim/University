#include <stdio.h>
#include <stdlib.h>

int main(){
     char v[5];
     scanf("%[^\n]s", v);
     for(int i=0;i<5;i++){
     	printf("%c\n", v[i]);
     	if(v[i]=='\0'){
     		printf("end\n");
     	}
     }       

     return 0;
}