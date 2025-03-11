def selectionSort(arr,n):
  for i in range(n):
    least = arr[i]
    pos = i
    for j in range(i+1,n):
      if arr[j] < least:
        least = arr[j]
        pos = j
    if i != pos:
      arr[i],arr[pos] = arr[pos],arr[i]
  return arr

arr = [22,67,32,45,12,107,678,4]
n=len(arr)
sortedArray=selectionSort(arr,n)
print ("Sorted array is:", sortedArray)