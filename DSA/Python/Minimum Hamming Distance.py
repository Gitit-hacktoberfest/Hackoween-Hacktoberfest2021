a=int(input())                  #input the number of elements in the array to find min hamming distance
arr=[]

def hammingdist(a,b):           #Get an array a and b for comparing and checking the hamming distance between them
                                    
    counter=0
    
    for i in range (0,len(a)):
        if(a[i]==b[i]):                     #Traverse through each element of a and b to check whether they are equal
            continue
        else:
            counter=counter+1               #Set a counter variable to store the number of unequal terms
    return counter                          #Return the hamming distance

minhdist=99999

for i in range(0,a):
    
    arr.append(input())

for i in range(0,a):
    
    for j in range(i+1,a):

        x=hammingdist(arr[i],arr[j])        #Traverse through arr such that each string is compared with the other
        
        if(x<minhdist):
            minhdist=x                      #Store the hamming distance of the closest strings

            
print(minhdist)                             #Print the minimum hamming distance
