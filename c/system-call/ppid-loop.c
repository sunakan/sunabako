#include <sys/types.h>
#include <unistd.h>

int main(void) {
  for (;;) {   // ユーザーモード
    getppid(); // カーネルモード
  }            // ユーザーモード
}
