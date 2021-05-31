#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
    int pid, status;

    if(fork() == 0){
        execl("/bin/date", "date", 0, (char *)NULL);
        
    }

    wait(&status);

    pid = fork();

    switch (pid)
    {
    case -1:
        exit(1);
        break;

    case 0:
        printf("\n Proceso hijo, PID = %d \n", pid);
        break;
    default:
        printf("\n Proceso padre, PID = %d \n", pid);
        wait(&status);
        break;
    }

    printf("\n Fin de la ejecucion \n");
    return 0;
}
