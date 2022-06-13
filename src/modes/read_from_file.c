#include "../../include/const.h"
#include "../../include/main.h"
#include "../../include/fork_and_exec.h"


int read_from_file(FILE* file) {

    const char* garbage = "123abc";
    fork_and_exec(garbage);
    return FILE_EXEC_FAIL;
}