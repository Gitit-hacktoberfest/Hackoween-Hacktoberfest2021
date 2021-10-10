
# Recursive Binary Search Algorithm
# Binary Search is used to search an element in a sorted array(ascending)
# Time complexity = O (Log N)  where Log has the base 2

def binary_search(list, low, high, key):

    if high >= low:
        # Calculate Mid value,using [low +(high-low)/2] to deal with larger values
        mid = low+(high-low)//2

        # If element is present at the middle itself
        if list[mid] == key:
            return mid

        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif list[mid] > key:
            return binary_search(list, low, mid - 1, key)

        # Else the element can only be present in right subarray
        else:
            return binary_search(list, mid + 1, high, key)

    else:
        # Element is not present in the array
        return -1


list = []

n = int(input("\nEnter Size of List : "))  # take size of list from user
print("\nEnter Values :")  # take values
for i in range(n):
    z = int(input())
    list.append(z)

k = int(input("\nEnter Element to be found : "))  # enter element to be found
list.sort()  # sort the list
print("\nSorted List : ", list)  # print the list
val = binary_search(list, 0, n, k)

if(val != -1):
    print("\nElement Found at index ", val)  # print index if element exists
else:
    print("\nElemetn not found!")  # print if element doesnt exists
