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



    char* command = malloc(1); // temporary while command isn't used yet
    
    error_clean_up:
        free(command); 
    
    return 0;
}