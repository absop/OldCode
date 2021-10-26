(include "stdio.h")
(include "stdlib.h")

int f() {  }
int g() {  }

int main()
{
  int (*func) =
        (case os
            [(win32) f]
            [(linux) g]);

  func();

  return 0;
}
