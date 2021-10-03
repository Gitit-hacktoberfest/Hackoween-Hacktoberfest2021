/*
Objective: To get the sum of the first n number using recursion. 

Base Case : If n == 0:
return 0;
We add the current number and recurse for Sum(n-1) 

Time Complexity: O(N)
Space Complexity: O(N)
*/

int Sum (int n){
    if(n==0)
     return 0;
    int prevSum= Sum(n-1);
    return n + prevSum;
}
