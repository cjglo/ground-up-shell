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
        printf("%c\n", ch);
        if(ch != '\n' && ch != EOF) {
            line_len++;
        } else {
            // same as incr ptr then deref
            str_lines[line_num] = malloc(sizeof(char)*(line_len+1));
            printf("line_num: %d\n", line_num);
            line_len = 0;
            line_num++;
        }
    } while(ch != EOF);

    printf("done\n");

    rewind(file);
    // time to insert chars

    line_num = 0;
    int pos_in_line = 0;
    ch = fgetc(file);
    while(ch != EOF) {

        printf("%c\n", ch);
        if(ch != '\n') {
            printf("line_num: %d , pos: %d\n", line_num, pos_in_line);
            str_lines[line_num][pos_in_line] = ch;
            pos_in_line++;
        } else {
            // str_lines[line_num][pos_in_line] = '\0';
            pos_in_line = 0;
            line_num++;
        }
        ch = fgetc(file);
    }

    return str_lines;
}