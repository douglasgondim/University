#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main(){
pid_t pid, pid1;
pid = fork();
if(pid < 0){
fprintf(stderr, "Fork Failed");
return 1;
}
else if(pid == 0){
pid1 = getpid();
printf("childA: pid = %d\n",pid); /*A*/
printf("childB: pid1 = %d\n",pid1); /*B*/
}
else{
pid1 = getpid();
printf("parentC: pid = %d\n",pid); /*C*/
printf("parentD: pid1 = %d\n",pid1); /*D*/
}
return 0;
}