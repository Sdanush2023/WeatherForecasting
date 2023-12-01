#include<stdio.h>
#include<fcntl.h>
#include<semaphore.h>

void error_handler(char* arg);
 
int main(){
	int sval;
	//sem_unlink("/semaph");
        sem_t* semaphore;
 	semaphore = sem_open("/semaph",O_CREAT|O_RDWR,0666,1);
    
   	 if(semaphore == NULL)//SEM_FAILED == NULL
	{
		error_handler("semaphore failed");
		exit(1);
	}
	else{
		printf("\n sem_open success");
	}
	int  n =sem_getvalue(semaphore,&sval);
	if(n==-1){
		error_handler("call failed");
		exit(1);	
	}
}

void error_handler(char *arg){
	perror("%s",arg);
}
