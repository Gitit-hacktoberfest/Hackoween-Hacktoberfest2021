/*
Factorial

Objective: To get the factorial of the n 

Base Case : If n == 0:
return 1;
We multiply the current number and recurse for factorial(n-1) 

Time Complexity: O(N)
Space Complexity: O(N)
*/

int factorial(int n){
    if(n==0)
     return 1;
    //int prevFact=factorial(n-1)
    //return n * prevFact
    return n * factorial(n-1);
}