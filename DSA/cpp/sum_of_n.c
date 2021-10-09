// 1+2+3+4...+n
//Time complexity: o(n)

#include <stdio.h>
int sum(int n)
{
 if(n==0)
 {
   return 0;
 }
 return sum(n-1)+n;
}

int main(void) {
 printf("%d", sum(4));
 return 0;
}
