#include <stdio.h>
int findRotationCount(int nums[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        if (nums[low] <= nums[high]) {
            return low;
        }
        int mid = (low + high) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;
        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
            return mid;
        }
        else if (nums[mid] <= nums[high]) {
            high = mid - 1;
        }
        else if (nums[mid] >= nums[low]) {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n=6;
    int nums[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    int count = findRotationCount(nums, n);
    printf("%d", count);
    return 0;
}
*/ Time complexity-O(n)
   Space complexity-O(n) */