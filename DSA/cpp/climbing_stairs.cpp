class Solution {
public:
    int climbStairs(int n) {
        vector<int>v(n+1);
        v[0]=1;
        v[1]=1; //number of ways to reach first step

        for(int i=2;i<=n;i++)
        {
            v[i]=v[i-2]+v[i-1]; //you can either take one step or two step at a time
        }
        return v[n];



    }
    //Time Complexity is O(n)
    //We created array of size n+1 i.e Space complexity is O(n)
};
