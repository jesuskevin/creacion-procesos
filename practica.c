#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdint.h>

int main(){
    char var[20];
    int x;

    while(1){
        printf("\n Escriba el nombre del comando \n");
        scanf("%s", var);

        if(strcmp(var, "salir") == 0){
            printf("Saliendo... \n");
            exit(0);
        }

        x = fork();
        switch (x)
        {
        case -1:
            exit(1);
            break;

        case 0:
            /*printf("proceso hijo, PID = %d \n", getpid());*/
            sleep(1);
            execlp(var, var, NULL);
            exit(0);
            break;
        
        default:
            wait(NULL);
            /*printf("Proceso hijo ha terminado, entrando al proceso padre PID = %d \n", getpid());*/
            break;
        }

        /*x = fork();
        if(x == 0){
            sleep(1);
            execlp(var, var, NULL);
            exit(0);
        }else{
            wait(NULL);
            printf("Proceso padre, PID = %d \n", getpid());
            printf("Saliendo...");
        }*/
    }
}