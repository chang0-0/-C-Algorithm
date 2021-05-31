#include <stdio.h>



  int main() {
      int a;
      int *pa;

      a = 30;
      pa = &a;
      *pa = 100;

      printf("%d \n" ,a);

      return 0;
  }