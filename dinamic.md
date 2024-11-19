# Dynamic Memory Functions in C

In C, dynamic memory allocation allows you to allocate memory at runtime, which is essential when the size of data is unknown at compile-time. The C Standard Library provides several functions for managing dynamic memory. These functions are defined in the `stdlib.h` header file.

## Functions for Dynamic Memory Management

### 1. **malloc()**  
Allocates a specified number of bytes of memory and returns a pointer to the beginning of the block.

```c
void *malloc(size_t size);
```
- `size` : The number of bytes to allocate.
- Returns a pointer to the allocated memory, or NULL if the allocation fails.
Example:

```c
int *arr = (int *)malloc(10 * sizeof(int));  // Allocates memory for an array of 10 integers
```
### 2. calloc()
Allocates memory for an array of elements and initializes each element to zero.

```c
void *calloc(size_t num, size_t size);
```
- `num` : The number of elements.
- `size` : The size of each element.
Returns a pointer to the allocated memory, or NULL if the allocation fails.

Example:

```c
int *arr = (int *)calloc(10, sizeof(int));  // Allocates memory for 10 integers and initializes them to 0
```
### 3. realloc()
Changes the size of a previously allocated memory block.

```c
void *realloc(void *ptr, size_t size);
```
- `ptr` : A pointer to the previously allocated memory block.
- `size` : The new size in bytes.
Returns a pointer to the reallocated memory block, or NULL if the reallocation fails.
Example:

```c
arr = (int *)realloc(arr, 20 * sizeof(int));  // Resizes the memory block to hold 20 integers
```
### 4. free()
Frees previously allocated memory.

```c
void free(void *ptr);
```
- `ptr` : A pointer to the memory block to be freed.
Example:

```c
free(arr);  // Frees the memory previously allocated for arr
```

## Key Points
- **Memory Leak**: Always free memory using `free()` after you are done using it to avoid memory leaks.
- **NULL Pointer Check**: Always check if memory allocation functions like `malloc()`, `calloc()`, or `realloc()` return `NULL`, indicating failure.
- **Size Calculation**: Use `sizeof()` to calculate the size of the data type when allocating memory.

## Example of Dynamic Memory Usage in C:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, n, i;

    // Allocate memory dynamically for 5 integers
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the array
    for (i = 0; i < n; i++) {
        arr[i] = i * 10;
    }

    // Print the array
    printf("Array contents:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
```
### Conclusion
Dynamic memory allocation in C allows for more flexible and efficient use of memory, but it requires careful management. Always ensure to `free()` memory when it is no longer needed to avoid memory leaks.
