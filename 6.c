#include<stdio.h>
struct Process {
int  id;
int arrival;
int burst;
int waiting;
int turnaround;
};
void calculateWaitingTime(struct Process processes[], int n) {
int totalWaiting = 0;
for(int i=1; i<n; i++) {
processes[i].waiting = processes [i-1].waiting + processes[i-1].burst;
totalWaiting += processes [i].waiting;
}
float avgWaiting = (float) totalWaiting /n;
printf("Average waiting time : %.2f\n", avgWaiting);
}
void calculateTurnaroundTime( struct Process processes[], int n) {
int totalTurnaround =0;
for( int i=0; i<n ; i++) {
processes[i].turnaround = processes[i].waiting + processes [i].burst;
totalTurnaround += processes[i].turnaround;
}
float avgTurnaround = (float)totalTurnaround /n;
printf("Average Turnaround Time : %.2f\n", avgTurnaround);
}
int main () {
int n;
printf("Enter the number of processes : ");
scanf("%d",&n);
struct Process proccesses [n];
for(int i=0 ; i<n;i++){
proccesses[i].id =i+1;
printf ("Enter arrival time for process %d : ",i+1);
scanf("%d", &proccesses[i].arrival);
printf("Enter burst time for process %d: ",i+1);
scanf("%d" , &proccesses[i].burst);
}
for(int i=0; i<n-1; i++) {
for(int j=0;j<n-i-1;j++){
if(proccesses [j].arrival>proccesses[j+1].arrival) {
struct Process temp = proccesses[j];
proccesses[j] = proccesses[j+1];
proccesses[j+1]=temp;
}
}
}
calculateWaitingTime(proccesses,n);
calculateTurnaroundTime(proccesses,n);
printf("Process \t Arrival Time \t Burst Time \t Waiting Time\t TurnaroundTime\n");
for(int i=0; i<n; i++)
{
printf("%d\t %d\t\t %d\t\t %d\t\t %d\n",  proccesses[i].id, proccesses[i].arrival,proccesses[i].burst,proccesses[i].waiting, proccesses[i].turnaround);
}
return 0;
}
