#include "../../include/const.h"
#include "../../include/main.h"
#include "../../include/fork_and_exec.h"

char** file_to_strings(FILE* file);

int read_from_file(FILE* file) {

    char** buffer = file_to_strings(file);

    for(int i = 0; buffer[i][0] != '\0'; i++) {
        
        int begin = 0;
        int end = 0;
        char* args[1] = malloc(sizeof(char*)); // holds args
        int last_arg = 0;
        for(int j = 0; buffer[i][j] != '\0'; j++) {
            // TODO: best way to copy first arg?
            
            // go along string
            // each space or last '\0: 
                // realloc arr for one more spot and copy contents
                // add new arg 

            if(buffer[i][j] == ' ') {
                int word_size = end - begin;
                begin = j+1; // move to begin of next word
                // realloc args and copy in new word
                args = (*char) realloc(args, 1);
                
            }
            
            // memcpy( subbuff, &buff[10], 4 );  
            end++;
        }
        
    }
    printf("\n");
    
    return FILE_EXEC_SUCCESS;
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
            str_lines[line_num] = malloc(sizeof(char)*(line_len)); // extra 1 to insert null terminator
            line_len = 0;
            line_num++;
        }
    } while(ch != EOF); 

    str_lines[line_num]= malloc(sizeof(char)*(1)); 
    str_lines[line_num][0] = '\0'; // inserting null term so no when input ends 

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