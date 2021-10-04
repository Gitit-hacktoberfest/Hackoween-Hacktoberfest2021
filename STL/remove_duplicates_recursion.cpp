/*Problem : 
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S

Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba
Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz  
*/

//Solution : 

void removeConsecutiveDuplicates(char *input) {
	

    if(input[0] == '\0')
        return ;
    if(input[0]!=input[1]){
        removeConsecutiveDuplicates(input+1);
        
    }
    else{
        int i;
        for( i = 1; input[i]!='\0';i++)
            input[i-1] = input [i];
    
    input[i-1] = input [i];
           removeConsecutiveDuplicates(input);
    }
    

}

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}