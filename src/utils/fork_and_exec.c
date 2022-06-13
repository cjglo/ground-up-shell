#include "../../include/main.h"

int fork_and_exec(const char* command) {

    if(true) return true; // TODO: Remove when ready for process forking

    pid_t pid;
    pid = fork(); // two lines of execution here on, parent and child

    if(pid < 0) { // ERROR
        printf("Forked Call Failed");
        return false;
    } else if(pid == 0) { // child process
        
        // TODO: Logic for executing call

    } else { // parent
        wait(NULL);
        return true;
    }
}