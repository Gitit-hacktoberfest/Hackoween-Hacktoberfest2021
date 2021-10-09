//Time complexity: o(n)
#include <stdio.h>
void fun(int n)
{
 if(n>0)
 {
   fun(n-1);
   printf("%d ",n);
 }
}

int main() {
 int x=3;
 fun(3);
 return 0;
}
