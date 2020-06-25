//best fit//

#include<stdio.h>
struct segment
{
int id,size,allocation;
}seg[100];

int m,n,p[100];

void bestfit(int pn,int request)
{
int i,flag=0,sid,min=999;
for(i=1;i<=m;i++)
{
    if(seg[i].size>=request && seg[i].size<min)
    {
        min=seg[i].size;
        flag=1;
        sid=seg[i].id;
    }
}
if(flag==0)
{
    printf("The process %d having size %d could not be allocated to any memory blocks\n",pn,request);
}
else
{
    printf("The process %d having size %d was successfully allocated to memory block %d having size %d\n\n",pn,request,sid,seg[sid].size);
    seg[sid].size=seg[sid].size-request;
    seg[sid].allocation=1;
}
}

void main()
{
int i;
printf("enter the no of memory segments\n");
scanf("%d",&m);
for(i=1;i<=m;i++)
{
printf("enter the memory block %d's size\n",i);
scanf("%d",&seg[i].size);
seg[i].id=i;
seg[i].allocation=0;
}
printf("the memory block sizes are\n");
for(i=1;i<=m;i++)
{
    printf("%d ",seg[i].size);
}
printf("\n\nenter the no of processes\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("enter the requesting size of process %d\n",i);
scanf("%d",&p[i]);
bestfit(i,p[i]);
}
printf("\nThe allocation array is\n");
for(i=1;i<=m;i++)
{
    printf("%d ",seg[i].allocation);
}
printf("\nThe remaining memory block sizes are\n ");
for(i=1;i<=m;i++)
{
    printf("%d ",seg[i].size);
}
}
