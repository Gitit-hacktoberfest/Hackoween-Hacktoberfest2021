/*Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.*/

//Time Complexity : O(|s1|*|s2|)
// Auxiliary Space: O(|s1|*|s2|)

/***SOLUTION USING DP***/
#include <bits/stdc++.h>

using namespace std;
int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int t[x+1][y+1];
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0||j==0)
                t[i][j]=0;
            }
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[x][y];}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
      int ans=lcs(s1.length(),s2.length(),s1,s2);
      cout<<ans<<endl;
        
    }

    return 0;
}
