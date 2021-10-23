int mod=1000007;
int Solution::coinchange2(vector<int> &A, int B) {
    int i,j,n=A.size();
    vector<int>dp(B+1);
    dp[0]=1;
    for(i=0;i<n;i++){
        for(j=0;j<=B;j++){
            if(A[i]<=j){
                dp[j]=(dp[j]+dp[j-A[i]])%mod;
            }
        }
    }
    return dp[B];
}
