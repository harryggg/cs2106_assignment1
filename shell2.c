#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void processCommand(char* command);
void setEnv( char* progNameRaw);

int main(int argc,  char * argv[]){
	char command[999];
	setEnv(argv[0]);
	while(1){
		printf("> ");
		fgets(command, sizeof(command), stdin);
		if(command[strlen(command)-1] == '\n') {
            command[strlen(command)-1] = '\0';
        }
		processCommand(command);
	}
}

void setEnv( char* progNameRaw){
	char cwd[1024];
   	getcwd(cwd, sizeof(cwd));
   	char *progName;
   	progName = strtok(progNameRaw, "./");
   	char *path = malloc(strlen("SHELL_PATH=") + strlen(cwd) + strlen(progName) + 1);
   	strcpy(path,"SHELL_PATH=");
	strcat(path, cwd);
	strcat(path, "/");
	strcat(path, progName);
    putenv(path);
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
        char* error = strerror(errno);
        printf("Shell Error: %s\n", error);
        return;

	}else{
		printf("Loading new process with id %i\n",pid);
		int status;
	    waitpid(pid,&status,0);
	}
}