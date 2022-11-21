// UVa272 Tex Quotes
// Rujia Liu
#include<stdio.h>
int main() { 
  int c, q = 1;  // q: 标志变量
  while((c = getchar()) != EOF) {
    if(c == '"') { printf("%s", q ? "``" : "''"); q = !q; }
    else printf("%c", c);
  }
  return 0;
}
