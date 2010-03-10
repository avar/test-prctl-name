/* gcc -Wall -DCHECK_NEW_NAME prctl-test.c -o prctl-test; ./prctl-test */
#include <stdio.h>
#include <stdlib.h>
#include <sys/prctl.h>
#include <errno.h>
#include <string.h>

int main(void) {
    const char* mynameis = "a perl program";
#if CHECK_NEW_NAME
    char newname[16];
#endif

    /* since Linux 2.6.9 */
    if (prctl(PR_SET_NAME, (unsigned long) mynameis, 0, 0, 0) != 0) {
        fprintf(stderr, "Got error '%s' when setting process name with prctl() to '%s'\n", strerror(errno), mynameis);
        exit(1);
    } else {
#if CHECK_NEW_NAME
        /* since Linux 2.6.11 */
        if (prctl(PR_GET_NAME, (unsigned long) newname, 0, 0, 0) != 0) {
            fprintf(stderr, "Got error '%s' when getting process name with prctl() to '%s'\n", strerror(errno), mynameis);
            exit(1);
        } else {
            if (strcmp(mynameis, newname) !=0) {
                fprintf(stderr, "The new process name '%s' doesn't match the expected '%s'\n", newname, mynameis);
                exit(1);
            } else {
                /* All OK! */
                exit(0);
            }
        }
#endif
        exit(0);
    }
}
