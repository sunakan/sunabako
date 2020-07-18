#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void child() {
  printf("子です! 子プロセスのpidは => %d\n", getpid());
  exit(EXIT_SUCCESS);
}

static void parent(pid_t pid_c) {
  printf("親です! 親pidは => %d、子pidは => %d\n", getpid(), pid_c);
  exit(EXIT_SUCCESS);
}

int main(void) {
  pid_t ret;
  ret = fork();
  if (ret == -1)
    err(EXIT_FAILURE, "fork() で失敗");
  if (ret == 0) {
    // 子プロセスならここ
    child();
  } else {
    // 親プロセスならここ
    // retが子プロセスのpid
    parent(ret);
  }
  err(EXIT_FAILURE, "ここには来ない、来たら何かおかしい");
}
