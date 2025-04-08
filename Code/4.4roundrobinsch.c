
    #include <stdio.h>

void main() {
    int i, n, time = 0, remain, ts, flag = 0;
    int at[10], bt[10], rt[10],wt[10],tat[10];
    int sum_wait = 0, sum_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for Process P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Slice: ");
    scanf("%d", &ts);

    printf("\nGantt Chart:\n");
    printf("|");

    for(time = 0, i = 0; remain != 0;) {
        if(rt[i] <= ts && rt[i] > 0) {
            time += rt[i];
            printf(" P%d |", i + 1);  // Gantt Chart block
            rt[i] = 0;
            flag = 1;
        } else if(rt[i] > 0) {
            rt[i] -= ts;
            time += ts;
            printf(" P%d |", i + 1);  // Gantt Chart block
        }

        if(rt[i] == 0 && flag == 1) {
            remain--;
             wt[i] = time - at[i] - bt[i];
            tat[i] = time - at[i];
            sum_wait += wt[i];
            sum_turnaround += tat[i];
            flag = 0;
        }

        if(i == n - 1)
            i = 0;
        else if(at[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\n\nTotal Waiting Time: %d", sum_wait);
    printf("\nAverage Waiting Time: %.2f", (float)sum_wait / n);
    printf("\nTotal Turnaround Time: %d", sum_turnaround);
    printf("\nAverage Turnaround Time: %.2f\n",(float)sum_turnaround / n);
    
    // Display the table
    printf("\n\nProcess\tAT\tBT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], tat[i], wt[i]);
    }
}



