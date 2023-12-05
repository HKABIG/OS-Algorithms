#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void FCFS(int n, int rs[], int head) {
    int curr_pos = head;
    int seek_length = 0;
    for (int i = 0; i < n; i++) {
        int dist = abs(curr_pos - rs[i]);
        seek_length += dist;
        curr_pos = rs[i];
    }
    printf("The total seek length is: %d\n", seek_length);
    printf("The Sequence is the same as given\n");
}

int min_diff(int n, int rs[], int curr, int vis[]) {
    int mn = INT_MAX;
    int min_diff = 0;
    for (int i = 0; i < n; i++) {
        if (vis[rs[i]] == -1 && rs[i] != curr) {
            if (abs(rs[i] - curr) < mn) {
                mn = abs(rs[i] - curr);
                min_diff = rs[i];
            }
        }
    }
    vis[min_diff]++;
    return min_diff;
}

void SSTF(int n, int rs[], int head, int vis[]) {
    int curr_pos = min_diff(n, rs, head, vis);
    int seek_length = 0;
    int seek_sequence[n + 1];
    seek_sequence[0] = curr_pos;
    for (int i = 0; i < n; i++) {
        int dist = abs(curr_pos - head);
        seek_length += dist;
        head = curr_pos;
        curr_pos = min_diff(n, rs, curr_pos, vis);
        seek_sequence[i + 1] = curr_pos;
    }
    printf("The seek length is %d\n", seek_length);
    printf("The seek Sequence is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
}

void SCAN(int n, int s, int rs[], int head) {
    int dir, curr_pos, seek_length = 0;
    printf("Enter the direction for SCAN (0 for left, 1 for right): ");
    scanf("%d", &dir);
    int seek_sequence[n + 1];
    // Sorting the seek_sequence
    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
            if (rs[i] > rs[j]) {
                int temp = rs[i];
                rs[i] = rs[j];
                rs[j] = temp;
            }
        }
    }
    int index;
    for (index = 0; index < s; index++) {
        if (dir == 0 && rs[index] >= head) {
            break;
        }
        if (dir == 1 && rs[index] < head) {
            break;
        }
    }

    if (dir == 0) {
        seek_length += abs(head - (n - 1));
        seek_length += abs((n - 1) - rs[0]);
    } else {
        seek_length += abs(head - 0);
        seek_length += abs(0 - rs[s - 1]);
    }

    printf("The seek length for SCAN is %d\n", seek_length);
    printf("The seek sequence is as follows: ");
    if (dir == 0) {
        for (int i = index; i < s; i++) {
            printf("%d ", rs[i]);
        }
        printf("%d ", n - 1);
        for (int i = index - 1; i >= 0; i--) {
            printf("%d ", rs[i]);
        }
    } else {
        for (int i = index - 1; i >= 0; i--) {
            printf("%d ", rs[i]);
        }
        printf("%d ", 0);
        for (int i = index; i < s; i++) {
            printf("%d ", rs[i]);
        }
    }
    printf("\n");
}

void LOOK(int n,int s,int rs[],int head){
    int dir,curr_pos,seek_length=0;
    printf("Enter the direction for LOOK: ");
    scanf("%d",&dir);
    int seek_sequence [n+1];
    // Sorting the seek_sequence
    for(int i=0;i<s;i++){
        for(int j=i+1;j<s;j++){
            if(rs[i]>rs[j]){
                int temp = rs[i];
                rs[i] = rs[j];
                rs[j] = temp;
            }
        }
    }
    int index ;
    for(index = 0;index<s;index++){
        if(dir==0 && rs[index]>=head){
            break;
        }
        if(dir==1 && rs[index]<head){
            break;   
        }
    }

    if(dir==0){
        seek_length += abs(head-rs[s-1]);
        seek_length += abs(rs[s-1] - rs[0]);
    }else{
        seek_length += abs(head-rs[0]);
        seek_length += abs(rs[0]-rs[s-1]);
    }
    
    printf("The seek_length for LOOK is %d \n",seek_length);
    printf("The seek_sequence is as follows: ");
    if(dir==0){
        for (int i = index; i < s; i++) {
            printf("%d ",rs[i]);
        }
        printf("%d ",n-1);
        for(int i=index-1;i>=0;i--){
            printf("%d ",rs[i]);
        }
    }else{
        for(int i=index-1;i>=0;i--){
            printf("%d ",rs[i]);
        }
        printf("%d ",0);
        for (int i = index; i < s; i++) {
            printf("%d ",rs[i]);
        }
    }
    printf("\n");
}

void CLOOK(int n,int s,int rs[],int head){
    int dir,curr_pos,seek_length=0;
    printf("Enter the direction for CSCAN: ");
    scanf("%d",&dir);
    int seek_sequence [n+1];
    // Sorting the seek_sequence
    for(int i=0;i<s;i++){
        for(int j=i+1;j<s;j++){
            if(rs[i]>rs[j]){
                int temp = rs[i];
                rs[i] = rs[j];
                rs[j] = temp;
            }
        }
    }
    int index ;
    for(index = 0;index<s;index++){
        if(dir==0 && rs[index]>=head){
            break;
        }
        if(dir==1 && rs[index]<head){
            break;   
        }
    }

    if(dir==0){
        seek_length += abs(head-rs[s-1]);
        seek_length += abs(rs[s-1]-rs[0]);
        seek_length += abs(rs[0]-rs[index-1]);
    }else{
        seek_length += abs(head-rs[0]);
        seek_length += abs(rs[0]-rs[s-1]);
        seek_length += abs(rs[s-1]-rs[index]);
    }
    
    printf("The seek_length for CSCAN is %d \n",seek_length);
    printf("The seek_sequence is as follows: ");
    if(dir==0){
        for (int i = index; i < s; i++) {
            printf("%d ",rs[i]);
        }
        // printf("%d ",rs[s-1]);
        printf("%d ",rs[0]);
        for(int i=0;i<index;i++){
            printf("%d ",rs[i]);
        }
    }else{
        for(int i=index-1;i>=0;i--){
            printf("%d ",rs[i]);
        }
        // printf("%d ",0);
        printf("%d ",rs[s-1]);
        for (int i = s-1; i>=index; i--) {
            printf("%d ",rs[i]);
        }
    }
    printf("\n");
}

void CSCAN(int n,int s,int rs[],int head){
    int dir,curr_pos,seek_length=0;
    printf("Enter the direction for CSCAN: ");
    scanf("%d",&dir);
    int seek_sequence [n+1];
    // Sorting the seek_sequence
    for(int i=0;i<s;i++){
        for(int j=i+1;j<s;j++){
            if(rs[i]>rs[j]){
                int temp = rs[i];
                rs[i] = rs[j];
                rs[j] = temp;
            }
        }
    }
    int index ;
    for(index = 0;index<s;index++){
        if(dir==0 && rs[index]>=head){
            break;
        }
        if(dir==1 && rs[index]<head){
            break;   
        }
    }

    if(dir==0){
        seek_length += abs(head-(n-1));
        seek_length += abs((n-1)-0);
        seek_length += abs(0-rs[index-1]);
    }else{
        seek_length += abs(head-0);
        seek_length += abs(0-(n-1));
        seek_length += abs((n-1)-rs[index]);
    }
    
    printf("The seek_length for CLOOK is %d \n",seek_length);
    printf("The seek_sequence is as follows: ");
    if(dir==0){
        for (int i = index; i < s; i++) {
            printf("%d ",rs[i]);
        }
        printf("%d ",n-1);
        printf("%d ",0);
        for(int i=0;i<index;i++){
            printf("%d ",rs[i]);
        }
    }else{
        for(int i=index-1;i>=0;i--){
            printf("%d ",rs[i]);
        }
        printf("%d ",0);
        printf("%d ",n-1);
        for (int i = s-1; i>=index; i--) {
            printf("%d ",rs[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, head, s;
    printf("Enter total number of tracks: ");
    scanf("%d", &n);
    printf("Enter the size of the Sequence: ");
    scanf("%d", &s);
    printf("Enter current Head position: ");
    scanf("%d", &head);
    int rs[n];
    printf("Enter Request Sequence: ");
    for (int i = 0; i < s; i++) {
        scanf("%d", &rs[i]);
    }

    int vis[n + 1];
    for (int i = 0; i < n; i++)
        vis[i] = -1;

    int choice;
    do {
        printf("\nDisk Scheduling Algorithms:\n");
        printf("1. FCFS\n");
        printf("2. SSTF\n");
        printf("3. SCAN\n");
        printf("4. LOOK\n");
        printf("5. CSCAN\n");
        printf("6. CLOOK\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                FCFS(s, rs, head);
                break;
            case 2:
                SSTF(s, rs, head, vis);
                break;
            case 3:
                SCAN(n, s, rs, head);
                break;
            case 4:
                CSCAN(n, s, rs, head);
                break;
            case 5: 
                LOOK(n, s, rs, head);
                break;
            case 6:
                CLOOK(n, s, rs, head);
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
