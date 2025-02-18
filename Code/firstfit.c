#include<stdio.h>
struct memory
  {
    int size,alloc,flag;
  }m[50];
struct process
{
  int psize,flag;
}p[10];


void main(){
int blk,i,np;
printf("Enter the number of blocks:");
scanf("%d",&blk);
for(i=1;i<=blk;i++){
printf("Size of block %d:",i);
scanf("%d",&m[i].size);
//initialising flag as 0
m[i].flag=0;
}
printf("\n");
printf("Enter the number of processes:");
scanf("%d",&np);
for(i=1;i<=np;i++){
printf("Size of process %d:",i);
scanf("%d",&p[i].psize);
}
for(i=1;i<=np;i++)
if(p[i].psize<= m[i].size && m[i].flag==0){
m[i].alloc=p[i].psize;
m[i].flag=1;
printf(" Process %d is allocated to %d",i,m[i].size);
printf("\n");
} 
else{
printf("\n");
 printf("Process %d is waiting ",i);
 
}


}
