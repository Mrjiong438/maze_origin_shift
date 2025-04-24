#define NOB_IMPLEMENTATION
#define PATH_MAX 4096
#include "nob.h"

#define BUILD_FOLDER "build/"
#define SRC_FOLDER   "./"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    if (!nob_mkdir_if_not_exists(BUILD_FOLDER)) return 1;

    Nob_Cmd cmd = {0};

#if !defined(_MSC_VER)
    // On POSIX
    nob_cmd_append(&cmd,
            "cc", "-std=c99",
            "-pedantic", "-Wall", "-Wextra",
            "-fsanitize=undefined",
            "-o", BUILD_FOLDER"HLK.out",
            SRC_FOLDER"HKL.c");

    if (!nob_cmd_run_sync_and_reset(&cmd)) return 1;

#else
    // On MSVC
    nob_cmd_append(&cmd, "cl", "-I.", "-o", BUILD_FOLDER"HLK.exe", SRC_FOLDER"HKL.c");

    if (!nob_cmd_run_sync_and_reset(&cmd)) return 1;

    if (!nob_cmd_run_sync_and_reset(&cmd)) return 1;
#endif // _MSC_VER
    return 0;
}
