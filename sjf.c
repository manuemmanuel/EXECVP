#include <stdio.h>
void main(){
	int n;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int process[n],burst[n],wt[n],tat[n],total_tat = 0,total_wt = 0;
	printf("Enter the burst time and process id: ");
	for (int i = 0; i < n; i++){
		scanf("%d",&process[i]);
		scanf("%d",&burst[i]);
		}
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n;j++){
			if (burst[i] > burst[j]){
				int temp = burst[i];
				burst[i] = burst[j];
				burst[j] = temp;
				int temp2 = process[i];
				process[i] = process[j];
				process[j] = temp2;
				}
			}
		}
	wt[0] = 0;
	tat[0] = burst[0];
	total_tat = tat[0];
	for (int i = 1; i < n; i++){
		wt[i] = wt[i-1]+burst[i-1];
		total_wt = total_wt + wt[i];
		tat[i] = tat[i-1] + burst[i];
		total_tat = total_tat + tat[i];
		}
		float avg_wt = (float)total_wt/n;
		float avg_tat = (float)total_tat/n;
	printf("Average Waiting time: %f\nTotal Waiting time: %d\nAverage Turnaround time: %f\nTotal Turnaround time: %d\n",avg_wt,total_wt,avg_tat,total_tat);	
	}
