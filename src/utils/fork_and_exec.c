#include "../../include/main.h"

int fork_and_exec(char* command, char** args) {

    pid_t pid;
    pid = fork(); // two lines of execution here on, parent and child

    if(pid < 0) { // ERROR
        printf("Forked Call Failed");
        return false;
    } else if(pid == 0) { // child process
        
        // exec call, replaces current process with this
        execvp(command, args);

    } else { // parent
        wait(NULL);
        return true;
    }
}