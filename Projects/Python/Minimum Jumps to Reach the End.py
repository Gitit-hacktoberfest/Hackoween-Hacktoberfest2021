'''
Minimum number of jumps to reach end 

Given an array of integers where each element represents 
the max number of steps that can be made forward from that 
element. Write a function to return the minimum number of
jumps to reach the end of the array (starting from the first element).
If an element is 0, they cannot move through that element. If
the end isn’t reachable, return -1.


----------------------------------------
Solution : 

Time Complexity : O(n)
Aux Space : O(1)


'''


class Solution():
    def minJumps(self,arr,n):                        
        if len(arr) == 1 :
            return 1 
        if arr[0] == 0 :
            return -1
        jumps = 1 
        reach = arr[0]
        steps = arr[0]
        for i in range(1,n-1):
            reach = max(reach ,  arr[i] + i)
            steps-=1 
            if steps == 0 :
                jumps+=1
                if i >= reach :
                    return -1 
                steps = reach - i
        return jumps



t =  int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    ob = Solution()
    res = ob.minJumps(arr,n)
    print(res)