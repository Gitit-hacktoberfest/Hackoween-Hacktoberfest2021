#include <bits/stdc++.h>
using namespace std;

// convert a decimal number to its binary form
string decimalToBinary(int n){
    //finding the binary form of the number and converting it to string
    string s = bitset<64> (n).to_string();
    //Finding the first occurrence of "1" to strip off the leading zeroes
    const auto loc1 = s.find('1');
    if(loc1 != string::npos)
        return s.substr(loc1);
    return "0";
}
int main(){
    int n; cin >> n;
    // output will be in string format
    cout << decimalToBinary(n) << endl;
    return 0;
}