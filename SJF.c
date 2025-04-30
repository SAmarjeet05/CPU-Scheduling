#include <stdio.h>

typedef struct{
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
}process;

void sorting(process p[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].burst_time > p[j+1].burst_time){
                process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void fetchDetails(process p[], int n){
    printf("Enter the Burst Time of every process: \n");
    for(int i=0;i<n;i++){
        p[i].burst_time = 0;
        p[i].waiting_time = 0;
        p[i].turnaround_time = 0;
        p[i].pid = i;
        printf("Enter the Burst Time of p[%d]: ",i);
        scanf("%d",&p[i].burst_time);
    }
    p[0].waiting_time = 0;
}

void calculateWaitingTime(process p[], int n){
    for(int i=1;i<n;i++){
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }
}

void calculateTurnaroundTime(process p[], int n){
    for(int i=0;i<n;i++){
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

void display(process p[], int n){
    printf("Printing the values: \n");
    printf("Pid    Burst Time    Waiting Time    Turnaround Time\n");
    for(int i=0;i<n;i++){
        printf("  %d         %d              %d             %d\n",p[i].pid,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
    }
}

void avg(process p[], int n){
    float total_waiting = 0, total_turnaround = 0;
    for(int i=0;i<n;i++){
        total_waiting += p[i].waiting_time;
        total_turnaround += p[i].turnaround_time;
    }
    float avg_waiting = total_waiting/n;
    float avg_turnaround = total_turnaround/n;
    printf("Avg Waiting Time: %0.2f",avg_waiting);
    printf("Avg Turnaround Time: %0.2f",avg_turnaround);
}

int main() {
    //When Arrival time is not included
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process p[n];
    
    fetchDetails(p,n);
    sorting(p,n);
    calculateWaitingTime(p,n);
    calculateTurnaroundTime(p,n);
    display(p,n);
    avg(p,n);

    return 0;
}
