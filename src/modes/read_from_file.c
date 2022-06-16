#include "../../include/const.h"
#include "../../include/main.h"
#include "../../include/fork_and_exec.h"


int read_from_file(FILE* file) {

    while(ch = fgetc(file) != EOF) {
        
        if(ch == '\n') {
            // end of command

        } else if(isspace(ch)) {
            // parameter


        } else {
            // building word

        }

    }



    const char* garbage = "123abc";
    fork_and_exec(garbage);
    return FILE_EXEC_FAIL;
}

char* file_to_string(FILE* file) {

    int len = 0;
    while(fegetc(file) != EOF) len++;

    char* buffer = malloc(sizeof(char)*len+1);
    // restart file pointer to now copy file to str
    rewind(file);

    int i = 0;
    while(ch = fegetc(file) != EOF) {
        *(buffer+i)= ch;
        i++;
    }
    *(buffer+i) = '\0';

    


}