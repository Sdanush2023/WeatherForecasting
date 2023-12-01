#include<stdio.h>
#include<fcntl.h>
#include<semaphore.h>

 
int main(){
	int sval;
	//sem_unlink("/semaph");
        sem_t* semaphore;
 	semaphore = sem_open("/semaph",O_CREAT|O_RDWR,0666,1);
    
   	 if(semaphore == NULL)//SEM_FAILED == NULL
	{
		perror("sem_open fail\n");
		return -1;
	}
	else{
		printf("\n sem_open success");
	}
	int  n =sem_getvalue(semaphore,&sval);
	if(n==-1){
		printf("system call failed\n");
	}
}
