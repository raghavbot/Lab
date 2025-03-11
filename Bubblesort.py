def bubbleSort(arr,n):
  for i in range(n):
    for j in range(n-i-1):
      if(arr[j]>arr[j+1]):
        arr[j],arr[j+1]=arr[j+1],arr[j]
  return arr

arr = [22,67,32,45,12,107,678,4,66]
n=len(arr)
sortedArray=bubbleSort(arr,n)
print ("Sorted array is:", sortedArray)