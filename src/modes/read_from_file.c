#include "../../include/const.h"
#include "../../include/main.h"
#include "../../include/fork_and_exec.h"

char** file_to_string(FILE* file);

int read_from_file(FILE* file) {

    char** buffer = file_to_string(file);

    for(int i = 0; i<3; i++) {
        // printf("%s\n", buffer[i]);
    }
    
    return FILE_EXEC_FAIL;
}

char** file_to_string(FILE* file) {

    char ch;
    int number_of_lines = 1;
    while(ch = fgetc(file) != EOF) {
        if(ch == '\n') number_of_lines++;
    }

    char** str_lines = malloc(sizeof(char)*(number_of_lines+1));
    // restart file pointer to now copy file to str
    rewind(file);

    int line_len = 1;
    int line_num = 1;
    while(ch = fgetc(file) != EOF) {
        if(ch != '\n') {
            line_len++;
        } else {
            // same as incr ptr then deref
            str_lines[line_num] = malloc(sizeof(char)*(line_len+1));
            line_len = 0;
        }
    }

    rewind(file);
    // time to insert chars

    line_num = 0;
    int pos_in_line = 0;
    while(ch = fgetc(file) != EOF) {
        
        if(ch != '\n') {
            str_lines[line_num][pos_in_line] = ch;
            pos_in_line++;
        } else {
            // str_lines[line_num][pos_in_line] = '\0';
            pos_in_line = 0;
            line_num++;
        }
    }

    return str_lines;
}