//round robin//
#include<stdio.h>
struct process
{
int id,bt,wt,tt,rem;
};
void main()
{
struct process p[10];
int i,n,j,count=0,quan,alot;
float twt=0,ttt=0,awt,att;
printf("enter the no of process\n");
scanf("%d",&n);
printf("enter the burst time for processes\n");
for(i=0;i<n;i++)
{
    scanf("%d",&p[i].bt);
    p[i].id=i;
    p[i].wt=0;
    p[i].rem=p[i].bt;
    p[i].tt=0;
}
printf("enter the quantum time \n");
scanf("%d",&quan);
i=0;
printf("-----------------------------------------------------------------\n");
while(count<n)
{
    if(p[i].rem>0)
    {
        if(p[i].rem>=quan)
            alot=quan;
        else
            alot=p[i].rem;

        p[i].rem=p[i].rem-alot;
        p[i].tt=p[i].tt+alot;
        for(j=0;j<n;j++)
        {
            if(i!=j && p[j].rem!=0)
            {
                p[j].wt=p[j].wt+alot;
                p[j].tt=p[j].tt+alot;
            }
        }
        if(p[i].rem==0)
            count=count+1;
    }
    i=(i+1)%n;
}

for(i=0;i<n;i++)
{
twt=twt+p[i].wt;
ttt=ttt+p[i].tt;
}
awt=twt/n;
att=ttt/n;
printf("proc \t bt \t wt \t tt\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\n",p[i].id,p[i].bt,p[i].wt,p[i].tt);
}
printf("average wt=%f\n",awt);
printf("average tt=%f\n",att);

}

