#include<stdio.h>
struct process
{
int pid,bt,wt,tt;
};

void main()
{
struct process p[10];
int bt,i,n,awt,att,ttt=0,twt=0;
printf("enter the no of processes\n");
scanf("%d",&n);
printf("enter the burst time of %d processes\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&p[i].bt);
p[i].pid=i;
}
p[0].wt=0;
p[0].tt=p[0].bt+p[0].wt;

for(i=1;i<n;i++)
{
p[i].wt=p[i-1].wt+p[i-1].bt;
p[i].tt=p[i].wt+p[i].bt;
}

printf("\n pid \t bt \t wt \t tt \t \n");
for(i=0;i<n;i++)
{
printf("\n %d \t %d \t %d \t %d \t \n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
}
for(i=0;i<n;i++)
{
twt=p[i].wt+twt;
ttt=p[i].tt+ttt;
}
awt=twt/n;
att=ttt/n;
printf("\naverage waiting time =%d\n",awt);
printf("average turnaround time =%d",att);

}


