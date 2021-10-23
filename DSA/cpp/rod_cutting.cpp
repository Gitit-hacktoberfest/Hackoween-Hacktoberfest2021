class Solution{
  public:
    int rod(int price[],int l,int n,vector<vector<int>>&dp){
        if(n==0||l==0){
            return 0;
        }
        if(dp[n][l]!=-1){
            return dp[n][l];
        }
        if(l>=n){
            dp[n][l]=max(price[n-1]+rod(price,l-n,n,dp),rod(price,l,n-1,dp));
        }
        else{
            dp[n][l]=rod(price,l,n-1,dp);
        }
        return dp[n][l];
    }
    int cutRod(int price[], int n) {
        //code here
        int i,j;
        vector<vector<int>>dp(n+1);
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                dp[i].push_back(-1);
            }
        }
        int ans=rod(price,n,n,dp);
        return ans;
    }
};
