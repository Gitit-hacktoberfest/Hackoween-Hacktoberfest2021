/*
Fibonacci

Objective: To get the Fibonacci of n
 
Recurrence Relation: F(n) = F(n-1) + F(n-2)

Base Case : If (n == 0 or n == 1):	
//Since F(n) depends on prev two states return n;	//so base case will have two cases
We calculate fib(n - 1), fib(n - 2) using recursion, and return the sum of the two 

Time Complexity: O(N)
Space Complexity: O(N)
*/

int fib(int n){
    if(n==0 || n==1) //base class
     return n;
    return fib(n-1) + fib(n-2);
}
