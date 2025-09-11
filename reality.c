#include <stdio.h>
#include <stdlib.h>

void reality_1_example_1();
void reality_1_example_2();
void reality_3(int n);
double fun(int i);

typedef struct {
  int a[2];
  double d;
} struct_t;

int main(int argc,char **argv) {
  int n;  /* used to loop for reality_3() */

  reality_1_example_1();
  reality_1_example_2();

  if (argc == 1) 
      n = 5;   /* default 5 iterations */
  else 
      n = atoi(argv[1]);
  reality_3(n);

  return 0;
}

/* ===== Reality 1 Example 1 ===== */
void reality_1_example_1() {
  float f = 50000;
  int i = 40000;

  /* float multiplication is safe */
  printf("reality_1_example_1_float: f=%f\n", f);
  printf("f*f=%f >= 0\n\n", f * f);

  /* safe integer multiplication */
  printf("reality_1_example_1_int: i=%d\n", i);
  printf("i*i=%d >= 0\n\n", i * i);

  /* overflow integer multiplication */
  i = 50000;
  printf("reality_1_example_1_int: i=%d\n", i);
  printf("i*i=%d < 0\n\n", i * i);
}

/* ===== Reality 1 Example 2 ===== */
void reality_1_example_2() {
  float fx = 1e20, fy = -1e20, fz = 3.14;
  unsigned int uix = 12, uiy = 34, uiz = 56;
  int six = 12, siy = 34, siz = 56;

  /* Unsigned integers are associative */
  printf("reality_1_example_2_unsigned: uix=%u uiy=%u uiz=%u\n",
          uix, uiy, uiz);
  printf("((uix+uiy)+uiz)=%u == (uix+(uiy+uiz))=%u\n\n",
          (uix + uiy) + uiz, uix + (uiy + uiz));

  /* Signed integers are associative for these values */
  printf("reality_1_example_2_signed: six=%d siy=%d siz=%d\n",
          six, siy, siz);
  printf("((six+siy)+siz)=%d == (six+(siy+siz))=%d\n\n",
          (six + siy) + siz, six + (siy + siz));

  /* Floating point numbers are NOT associative */
  printf("reality_1_example_2_float: fx=%e fy=%e fz=%f\n",
          fx, fy, fz);
  printf("((fx+fy)+fz)=%e != (fx+(fy+fz))=%e\n\n",
          (fx + fy) + fz, fx + (fy + fz));
}

/* ===== Reality 3 ===== */
void reality_3(int n) {
  int i;
  printf("reality_3: n=%d iterations\n", n);
  for (i = 0; i < n; i++) {
    fun(i);  // Segfault expected when i >= 2
  }
}

double fun(int i) {
  volatile struct_t s;

  s.d = 3.14;
  s.a[i] = 1073741824;  // Out-of-bounds when i >= 2
  printf("fun(%d) -> %f\n", i, s.d);

  return s.d;
}

/* End of file */
