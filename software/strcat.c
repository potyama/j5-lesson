#include <stdio.h>
#include <string.h>

char *Strcat(char *s, char *p) {
  char *s_ptr = s;
  while (*s_ptr != '\0') {
    s_ptr++;
  }
  while (*p != '\0') {
    *s_ptr++ = *p++;
  }
  *s_ptr = '\0';
  return s;
}

int main() {
  char s[10] = "Hi";
  char *p = Strcat(s, "ramen!");
  printf("s = %s\n", s);
}