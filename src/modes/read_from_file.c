#include "../../include/const.h"
#include "../../include/main.h"
#include "../../include/fork_and_exec.h"

char*** file_to_strings(FILE* file);

int read_from_file(FILE* file) {

    char*** buffer = file_to_strings(file); // ptr to lines, which are ptr to words of each line, words being C-strings

    // loop through whole file and pass each line to func to fork & process
    int num_of_success = 0;
    int i = 0;
    for( ; buffer[i] != NULL; i++) {
        num_of_success += fork_and_exec(buffer[i][0], buffer[i]);   
    }

    // TODO: Might want to rework how determining this if find cleaner solution
    if(i == num_of_success) {
    	return FILE_EXEC_SUCCESS;
    } else if(num_of_success == 0) {
	return FILE_EXEC_FAIL;
    } else {
	return FILE_EXEC_PARTIAL_SUCCESS;
    }
}

char*** file_to_strings(FILE* file) {

    /*
    This function breaks the file into an array of lines, 
    which are arrays of words (and words are C-strings).

    Example File:
        This is an
        example file
    
    Will become:
        [
            ["This", "is", "an"],
            ["example", "file"]
        ]
    */

    int number_of_lines = 1;
    char ch = fgetc(file);
    int test_i = 0;
    // first, count lines to malloc outer ptr
    while(ch != EOF) {
        if(ch == '\n') number_of_lines++;
        ch = fgetc(file);
    }

    char*** lines_of_words = malloc(sizeof(char***)*(number_of_lines+1));
    lines_of_words[number_of_lines] = NULL; // NULL used to mark end of outer two ptrs

    // TODO: Could combine these into one loop and use realloc, not sure if cleaner / more efficient
    rewind(file); // restart file
    int number_of_words = 0;
    int line = 0;
    // now count words so can alloc each index in lines with right # of words
    do {
        ch = fgetc(file);
        if(ch == ' ') {
            number_of_words++;
        } else if(ch == '\n' || ch == EOF) {
            number_of_words++;
            lines_of_words[line] = malloc(sizeof(char**)*(number_of_words+1));
            lines_of_words[line][number_of_words] = NULL; // NULL used to mark end of outer two ptrs
            number_of_words = 0;
            line++;
        }
        
    } while(ch != EOF);

    rewind(file); // restart again
    int word_len = 0;
    line = 0;
    int word_index = 0;
    // now alloc each word based on length of word
    do {
        ch = fgetc(file);
        if(ch == ' ') {
            lines_of_words[line][word_index] = malloc(sizeof(char*)*(word_len+1));
            word_index++;
            word_len = 0;
        } else if(ch == '\n' || ch == EOF) {
            lines_of_words[line][word_index] = malloc(sizeof(char*)*(word_len+1));
            line++;
            word_index = 0;
            word_len  = 0;
        } else {
            word_len++;
        }
    } while(ch != EOF);

    rewind(file);
    ch = fgetc(file);
    word_len = 0;
    line = 0;
    word_index = 0;
    int char_index = 0;
    // finally, we can now move each char into its spot
    while(ch != EOF) {
        if(ch == ' ') {
            lines_of_words[line][word_index][char_index] = '\0';
            char_index = 0;
            word_index++;
        } else if(ch == '\n') {
            lines_of_words[line][word_index][char_index] = '\0';
            line++;
            word_index = 0;
            char_index = 0;
        } else {
            lines_of_words[line][word_index][char_index] = ch;
            char_index++;
        }
        ch = fgetc(file);
    }
    lines_of_words[line][word_index][char_index] = '\0';

    return lines_of_words;
}
