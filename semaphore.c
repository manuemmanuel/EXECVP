#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int mutex = 1, full = 0, empty = 3;
int wait(int);
int signal(int);
int producer();
int producer(){
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	mutex = signal(mutex);
	}
int consumer();
int consumer(){
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	mutex=signal(mutex);

	}
int wait(int s)
{
return --s;
}
int signal(int s)
{
return ++s;
}
void main(){
	int k = 1;
	while (k == 1){
		int n;
	printf("1.Producer\n2.Consumer\n3.Exit\nEnter an option: ");
	scanf("%d",&n);
	switch(n){
		case 1:
			if (mutex == 1 && empty != 0){
				producer();
				printf("An item is produced.\n");
				}
			else {
				printf("The buffer is full.\n");
				}
			break;
		case 2:
			if (mutex == 1 && full != 0){
				consumer();
				printf("An item is consumed.\n");
				}
			else {
				printf("The buffer is empty.\n");
				}
			break;
		case 3:
			exit(0);
			break;
		case 4:
			printf("Invalid input.\n");
			break;
		}
	}	
}
