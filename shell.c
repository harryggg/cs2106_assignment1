#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void processCommand(char* command);

int main(){
	char command[999];
	while(1){
		printf("> ");
		fgets(command, sizeof(command), stdin);
		processCommand(command);
	}
}

void processCommand(char* command){
	
	pid_t pid = fork();
	if (pid == 0) { //child process
		printf("Parent pid: %i\n",getppid());
	}else{
		printf("Loading new process with id %i\n",pid);
	}

}