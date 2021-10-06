Q. To Find the Prime Factor of a given number using Sieve of Eratosthenes algorithm.

* Time Complexity: O(nloglogn)
    
#include <iostream>
using namespace std;

void primefactor(int n){
    // stores smallest prime factor for every number
    int spf[100] = {0};
    
    for(int i=2;i<=n;i++){
        spf[i] = i; // marking smallest prime factor for every number to be itself.
    }
    for(int i=2;i<=n;i++){
        if(spf[i] == i){
            for(int j=i*i;j<=n;j+=i){ // marking SPF for all numbers divisible by i
                if(spf[j] == j){ // marking spf[j] if it is not previously marked
                    spf[j] = i;
                }
            }
        }
    }
    // A O(log n) function returning prime_factorization by dividing by smallest prime factor at every step
    while(n != 1){
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }
}
// main method
int main(int argc, const char * argv[]) {
    int n;
    cout<<"Enter a number:"<<endl;
    cin>>n;
    
    primefactor(n); // calling primefactor function
    return 0;
}
