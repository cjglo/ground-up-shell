#include "../../include/const.h"
#include "../../include/main.h"
#include "../../include/fork_and_exec.h"

char*** file_to_strings(FILE* file);

int read_from_file(FILE* file) {

    char*** buffer = file_to_strings(file); // ptr to lines, which are ptr to words of each line, words being C-strings

    printf("\nCOMPLETED FUNCTION\n\n");

    for(int i = 0; buffer[i] != NULL; i++) {

        for(int j = 0; buffer[i][j] != NULL; j++) {

            printf("%s\n", buffer[i][j]);
        }

    }

    // for(int i = 0; buffer[i][0] != '\0'; i++) {
    //     printf("Should be: %s\n", buffer[i]);

    //     // for(int x = 0; buffer[i][x] != '\0'; x++) {
    //     //     printf("%d ", buffer[i][x]);
    //     // }

    //     int begin = 0;
    //     int end = 0;
    //     char** args = malloc(0); // holds args
    //     int last_arg = -1;
    //     for(int j = 0; true; j++) {
    //         // TODO: best way to copy first arg?
            
    //         // printf("begin: %d, end: %d, ij: %d\n", begin, end, buffer[i][j]);
    //         // go along string
    //         // each space or last '\0: 
    //             // realloc arr for one more spot and copy contents
    //             // add new arg 

    //         if(buffer[i][j] == ' ') {
    //             // printf("HERE2\n");
    //             int word_size = end - begin;
    //             // realloc args and copy in new word
    //             args = (char**) realloc(args, sizeof(char*));
    //             args[++last_arg] = malloc( sizeof(char*)*word_size); // TODO: Need plus 1?
                
    //             for(int k = begin; k<word_size; k++) {
    //                 args[last_arg][k] = buffer[i][k];
    //             }
    //             args[last_arg][end] = '\0';
    //             begin = j+1;// move to begin of next word
    //         } 
    //         if(buffer[i][j] == '\0') { // EXIT CONDITION
    //             // printf("HERE!");
    //             // int word_size = end - begin - 1;
    //             // // realloc args and copy in new word
    //             // args = (char**) realloc(args, sizeof(char*));
    //             // args[++last_arg] = malloc( sizeof(char*)*word_size+1); // TODO: Need plus 1?
    //             // memcpy(args[last_arg], &buffer[i][begin], end - 1);
    //             // args[last_arg][end] = '\0';
    //             // begin = j+1; // move to begin of next word
    //             break;
    //         }
    //         // memcpy( subbuff, &buff[10], 4 );  
    //         end++;
    //     }
    //     printf("%s\n", args[0]);
    //     printf("%s\n", args[1]);
    //     printf("%s\n", args[2]);
    // }
    // printf("\n");
    
    return FILE_EXEC_SUCCESS;
}

char*** file_to_strings(FILE* file) {

    int number_of_lines = 1;
    char ch = fgetc(file);
    int test_i = 0;
    while(ch != EOF) {
        printf("%d\n", test_i);
        if(ch == '\n') number_of_lines++;
        ch = fgetc(file);
    }

    char*** str_lines = malloc(sizeof(char**)*(number_of_lines+1));
    str_lines[number_of_lines] = NULL; // to mark end
    // restart file pointer to now copy file to str
    rewind(file);

    printf("\nHERE!\n");

    ch = fgetc(file);
    int number_of_words = 0;
    int line = 0;
    // TODO: Could combine these into one loop and use realloc, not sure if cleaner / more efficient
    do {
        if(ch == ' ') {
            number_of_words++;
        } else if(ch == '\n' || ch == EOF) {
            number_of_words++;
            str_lines[line] = malloc(sizeof(char*)*(number_of_words+1));
            str_lines[line][number_of_words] = NULL; // to mark end
            number_of_words = 0;
            line++;
        }
        ch = fgetc(file);
    } while(ch != EOF);

    printf("\nHERE!22\n");


    rewind(file);
    ch = fgetc(file);
    int word_len = 0;
    line = 0;
    int word_index = 0;
    do {
        printf("%c\n", ch);
        if(ch == ' ') {
            printf("line: %d, word_i: %d, word_len: %d\n", line, word_index, word_len);
            str_lines[line][word_index] = malloc(sizeof(char)*(word_len+1));
            word_index++;
            word_len = 0;
        } else if(ch == '\n' || ch == EOF) {
            str_lines[line][word_index] = malloc(sizeof(char)*(word_len+1));
            line++;
            word_index = 0;
            word_len  = 0;
        } else {
            word_len++;
        }
        ch = fgetc(file);
    } while(ch != EOF);

    printf("\nHERE!33\n");


    rewind(file);
    ch = fgetc(file);
    word_len = 0;
    line = 0;
    word_index = 0;
    int char_index = 0;
    while(ch != EOF) {
        if(ch == ' ') {
            str_lines[line][word_index][char_index] = '\0';
            char_index = 0;
            word_index++;
        } else if(ch == '\n') {
            str_lines[line][word_index][char_index] = '\0';
            line++;
            word_index = 0;
            char_index = 0;
        } else {
            str_lines[line][word_index][char_index] = ch;
            char_index++;
        }
        ch = fgetc(file);
    }
    str_lines[line][word_index][char_index] = '\0';

    return str_lines;


    // int line_len = 1;
    // int line_num = 0;
    // do {
    //     ch = fgetc(file);
    //     if(ch != '\n' && ch != EOF) {
    //         line_len++;
    //     } else {
    //         // same as incr ptr then deref
    //         str_lines[line_num] = malloc(sizeof(char)*(line_len+1)); // extra 1 to insert null terminator
    //         line_len = 0;
    //         line_num++;
    //     }
    // } while(ch != EOF); 

    // str_lines[line_num]= malloc(sizeof(char)*(1)); 
    // str_lines[line_num][0] = '\0'; // TODO: Need this to determine end of char**?  Might be bad practice cause looks like a string

    // rewind(file);

    // // time to insert chars
    // line_num = 0;
    // int pos_in_line = 0;
    // ch = fgetc(file);
    // while(ch != EOF) {
    //     if(ch != '\n') {
    //         str_lines[line_num][pos_in_line] = ch;
    //         pos_in_line++;
    //     } else {
    //         str_lines[line_num][pos_in_line] = '\0';
    //         pos_in_line = 0;
    //         line_num++;
    //     }
    //     ch = fgetc(file);
    // }

    // return str_lines;
}