
#include <stdio.h>
void main(){
	int m, p;
	printf("Enter the number of memory blocks: ");
	scanf("%d", &m);
	printf("Enter the number of processes: ");
	scanf("%d",&p);

	struct memory {
		int size;
		int alloc;
	}M[m];
	struct process {
		int process;
		int flag;
	}P[p];
	
	printf("Enter the size of the memory blocks: ");
	for (int i = 0; i < m; i++) {
		scanf("%d",&M[i].size);
		M[i].alloc = 0;
	}
	
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			if (M[j].size < M[i].size){
				int temp = M[j].size;
				M[j].size = M[i].size;
				M[i].size = temp;
			}
		}
	}
	printf("Enter the space required for each processes: ");
	for (int i = 0; i < p; i++){
		scanf("%d",&P[i].process);
		P[i].flag = 0;
	}
	
	for (int i = 0; i < p; i++){
		for (int j = 0; j < p; j++){
			if (P[j].process < P[i].process){
				int temp = P[j].process;
				P[j].process = P[i].process;
				P[i].process = temp;
			}
		}
	}
	
	for (int i = 0; i < p; i++){
		for (int j = 0; j < m; j++){
			if (P[i].process <= M[j].size){
				if (M[j].alloc == 1){
					continue;
					}
				else {
					M[j].alloc = 1;
					P[i].flag = 1;
					printf("The process of size %d is allocated to memory block %d.\n",P[i].process, M[j].size);
					break;
				}
			}
		}
	}
	
	for (int i = 0; i < p; i++){
		if (P[i].flag == 0){
			printf("The process %d is not allocated.",P[i].process);
		}
	}
}
