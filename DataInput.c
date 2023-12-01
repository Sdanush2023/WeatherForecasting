#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

// Structure for storing temperature, humidity, and wind data
struct WeatherData {
    float temperature;
    float humidity;
    float wind;
};

int main(int argc,char *argv[]) {
    if(argc!=4){
    	printf("Incorrect arguments count !! Enter temperature humidity wind data\n");
    	exit(EXIT_FAILURE);
    }
    else{


    size_t size = sizeof(struct WeatherData);

    int shmid = shmget((key_t)2000, size, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    struct WeatherData *shared_data = shmat(shmid, NULL, 0);
   

    /*
    // Get input from the user
    printf("Enter temperature: ");
    scanf("%f", &shared_data->temperature);

    printf("Enter humidity: ");
    scanf("%f", &shared_data->humidity);

    printf("Enter wind: ");
    scanf("%f", &shared_data->wind);*/
   

    shared_data->temperature = atof(argv[1]);
    shared_data->humidity = atof(argv[2]);
    shared_data->wind = atof(argv[3]);

   
    if (shmdt(shared_data) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    printf("Data sent to shared memory.\n");
}
    return 0;
}
