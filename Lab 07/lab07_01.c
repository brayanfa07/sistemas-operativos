#include <signal.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



void myhandler(int a) { 
	printf("In myhandler\n"); 
}

int main(void) {

	/*struct sigaction info, handler;
	handler.sa_handler = &myhandler;
	if (sigaction(SIGUSR1,&handler,&info) != -1)
		printf("New handler set.\n");
	raise(SIGUSR1);
	*/
}



int number = 0;
pid_t pidchild1;
pid_t pidchild2;

int main(){

    int indexVar;
    for (indexVar = 0; indexVar < 2; indexVar++){
    	pid = fork();

       	if (pid == 0){
        	if (number %2 == 0){
        		printf("This is the parent process, with the pid %d and the number %d\n", pid, number);
           	}
       	}

       	else{
       		if (pid > 0){
            	if (number %2 != 0){
                	printf("This is the child process, with the pid %d and the number %d\n", pid, number);

                	number++;
           		}
       		}
    	}
    	
    }
}
