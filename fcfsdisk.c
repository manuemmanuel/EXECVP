#include <stdio.h>

int main() {
    int head, a[20], i, distance, n, seektime = 0;

    printf("\nEnter Head position: ");
    scanf("%d", &head);
    
    printf("\nEnter number of disk requests: ");
    scanf("%d", &n);
    
    printf("\nEnter the disk requests: ");
    for(i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    a[0] = head;
    printf("*****FCFS DISK SCHEDULING*****************\n");
    
    for(i = 0; i < n; i++) {
        if(a[i] > a[i + 1]) {
            distance = a[i] - a[i + 1];
        } else {
            distance = a[i + 1] - a[i];
        }
        printf("Head movement from %d to %d : %d\n", a[i], a[i + 1], distance);
        seektime += distance;
    }
    
    printf("Total seek time is : %d\n", seektime);
    
    return 0;
}
