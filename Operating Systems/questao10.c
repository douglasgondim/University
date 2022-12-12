#include 
void f1(){
	printf("2");
	exit();
}

void f2(){
	printf("3");
	printf("4");
	printf("5");
exit();
}

void f3(){
	printf("6");
	printf("7");
	exit();
}

int main(){
	printf("1");
	int pid = fork();
	if(pid == 0) f2();
	else if(pid > 0){
		pid = fork();
		if(pid == 0) f3();
		else if(pid > 0) f1();
	}
}