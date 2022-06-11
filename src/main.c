#include "../include/main.h"

int main(int argc, char* argv[]) {

    // input validation
    if(argc < 2) {
        printf("Not enough arguements supplied\n");
        exit(1);
    }

    // Open file for commands and buffer
    FILE* file;

    file = fopen(argv[1],"r");

    if(file == NULL) {
        printf("File failed to open\n");
        exit(1);
    }

    char ch = fgetc(file);
    while(ch != EOF) {
        printf("%c", ch);
        ch = fgetc(file);

    // TODO: Loop through file lines and grab commands by assinging to buffer
    // TODO: Then fork process and exec() command
    // TODO: Then wait and execute next command
    }

    pid_t pid;
    pid = fork(); // two lines of execution here on, parent and child

    if(pid < 0) { // ERROR
        printf("Forked Call Failed");
        exit(1);
    } else if(pid == 0) { // child process
        
        // TODO: Logic for executing call

    } else { // parent
        wait(NULL);
    }


    char* command = malloc(1); // temporary while command isn't used yet
    
    error_clean_up:
        free(command); 
    
    return 0;
}