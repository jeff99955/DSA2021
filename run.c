#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
int main() {
    for (int i = 0; i <= 20; i++) {
        pid_t p = fork();
        char buf[16]; 
        sprintf(buf, "%d", i);
        if (p == 0) {
            execlp("./test", "test",  buf, NULL);
        } else {
            sleep(2);
            kill(p, SIGKILL);
        }
    }
}
