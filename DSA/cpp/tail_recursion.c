// Time complexity: o(n), Space complexity: o(n)
// Tail recursion

#include <stdio.h>
void fun(int n)
{
 if(n>0)
 {
   printf("%d ",n);
   fun(n-1);
 }
}

int main() {
 int x=3;
 fun(3);
 return 0;
}

// O/P: 3 2 1
