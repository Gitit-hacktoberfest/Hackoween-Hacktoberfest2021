//count sort  works by counting the number of objects having distinct key values (kind of hashing). 
//Then doing some arithmetic to calculate the position of each object in the output sequence.  Time complexity - O(n+k)
//method:
//  1) find the count of every distinct element in the array
//  2) calculate the position of each element in sorted array

#include<iostream>
#include<algorithm>
using namespace std;

void countsort(int arr[], int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }

    int output[n];
    for(int i=n-1 ;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
