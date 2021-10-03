#include<iostream>
#include<cmath> 
using namespace std;

int main(){
    int r,c;
    cout <<  "Enter length: ";
    cin >> r;
    cout << "Enter number of characters to be printed: ";
    cin >> c;
    int arr[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arr[i][j] = 0;
        }
    }
    int j =0;
    arr[0][0] = j+1;
    j++;
    while(j<c)
    {
        for(int i=1;i<r && j<c;i++)
        {
            arr[i][j] = j+1;
            j++;
        }
        for(int i=r-2;i>=0 && j<c;i--)
        {
            arr[i][j] = j+1;
            j++;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==0)
            {
                cout << " ";
            }
            else
            {
                //cout << arr[i][j];
                cout << "*";
            }
            
        }
        cout << endl;
    }
}
