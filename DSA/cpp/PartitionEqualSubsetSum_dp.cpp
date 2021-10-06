/*Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.*/

//Time complexity:-O(N*sum of elements)
//Space complexity:-O(N*sum of elements)

#include <bits/stdc++.h>
using namespace std;
int equalPartition(int N, int arr[])
    {
        
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0)
        return 0;
        
        
        else{
            sum=sum/2;
            
            int t[N+1][sum+1];
        
        for(int i=0;i<N+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0)
                t[i][j]=0;
                if(j==0)
                t[i][j]=1;
            }
        }
        
        for(int i=1;i<N+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]>sum)
                t[i][j]=t[i-1][j];
                else
                t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                
            }
        }
        return t[N][sum];
        }}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=equalPartition(n,arr);
        if(ans)
      cout<<"YES"<<endl;
      else
      cout<<"NO"<<endl;
      
        
    }

    return 0;}
