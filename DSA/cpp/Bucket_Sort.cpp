//Bucket sort
/*The process of bucket sort can be understood as a scatter-gather approach*/
/*
Time Complexity:
Best : O(n+k)
Worst : O(n^2)
Average : O(n)
Space Complexity : O(n+k)
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to sort arr[] 
void bucketSort(float arr[], int n)
{
	
	//Create n empty buckets
	vector<float> b[n];

	//Put array elements different buckets
	for (int i = 0; i < n; i++) {
		int bi = n * arr[i]; 
		b[bi].push_back(arr[i]);
	}
    //Sort individual buckets
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	//Concatenate all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}


int main()
{   int n,i;
    float arr[100]; 
    cout<<"Enter Size of Array: ";
    cin>>n;
    //input element from user
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
	bucketSort(arr, n);
    //Print Sorted Array
	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
