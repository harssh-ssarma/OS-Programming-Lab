#include<stdio.h>
void main(){
	int process_number,i=0,j=1,total_time=0,total_turn_time=0;
	int process[20][3];
	printf("Enter total number of processes(maximum 20):");
	scanf("%d",&process_number);
	printf("Enter Process Burst Time\n");
	
	for(i=0;i<process_number;i++){
		printf("P[%d]:",i+1);
		scanf("%d",&process[i][0]);
		process[i][1]=0;
		process[i][2]=0;
	}
	
	process[0][1]=0;
	printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time");
	for (i=0;i<process_number;i++){
		if(i > 0){
			process[i][1]=process[i-1][2];
		}
		process[i][2]=process[i][0]+process[i][1];
	}
	printf("\n");
	for(i=0;i<process_number;i++){
		printf("P[%d]\t\t%d\t\t%d\t\t%d",i+1,process[i][0],process[i][1],process[i][2]);
		total_time+=process[i][1];
		total_turn_time+=process[i][2];
		printf("\n");
	}
	printf("Average Waiting Time:%d\n",(total_time/process_number));
	printf("Average Turnaround Time:%d",(total_turn_time/process_number));
	
}