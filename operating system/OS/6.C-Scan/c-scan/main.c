//c-scan disc//

#include<stdio.h>

void main()
{
int queue[20],n,head,i,j,mov=0,max,diff,count,pos,temp;
printf("enter the max range of disk : ");
scanf("%d",&max);
printf("enter the size of queue request : ");
scanf("%d",&n);
printf("enter the queue\n");
for(i=0;i<n;i++)
  scanf("%d",&queue[i]);
printf("enter the initial head position : ");
scanf("%d",&head);
printf("  FROM\t    TO\t     HEAD MOVEMENTS\n");
for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        if(queue[j]>queue[j+1])
        {
            temp=queue[j];
            queue[j]=queue[j+1];
            queue[j+1]=temp;
        }
    }
queue[0]=0;
queue[n+1]=max;
pos=0;
for(i=0;i<n+1;i++)
{
   if(queue[i]<head)
       pos++;
}
temp=head;
for(i=pos;i<n+1;i++)
{
  diff=abs(temp-queue[i]);
  mov+=diff;
  printf("  %d\t   %d\t\t %d\n",temp,queue[i],mov);
  temp=queue[i];
}
temp=queue[0];;
for(i=0;i<pos;i++)
{
  diff=abs(temp-queue[i]);
  mov+=diff;
  printf("  %d\t   %d\t\t %d\n",temp,queue[i],mov);
  temp=queue[i];
}
printf("total head movements is %d\n",mov);
}
