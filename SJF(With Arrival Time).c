#include <stdio.h>

typedef struct{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int completed;
}process;


void fetchDetails(process p[], int n){
    printf("Enter the arrival and burst time of the processes: \n");
    for(int i=0;i<n;i++){
        printf("Enter the Arrival and Burst Time of process %d: ",i+1);
        scanf("%d %d",&p[i].arrival_time,&p[i].burst_time);
        p[i].completed = 0;
    }
}

void SJF(process p[], int n){
    int t=0;
    int count = n;
    while(count!=0){
        int min = 9999;
        int index = -1;
        for(int i=0;i<n;i++){
            if(p[i].arrival_time<=t && p[i].burst_time<=min && p[i].completed == 0){
                min = p[i].burst_time;
                index = i;
            }
        }
        if(index != -1){
            p[index].completion_time = t + p[index].burst_time;
            p[index].turnaround_time = p[index].completion_time - p[index].arrival_time;
            p[index].waiting_time = p[index].turnaround_time - p[index].burst_time;
            p[index].completed = 1;
            t += p[index].burst_time;
            count--;
        }
        else{
           t++; 
        }
    }
}

void display(process p[], int n){
    printf("Pid  Arrival Time  Burst Time  Completion Time  Turnaround Time  Waiting Time\n");
    for(int i=0;i<n;i++){
        printf("%d         %d             %d             %d                %d                %d\n",i+1,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].turnaround_time,p[i].waiting_time);
    }
}


int main() {
    
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process p[n];
    
    
    fetchDetails(p,n);
    SJF(p,n);
    display(p,n);

    return 0;
}