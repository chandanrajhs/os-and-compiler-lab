#include<stdio.h>
#include<stdlib.h>
int main()
{
    int max,head,n,queue[20];
    int i,j,temp,sum=0,sum1=0,sum2=0,count=0;
    printf("Enter the maximum range of disk\n");
    scanf("%d",&max);
    printf("Enter the initial head position\n");
    scanf("%d",&head);
    printf("Enter the size of queue request\n");
    scanf("%d",&n);
    printf("Enter the queue of disk positions to be read\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&queue[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(queue[i]>queue[j])
            {
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(queue[i]>=head)
        {
            if(sum2==0)
            {
                sum2=sum2+(queue[i]-head);
                printf("The disk head moves from %d to %d with seek = %d\n",head,queue[i],(queue[i]-head));
                count++;
            }
            else
            {
                sum2=sum2+(queue[i]-queue[i-1]);
                printf("The disk head moves from %d to %d with seek = %d\n",queue[i-1],queue[i],(queue[i]-queue[i-1]));
                count++;
            }
        }
        if(i==n-1)
        {
            printf("The disk head moves from %d to %d with seek = %d\n",queue[i],max,(max-queue[i]));
            printf("The disk head moves from %d to 0 with seek = %d\n",max,max);
        }
    }

    count=count+2;
    for(i=0;i<n;i++)
    {
        if(queue[i]<head)
        {
            if(sum1==0)
            {
                sum1=sum1+(queue[i]-0);
                printf("The disk head moves from 0 to %d with seek = %d\n",queue[i],queue[i]);
                count++;
            }
            else
            {
                sum1=sum1+(queue[i]-queue[i-1]);
                printf("The disk head moves from %d to %d with seek = %d\n",queue[i-1],queue[i],(queue[i]-queue[i-1]));
                count++;
            }
        }
    }
    sum=sum1+sum2+(max)+(max-queue[n-1]);
    printf("\nTotal seek time = %d\n",sum);
    printf("Total head movements = %d\n",count);
    return 0;
}
