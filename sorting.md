- [Insertion Sort](#insertion-sort)
- [Merge Sort](#)
- [Heap Sort](#)
- [Quick Sort](#)
- [Counting Sort](#)
- [Radix Sort](#)
- [Bucket Sort](#)

## Insertion Sort
```pseudo
InsertionSort(A)
    for i = 2 to length(A)
        current_element = A[i]
        j = i - 1
        while j >= 0 and A[j] > current_element
            A[j + 1] = A[j]
            j = j - 1
        A[j + 1] = current_element
```
