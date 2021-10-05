#include <bits/stdc++.h>
using namespace std;

bool isOperand(char a)
{
    // If the character is a digit then it must
    // be an operand
    return isdigit(a);
}

double evaluatePrefix(string str)
{
    stack<double> s1;

    for (int j = str.size() - 1; j >= 0; j--) {

        // Push operand to s1
        // To convert str[j] to digit subtract
        // '0' from str[j].
        if (isOperand(str[j]))
            s1.push(str[j] - '0');

        else {

            // Operator encountered
            // Pop two elements from s1
            double o1 = s1.top();
            s1.pop();
            double o2 = s1.top();
            s1.pop();

            // Use switch case to operate on o1
            // and o2 and perform o1 O o2.
            switch (str[j]) {
            case '+':
                s1.push(o1 + o2);
                break;
            case '-':
                s1.push(o1 - o2);
                break;
            case '*':
                s1.push(o1 * o2);
                break;
            case '/':
                s1.push(o1 / o2);
                break;
            }
        }
    }

    return s1.top();
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << evaluatePrefix(str) << endl;
    return 0;
}
