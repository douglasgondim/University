#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//Função para contar de 1 a 5
void conta(){
  printf("Oprocesso %d está contando\n", getpid());
  for(int i = 1; i <= 5; i++){
    printf("%d ", i);
  }
}

int main(){
    int i;
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0){
        //O código aqui dentro será executado no processo filho
        printf("pid do Filho: %d\n", getpid());
        conta();
    }
    else{
        //O código neste trecho será executado no processo pai
        printf("pid do Pai: %d\n", getpid());
        conta();
    }


    printf("Esta regiao sera executada por ambos processos\n\n");
    scanf("%d", &i);
    exit(0);
}
