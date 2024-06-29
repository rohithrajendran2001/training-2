#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
void main()
{
    int n,fp,fp1,ch;
    char r[25],w[25],buf[50];
    do{
        printf("\nMENU\n1.OPEN\n2.READ\n3.WRITE\nENTER CHOICE=\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter file to be read=");
                   scanf("%s",r);
                   printf("Enter file to write=");
                   scanf("%s",w);
                   fp=open(r,O_RDONLY);
                   fp1=open(w,O_CREAT|O_WRONLY,0642);
                   break;
            case 2:n=read(fp,buf,10);
                   break;
            case 3:write(fp1,buf,n);
                   break;
        }
    }
 while(ch<4);
}