#include <stdio.h>

char *Strcat(char *s, char *p) {
  while (*s != '\0') {
    *s;
  }
  while (*p != '\0') {
    *s++ = *p++;
  }
  *s = '\0';
  return s;
}

int main() {
  char s[10] = "Hi";
  char *p = Strcat(s, "ramen!");
  printf("s = %s\n", s);
}