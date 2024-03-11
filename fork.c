#include <stdio.h>
#include <unistd.h>
void wait();
void main(){
	int pid;
	pid = fork();
	if (pid == 0){
		printf("This is a child process.\n");
		printf("The process ID is %d\n",getpid());
		printf("ID of the parent is %d\n",getppid());
		printf("Enter a limit: ");
		int limit;
		scanf("%d",&limit);
		for (int i = 1; i <= limit; i++){
			printf("%d\n",i);
			}
		}
	else if (pid > 0){
		wait();
		printf("This is the parent process.\n");
		printf("The process ID is %d\n",getppid());
		int n;
		printf("Enter a number: ");
		scanf("%d",&n);
		if (n%2 == 0){
			printf("The number %d is even\n",n);
			}
		else{
			printf("The number %d is odd\n",n);
			}
		}	
	else{
		printf("Fork Failed\n");
		}
	}
