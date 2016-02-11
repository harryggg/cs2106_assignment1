#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void processCommand(char* command);

int main(){
	char command[999];
	
	while(1){
		printf("> ");
		fgets(command, sizeof(command), stdin);
		if(command[strlen(command)-1] == '\n') {
            command[strlen(command)-1] = '\0';
        }
		processCommand(command);
	}
}

void processCommand(char* command){
	
	pid_t pid = fork();
	if (pid == 0) { //child process
		printf("Parent pid: %i\n",getppid());
		char *p;
		char *params[15];
		int count = 0;
		p = strtok(command, " ");
		params[count++] = p;
		while (p != NULL) {
			p = strtok(NULL, " ");
  			params[count++] = p;
  		}
        execvp(params[0],params);
        return;

	}else{
		printf("Loading new process with id %i\n",pid);
		int status;
	//	waitpid(pid,&status,0);
	}
}