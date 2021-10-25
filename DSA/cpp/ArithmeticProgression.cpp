// Program to create A.P series with the help of first term , total terms and difference

#include<iostream>
using namespace std;

void makeAP(int a, int n, int d){
	while(n--){
		cout<<a<<" ";
		a += d;
	}
}

int main(){
	int a,n,d;
	cin>>a>>n>>d;
	makeAP(a,n,d);
}
