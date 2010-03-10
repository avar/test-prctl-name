#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/prctl.h>
#include <errno.h>
#include <unistd.h>

int main(const int argc, const char **argv) {
    const char* argv_name = argv[1];
    const char* prctl_name = argv[2];
    const char now_name[16];
    printf("About to argv  name to '%s' with length '%d'\n", argv_name, strlen(argv_name));
    printf("About to prctl name to '%s' with length '%d'\n", prctl_name, strlen(prctl_name));

    argv[0] = argv_name;

    if (prctl(PR_SET_NAME, (unsigned long) prctl_name, 0, 0, 0) != 0) {
        printf("Got error '%s' when setting name to '%s'\n", strerror(errno), prctl_name);
    } else {
        prctl(PR_GET_NAME, now_name);
        printf("Set prctl name, it's now '%s', with length '%d'\n", now_name, strlen(now_name));
        printf("Set argv name, it's now '%s', with length '%d'\n", argv[0], strlen(argv[0]));
    }

    /* Show up in top(1) */
    for(;;){}

    sleep(600);

    return 0;
}


