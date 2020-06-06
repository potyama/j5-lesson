#include <stdio.h>

void Strcpy(char *s_ptr, const char *p_ptr) {
  while ((*s_ptr++ = *p_ptr++) != '\0')
    ;
}

int main() {
  char s[20] = "HELLO";
  char p[20] = "hello";

  printf("s = %s\n", s);
  printf("p = %s\n", p);
  Strcpy(s, p);
  printf("s_ret = %s\n", s);
  printf("p_ret = %s\n", p);
}