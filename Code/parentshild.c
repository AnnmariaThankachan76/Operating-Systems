 #include <sys/types.h>
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdlib.h>
 #include <stdio.h>

 
 void  main()
 {
 pid_t childpid=fork();
 
 if(childpid==0)
 {
    printf("i am the child.The child is created");
    printf("The parent id is=%d\n",getppid());
    printf("The child id is=%d\n",getpid());
 }
 if(childpid>0)
 {
   printf("I am the parent and the child is created successfulll");
   printf("Parent id=%d\n",getpid());
   printf("child id=%d\n",childpid);
   wait(NULL);
   printf(" child is terminated.The parent moved from waiting state to running state");
 }
 if(childpid<0)
 {
 printf("The child is not created");
 }
 exit(0);
 
 }
 
 
    

