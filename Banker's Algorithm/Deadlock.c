#include <stdio.h>

void Avoidance(int np, int nr) {
    int allocation[np][nr];
    int maxneed[np][nr];
    int available[nr];
    int remain[np][nr];
    int safe[np];
    int availableVector[np][nr];
    
    for (int i = 0; i < np; i++) {
        printf("Allocation matrix for process %d:", i + 1);
        for (int j = 0; j < nr; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    for (int i = 0; i < np; i++) {
        printf("Max matrix for process %d:", i + 1);
        for (int j = 0; j < nr; j++) {
            scanf("%d", &maxneed[i][j]);
        }
    }
    printf("Enter the available matrix:\n");
    for (int i = 0; i < nr; i++) {
        scanf("%d", &available[i]);
    }
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            remain[i][j] = abs(allocation[i][j] - maxneed[i][j]);
        }
    }
    int finish[np];
    for (int i = 0; i < np; i++) {
        finish[i] = 0;
    }
    int processCount = np;
    int index = 0;
    while (processCount > 0) {
        int found = 0;
        for (int i = 0; i < np; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < nr; j++) {
                    if (remain[i][j] > available[j]) {
                        break;
                    }
                }
                if (j == nr) {
                    for (int k = 0; k < nr; k++) {
                        available[k] += allocation[i][k];
                        availableVector[index][k] = available[k];
                    }
                    safe[index++] = i + 1;
                    finish[i] = 1;
                    processCount--;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("There is no safe state\n");
        }
    }
    if (processCount == 0) {
        printf("The process is in a safe state\n");
        printf("The safe sequence is:\n");
        for (int i = 0; i < np; i++) {
            printf("%d->", safe[i]);
        }
        printf("\n");
    }
    printf("Available:\n");
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            printf("%d ", availableVector[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numprocess, numresource;
    printf("Enter the number of processes: ");
    scanf("%d", &numprocess);
    printf("Enter the number of resources: ");
    scanf("%d", &numresource);
    Avoidance(numprocess, numresource);
    return 0;
}
