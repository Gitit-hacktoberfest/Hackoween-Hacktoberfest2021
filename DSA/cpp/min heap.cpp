#include <iostream>

using namespace std;
void minHeap(int *a, int b, int n){
   int j, temp;
   temp= a[b];
   j = 2 * b;
   while (j <= n) {
      if (j < n && a[j+1] < a[j])
         j = j + 1;
      if (temp < a[j])
         break;
      else if (temp >= a[j]) {
         a[j/2] = a[j];
         j = 2 * j;
      }
   }
   a[j/2] = temp;
   
}
void buildMinHeap(int *a, int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      minHeap(a,k,n);
   }
}
int main() {
   int n, i;
   cout<<"enter no of elements of array\n";
   cin>>n;
   int a[30];
   for (i = 1; i <= n; i++) {
      cout<<"enter element"<<" "<<(i)<<endl;
      cin>>a[i];
   }
   buildMinHeap(a, n);
   cout<<"Min Heap" << endl;
   for (i = 1; i <= n; i++) {
      cout<<a[i]<<endl;
   }
   
}

