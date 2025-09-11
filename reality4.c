#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>

#define NNN 2048

void copyij();
void copyji();
void init_mat();
long time_diff(struct timeval start, struct timeval end);

int src[NNN][NNN], dst[NNN][NNN];

int main(int argc, char **argv) {
  long elapsed;
  struct timeval tv_s, tv_e;

  /* ===== copyij ===== */
  init_mat();
  gettimeofday(&tv_s, NULL);
  copyij();
  gettimeofday(&tv_e, NULL);

  elapsed = time_diff(tv_s, tv_e);
  printf("copyij(): dim=%d: elapsed=%ld.%03ld secs\n",
         NNN, elapsed / 1000000, (elapsed % 1000000) / 1000);

  /* ===== copyji ===== */
  init_mat();
  gettimeofday(&tv_s, NULL);
  copyji();
  gettimeofday(&tv_e, NULL);

  elapsed = time_diff(tv_s, tv_e);
  printf("copyji(): dim=%d: elapsed=%ld.%03ld secs\n",
         NNN, elapsed / 1000000, (elapsed % 1000000) / 1000);

  return 0;
}

void copyij() {
  int i, j;
  for (i = 0; i < NNN; i++) {
    for (j = 0; j < NNN; j++) {
      dst[i][j] = src[i][j];
    }
  }
}

void copyji() {
  int i, j;
  for (j = 0; j < NNN; j++) {
    for (i = 0; i < NNN; i++) {
      dst[i][j] = src[i][j];
    }
  }
}

void init_mat() {
  int i, j;
  for (i = 0; i < NNN; i++)
    for (j = 0; j < NNN; j++)
      src[i][j] = dst[i][j] = 1;
}

/* Helper: returns time difference in microseconds */
long time_diff(struct timeval start, struct timeval end) {
  return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}
