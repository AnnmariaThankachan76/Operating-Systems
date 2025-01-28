 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 void main()
 {
 char *path,path1[10];
 struct stat*nfile;
 nfile=(struct stat*)malloc(sizeof(struct stat));
 printf("Enter the file name:");
 scanf("%s",path1);
 stat(path1,nfile);
 printf( "id :%d\n",nfile->st_uid);
 printf("blocksize :%ld\n",nfile->st_blksize);
 printf("acess time:%ld\n",nfile->st_atime);
 printf("modified time :%ld\n",nfile->st_mtime);
 printf("filesize :%ld\n",nfile->st_size);
 printf("mode :%d\n",nfile->st_mode);
 printf("link :%ld\n",nfile->st_nlink);
 }
 
