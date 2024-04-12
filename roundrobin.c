#include <stdio.h>
void main(){
	int quantum = 5,n;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int process[n],burst[n],rburst[n],wt[n],tat[n],flag = 0,total = 0,total_wt = 0,total_tat = 0;
	for (int i = 0; i < n; i++){
		printf("Enter the process: ");
		scanf("%d",&process[i]);
		printf("Enter the burst time: ");
		scanf("%d",&burst[i]);
		rburst[i] = burst[i];
		}
	while (flag != n){
		for (int i = 0; i < n; i++){
			if (rburst[i] > quantum){
				total = total + quantum;
				rburst[i] = rburst[i] - quantum;
				}
			else if (rburst[i] == 0){
				continue;
				}
			else {
				total = total + rburst[i];
				rburst[i] = 0;
				tat[i] = total;
				wt[i] = total - burst[i];
				flag++;
				}
			}
		}
	printf("\n");
	printf("Process\t|Burst time\t|Waiting time\t|Turn Around Time\n");
	for (int i = 0; i < n; i++){
		printf("%d\t|%d\t\t|%d\t\t|%d\n",process[i],burst[i],wt[i],tat[i]);
		total_wt  = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		}
	printf("\n");
	printf("Total Waiting time: %d\n",total_wt);
	printf("Total Turn around time: %d\n",total_tat);
	float avg_wt = total_wt*1.0/n;
	float avg_tat = total_tat*1.0/n;
	printf("Average Waiting time: %f\n",avg_wt);
	printf("Average turn around time: %f\n",avg_tat);
	
	}
