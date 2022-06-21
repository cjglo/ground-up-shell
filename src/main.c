#include "../include/main.h"
#include "../include/const.h"
#include "../include/read_from_file.h"

int main(int argc, char* argv[]) {
    // TODO: Currently only reads from file, but in future
    // plan is to short our flags and execution path here

    // input validation
    if(argc < 2) {
        fprintf(stderr, "Not enough arguements supplied\n");
        exit(1);
    }

    // Open file of commands
    FILE* file = fopen(argv[1],"r");

    if(file == NULL) {
        fprintf(stderr, "File failed to open\n");
        exit(1);
    }

    switch(read_from_file(file)) {
        case FILE_EXEC_FAIL:
            fprintf( stderr, "File: %s Failed to execute commands\n", argv[1]);
            break; //TODO: Possibly should exit 1 here since was failure
        case FILE_EXEC_PARTIAL_SUCCESS:
            fprintf( stderr, "File: %s Partial failure to some of execute commands\n", argv[1]);
            break;
        case FILE_EXEC_SUCCESS:
            fprintf( stdout, "Succesfully executed commands\n");
            break;
        default:
            fprintf(stderr, "INVALID STATUS CODE RECIVED FROM read_from_file\n");
    }
    
    return 0;
}