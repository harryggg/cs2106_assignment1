#include <stdio.h>
#include <string.h>

extern char **environ;

int main()
{
	const char keyWord[10] = "SHELL_PATH";
	char *shell_path = NULL;
   	char *ret = NULL;
    for (char **env = environ; *env; ++env) {
    	ret = strstr(*env, keyWord);
    	if (ret != NULL){
    		shell_path = strstr(ret, "=");
    		shell_path++;
    	}
        printf("%s\n", *env);
    }
    printf("\n");
    if (shell_path == NULL){
    	printf("SHELL_PATH value is UNKNOWN\n");
    }else{
    	printf("SHELL_PATH value is %s\n", shell_path);
	}
}