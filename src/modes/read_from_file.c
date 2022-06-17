#include "../../include/const.h"
#include "../../include/main.h"
#include "../../include/fork_and_exec.h"

char** file_to_strings(FILE* file);

int read_from_file(FILE* file) {

    char** buffer = file_to_strings(file);

    //TODO: Need number of lines, and I guess 
    // break down each line into array of words?  
    // redesign might be necessary, where grab a line at 
    // a time.  Not sure
    
    
    return FILE_EXEC_FAIL;
}

char** file_to_strings(FILE* file) {

    char ch;
    int number_of_lines = 1;
    ch = fgetc(file);
    while(ch != EOF) {
        if(ch == '\n') number_of_lines++;
        ch = fgetc(file);
    }

    char** str_lines = malloc(sizeof(char)*(number_of_lines+1));
    // restart file pointer to now copy file to str
    rewind(file);

    int line_len = 1;
    int line_num = 0;
    do {
        ch = fgetc(file);
        if(ch != '\n' && ch != EOF) {
            line_len++;
        } else {
            // same as incr ptr then deref
            str_lines[line_num] = malloc(sizeof(char)*(line_len+1));
            line_len = 0;
            line_num++;
        }
    } while(ch != EOF);

    rewind(file);

    // time to insert chars
    line_num = 0;
    int pos_in_line = 0;
    ch = fgetc(file);
    while(ch != EOF) {
        if(ch != '\n') {
            str_lines[line_num][pos_in_line] = ch;
            pos_in_line++;
        } else {
            pos_in_line = 0;
            line_num++;
        }
        ch = fgetc(file);
    }

    return str_lines;
}