#include <stdio.h>
#include <limits.h>

void FCFS(int n, int at[], int bt[], int tat[], int ft[], int wt[], int rt[]) {
    int currTime = at[0];
    for (int i = 0; i < n; i++) {
        ft[i] = currTime + bt[i];
        currTime = ft[i];
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("\nPID\tAT\tBT\tFT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ft[i], tat[i], wt[i]);
    }
}

void nonPreemptiveSJF(int n, int at[], int bt[], int tat[], int completionTime[], int wt[], int rt[]) {
    printf("\nnonPreemptiveSJF Algorithm\n");
    int remaining[n];
    for (int i = 0; i < n; i++) {
        remaining[i] = bt[i];
        wt[i] = 0;
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        int shortest = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && remaining[i] < minBurst) {
                shortest = i;
                minBurst = remaining[i];
            }
        }

        if (shortest == -1) {
            currentTime++;
        } else {
            int currentProcess = shortest;
            completionTime[currentProcess] = currentTime + remaining[currentProcess];
            rt[currentProcess] = currentTime - at[currentProcess];
            currentTime = completionTime[currentProcess];
            tat[currentProcess] = completionTime[currentProcess] - at[currentProcess];
            wt[currentProcess] = tat[currentProcess] - bt[currentProcess];
            remaining[currentProcess] = INT_MAX;
            completed++;
        }
    }

    printf("\nProcess\tAT\tBT\tTAT\tFT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], tat[i], completionTime[i], wt[i], rt[i]);
    }
}

void preemptiveSJF(int n, int at[], int bt[], int tat[], int ft[], int wt[], int rt[]) {
    printf("\npreemptiveSJF SCHEDULING ALGORITHM\n");
    int remaining[n];
    for (int i = 0; i < n; i++) {
        remaining[i] = bt[i];
        wt[i] = 0;
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        int shortest = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && remaining[i] < minBurst && remaining[i] > 0) {
                shortest = i;
                minBurst = remaining[i];
            }
        }

        if (shortest == -1) {
            currentTime++;
        } else {
            int currentProcess = shortest;
            remaining[currentProcess]--;
            currentTime++;
            if (remaining[currentProcess] == 0) {
                completed++;
                tat[currentProcess] = currentTime - at[currentProcess];
                ft[currentProcess] = currentTime;
                wt[currentProcess] = tat[currentProcess] - bt[currentProcess];
                rt[currentProcess] = ft[currentProcess] - bt[currentProcess] - at[currentProcess];
            }
        }
    }

    printf("Process\tBT\tAT\tTAT\tFT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], at[i], tat[i], ft[i], wt[i], rt[i]);
    }
}

void nonPreemptivePriority(int n, int at[], int bt[], int tat[], int ft[], int wt[], int rt[], int priority[]) {
    printf("\nnonPreemptivePriority Scheduling Algorithm\n");
    int executed[n];
    for (int i = 0; i < n; i++) {
        executed[i] = 0;
    }
    int completed = 0;
    int currentTime = 0;
    while (completed < n) {
        int highestPriority = INT_MAX;
        int highestPriorityProcess = -1;
        for (int i = 0; i < n; i++) {
            if (!executed[i] && priority[i] < highestPriority && at[i] <= currentTime) {
                highestPriority = priority[i];
                highestPriorityProcess = i;
            }
        }
        if (highestPriorityProcess == -1) {
            currentTime++;
        } else {
            executed[highestPriorityProcess] = 1;
            ft[highestPriorityProcess] = currentTime + bt[highestPriorityProcess];
            tat[highestPriorityProcess] = ft[highestPriorityProcess] - at[highestPriorityProcess];
            wt[highestPriorityProcess] = tat[highestPriorityProcess] - bt[highestPriorityProcess];
            rt[highestPriorityProcess] = currentTime - at[highestPriorityProcess];
            completed++;
            currentTime = ft[highestPriorityProcess];
        }
    }
    printf("Process\tBT\tAT\tTAT\tFT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], at[i], tat[i], ft[i], wt[i], rt[i]);
    }
}

void preemptivePriority(int n, int at[], int bt[], int tat[], int wt[], int rt[], int ft[], int priority[]) {
    printf("\nPreemptive Priority Scheduling Algorithm\n");
    int remainingTime[n];
    int executed[n];

    for (int i = 0; i < n; i++) {
        executed[i] = 0;
        remainingTime[i] = bt[i];
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        int highestPriority = INT_MAX;
        int highestPriorityProcess = -1;

        for (int i = 0; i < n; i++) {
            if (!executed[i] && at[i] <= currentTime && priority[i] < highestPriority) {
                highestPriority = priority[i];
                highestPriorityProcess = i;
            }
        }

        if (highestPriorityProcess == -1) {
            currentTime++;
        } else {
            if (remainingTime[highestPriorityProcess] == bt[highestPriorityProcess]) {
                rt[highestPriorityProcess] = currentTime - at[highestPriorityProcess];
            }

            remainingTime[highestPriorityProcess]--;
            currentTime++;

            if (remainingTime[highestPriorityProcess] == 0) {
                completed++;
                ft[highestPriorityProcess] = currentTime; // Set the Finish Time.
                tat[highestPriorityProcess] = ft[highestPriorityProcess] - at[highestPriorityProcess];
                wt[highestPriorityProcess] = tat[highestPriorityProcess] - bt[highestPriorityProcess];
                executed[highestPriorityProcess] = 1;
            }
        }
    }

    printf("Process\tBT\tAT\tTAT\tWT\tRT\tFT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], at[i], tat[i], wt[i], rt[i], ft[i]);
    }
}

void RoundRobin(int n, int at[], int bt[], int tat[], int ft[], int wt[], int rt[]) {
    int quantum;
    printf("Enter a quantum: ");
    scanf("%d", &quantum);
    int remainingTime[n];
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        remainingTime[i] = bt[i];
    }
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0 && at[i] <= currentTime) {
                done = 0;
                if (remainingTime[i] > quantum) {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    currentTime += remainingTime[i];
                    wt[i] = currentTime - bt[i] - at[i];
                    remainingTime[i] = 0;
                    tat[i] = wt[i] + bt[i];
                    rt[i] = wt[i];
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
    printf("Process\tAT\tBT\tWT\tTAT\tFT\tRT\n");
    for (int i = 0; i < n; i++) {
        ft[i] = at[i] + tat[i]; // Calculate FT based on AT and TAT
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i], ft[i], rt[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n];
    int arrival_time[n];
    int priority[n];
    int tat[n], ft[n], wt[n], rt[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter Priority for Process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    int choice;
    do {
        printf("\nScheduling Algorithms:\n");
        printf("1. FCFS\n");
        printf("2. nonPreemptiveSJF\n");
        printf("3. preemptiveSJF\n");
        printf("4. nonPreemptivePriority\n");
        printf("5. preemptivePriority\n");
        printf("6. RoundRobin\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                FCFS(n, arrival_time, burst_time, tat, ft, wt, rt);
                break;
            case 2:
                nonPreemptiveSJF(n,arrival_time,burst_time,tat,ft,wt,rt);
                break;
            case 3:
                preemptiveSJF(n,arrival_time,burst_time,tat,ft,wt,rt);
                break;
            case 4:
                nonPreemptivePriority(n,arrival_time,burst_time,tat,ft,wt,rt,priority);
                break;
            case 5:
                preemptivePriority(n,arrival_time,burst_time,tat,wt,rt,ft,priority);
                break;
            case 6:
                RoundRobin(n,arrival_time,burst_time,tat,ft,wt,rt);
                break;

            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
