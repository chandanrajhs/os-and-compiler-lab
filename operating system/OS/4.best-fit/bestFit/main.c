//best fit//

#include<stdio.h>
struct segment
{
int id,size,allocation;
}seg[100];

int m,n,p[100];

void bestfit(int pn,int request)
{
int i,j,k,flag=0,small,sid,temp[100];
for(i=0,k=0;i<m;i++)
 {
    if(seg[i].size >= request && seg[i].allocation==0)
    {
        temp[k]=i;
        k++;
        flag=1;
    }
}
if(flag==0)
{
    printf("Requested memory %d is not allocated\n\n\n",request);
    return ;
}
small=seg[temp[0]].size;
sid=temp[0];
for(j=1;j<k;j++)
{
    if(seg[temp[j]].size<small)
    {
        small=seg[temp[j]].size;
        sid=temp[j];
    }
}
printf("process size %d is allocated to memory block %d\n\n\n",request,small);
seg[sid].allocation=1;
}

void main()
{
int i;
printf("enter the no of memory segments\n");
scanf("%d",&m);
for(i=0;i<m;i++)
{
printf("enter the memory block sizes\n");
scanf("%d",&seg[i].size);
seg[i].id=i;
seg[i].allocation=0;
}
printf("enter the no of processes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the requesting size of process %d\n",i+1);
scanf("%d",&p[i]);
bestfit(i,p[i]);
}
}
