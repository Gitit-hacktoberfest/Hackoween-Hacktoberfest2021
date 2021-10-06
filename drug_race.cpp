#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while (t--)
    {
        int n, x, y;
        cin >> n, x, y;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int choice = 1;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] >= x) && (arr[i] <= y))
            {
                continue;
            }
            else
            {
                choice = 0;
                break;
            }
        }
        if (choice == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
