#include<stdio.h>
struct process
{
int id,bt,wt,tt;
};
void main()
{
struct process p[100],temp;
int i,j,n;
float awt,att;
printf("enter the no of process\n");
scanf("%d",&n);
printf("enter the burst time of %d processes\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&p[i].bt);
p[i].id=i;
}

for(i=0;i<n-1;i++)
{
for(j=0;j<n-1-i;j++)
{
    if(p[j].bt>p[j+1].bt)
    {
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
    }
}
}
p[0].wt=0;
p[0].tt=p[0].bt;
for(i=1;i<n;i++)
{
p[i].wt=p[i-1].wt+p[i-1].bt;
p[i].tt=p[i].wt+p[i].bt;
}
awt=att=0;
for(i=0;i<n;i++)
{
awt=awt+p[i].wt;
att=att+p[i].tt;
}
awt=awt/n;
att=att/n;
printf("proc\tbt\twt\ttt\t\n");
for(i=0;i<n;i++)
{
printf("p[%d]\t%d\t%d\t%d\t\n",p[i].id,p[i].bt,p[i].wt,p[i].tt);
}
printf("\naverage waiting time is %f\n",awt);
printf("\n average turnaround time is %f",att);
}
