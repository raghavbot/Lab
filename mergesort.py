import time
import random

def merge(A,l,m,r):
    B=[0]*100000
    i=l
    j=m
    k=l
    while i<m and j<=r:
        if A[i]<A[j]:
            B[k]=A[i]
            i+=1
        else:
            B[k]=A[j]
            j+=1
        k+=1
    while i<m:
        B[k]=A[i]
        i+=1
        k+=1
    while j<=r:
        B[k]=A[j]
        j+=1
        k+=1
    for k in range(l,r+1):
        A[k]=B[k]
    
def mergeSort(A,l,r):
    if l<r:
        m=(l+r)//2
        mergeSort(A,l,m)
        mergeSort(A,m+1,r)
        merge(A,l,m+1,r)
def display(A,n):
    for i in range(0,n):
        print(A[i],end=" ")
    print(" ")

A=[0]*100000
print("Enter n:",end=" ")
n=int(input())

for i in range(0,n):
    A[i]=random.randint(0,10)
# display(A,n)
start=time.time()
mergeSort(A,0,n-1)
end=time.time()
# display(A,n)
diff=end-start
print(f"The time taken is {diff:.6f} seconds")



#time taken for 1000 0.136769
# The time taken 10000 is 1.340736 seconds
# The time taken 100000 is 13.452521 seconds