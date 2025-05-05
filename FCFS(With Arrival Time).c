#include <stdio.h>

typedef struct{
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
}process;

void fetchDetails(process p[], int n){
    
    printf("Enter the Arrival Time and Burst Time of the processess: \n");
    for(int i=0;i<n;i++){
        p[i].completion_time = 0;
        p[i].turnaround_time = 0;
        p[i].waiting_time = 0;
        printf("Enter the Arrival and Burst Time of %d: ",i+1);
        scanf("%d %d",&p[i].arrival_time,&p[i].burst_time);
    }
}

void sorting(process p[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].arrival_time>p[j+1].arrival_time){
                process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    p[0].completion_time = p[0].burst_time;
    
}

void calCompletionTime(process p[], int n){
    for(int i=1;i<n;i++){
        p[i].completion_time = p[i-1].completion_time + p[i].burst_time;
    }
}


void calTurnaroundTime(process p[], int n){
    for(int i=0;i<n;i++){
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
    }
}
void calWaitingTime(process p[], int n){
    for(int i=0;i<n;i++){
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

void display(process p[], int n){
    printf("Printing the processes: \n");
    printf("Pid  Burst Time  Arrival Time  Completion Time  Turnaround Time    Waiting Time\n");
    for(int i=0;i<n;i++){
        printf("%d          %d           %d              %d             %d                  %d",i+1,p[i].burst_time,p[i].arrival_time,p[i].completion_time,p[i].turnaround_time,p[i].waiting_time);
        printf("\n");
    }
}

int main() {
    
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process p[n];
    
    fetchDetails(p,n);
    sorting(p,n);
    calCompletionTime(p,n);
    calTurnaroundTime(p,n);
    calWaitingTime(p,n);
    display(p,n);
    
}