
bool fork_and_exec(char* command) {

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