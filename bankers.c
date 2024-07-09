#include <stdio.h>
#include <stdlib.h>

void main(){
	int n, r;
	int exec = 0, c = 0, k = 0, flag = 0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the number of resources: ");
	scanf("%d",&r);
	int visit[n], a[n];
	int alloc[n][r], max[n][r], need[n][r], avail[r];
	printf("Enter the available resourses: ");
	for (int i = 0; i < r; i++){
		scanf("%d", &avail[i]);
	}
	for (int i = 0; i < n; i++){
		visit[i] = 0;
		printf("Enter the max of process %d: ",i);
		for (int j = 0; j < r; j++){
			scanf("%d",&max[i][j]);
		}
		printf("Enter the allocation of the process %d: ",i);
		for (int j = 0; j < r; j++){
			scanf("%d",&alloc[i][j]);
		}
		for (int j = 0; j < r; j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	printf("\nAllocation\tMax      \tNeed\n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < r; j++){
			printf("%d",alloc[i][j]);
		}
		printf("\t");
		for (int j = 0; j < r; j++){
			printf("%d",max[i][j]);
		}
		printf("\t");
		for (int j = 0; j < r; j++){
			printf("%d",need[i][j]);
		}
		printf("\n");
		
	}
	while (c < n){
		flag = 0;
		for (int i = 0; i < n; i++ ){
			exec = 0;
			for (int j = 0;j < r; j++){
				if (need[i][j] <= avail[j]){
					exec ++;
				}
			if (exec == r && visit[i] == 0){
				for (int j = 0; j < r; j++){
					avail[j] += alloc[i][j];
					flag = 1;
					visit[j] = 1;
					a[k++] = i;
					c++;
				}
				
			}
			if (flag == 0){
				printf("No safe sequence.\n");
				exit(0);	
			}
			}
			printf("The safe sequence.\n");
			printf("< ");
			for (int i = 0; i < n; i++){
				printf("P%d ",a[i]);
			}
			printf(" >");
		}
	}
}
