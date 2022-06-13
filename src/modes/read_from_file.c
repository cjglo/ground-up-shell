#include "../../include/const.h"
#include "../utils/fork_and_exec.c"

int read_from_file(FILE* file) {

    const char* garbage = "123abc";
    fork_and_exec(garbage);
    return FILE_EXEC_FAIL;
}