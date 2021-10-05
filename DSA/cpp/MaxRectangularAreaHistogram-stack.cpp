/*Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all
bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12*/

#include <bits/stdc++.h>

using namespace std;
long long getMaxArea(long long arr[], int n)
    {
        
        stack<long long> s;
        vector<long long>r(n),l(n);
        s.push(0);
        l[0]=0;
        for(int i=1;i<n;i++){
            while(!s.empty()&& arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty())
            l[i]=0;
            else
            l[i]=s.top()+1;
            s.push(i);
            
            
        }
        
         while(!s.empty())
            s.pop();
            s.push(n-1);
            r[n-1]=n-1;
            for(int i=n-2;i>=0;i--){
             while(!s.empty()&& arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty())
            r[i]=n-1;
            else
            r[i]=s.top()-1;
            s.push(i);
            
    }
    long long area=-1;
        for(int i=0;i<n;i++){
            area=max(area,(r[i]-l[i]+1)*arr[i]);
        }
        return area;
    }

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        
        long long ans=getMaxArea(arr,n);
        cout<<ans<<endl;
    }

    return 0;
}
