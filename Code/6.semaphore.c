#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int wait(int s){
  return --s;
  }
 int signal(int s){
  return ++s;
  }
  void producer(){
  mutex=wait(mutex);
  empty=wait(empty);
  full=signal(full);
  x++;
  printf("The producer produed an item %d \n",x);
  mutex=signal(mutex);
  }
  void consumer(){
  mutex=wait(mutex);
  full=wait(full);
  empty=signal(empty);
  printf("The consumer consumed  an item %d \n",x);
  x--;
  mutex=signal(mutex);
  }
  
  void main(){
  int ch;
  while(1){
  printf("Enter the option youn want to perform \n 1.producer \n 2.consumer \n 3.exit \n Enter your choice :");
  scanf("%d",&ch);
  switch(ch){
   case 1:
    if(mutex==1 && empty!=0){
    	producer();
    	}
    else{
    	printf("The Buffer is full");
    	}
    break;
    case 2:
    	 if(mutex==1 && full!=0){
    	consumer();
    	}
    else{
    	printf("The Buffer is empty");
    	}
    break;
    case 3:
    	printf("Exit from the buffer");
    	exit(0);
    break;
    default:
    	printf("Invalid choice");
    break;
    }
    }
    }
    
    	
    
    
 
