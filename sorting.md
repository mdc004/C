- [Insertion Sort](#insertion-sort)
- [Merge Sort](#)
- [Heap Sort](#)
- [Quick Sort](#)
- [Counting Sort](#)
- [Radix Sort](#)
- [Bucket Sort](#bucket-sort)

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
## Bucket Sort
### Funzionamento
Per ordinare un array $A[1..n]$, si divide l’intervallo in $k$ parti uguali e usa un array $B[0...k-1]$ di liste (i bucket), mettendo in $B[j]$ gli $A[i]$ che cadono nella j-esima parte dell’intervallo. 

Successivamente, riordina ciascuna lista e infine ricopia in $A$ tutti gli elementi delle liste.

Dove $k$ rappresenta il numero di secchi utilizzati per distribuire gli elementi. Idealmente si sceglie un numero di secchi proporzionale al numero di elementi nell'array per ottenere una distribuzione uniforme.

### Pseudo Codice
```pseudo
BucketSort(A, n):
    // Step 1: Create empty buckets
    create k empty buckets B[0], B[1], ..., B[k-1]
    
    // Step 2: Put array elements in different buckets
    for i = 0 to n-1 do:
        index = floor(k * A[i]) // Assuming A[i] is in range [0, 1)
        B[index].append(A[i])
        
    // Step 3: Sort individual buckets
    for i = 0 to k-1 do:
        sort(B[i]) // You can use any sorting algorithm here, like Insertion Sort
    
    // Step 4: Concatenate all buckets into A
    m = 0
    for i = 0 to k-1 do:
        for j in 0 to len(B[i])-1 do:
            A[m] = B[i][j]
            m = m + 1
```

### Complessità
Per quanto riguarda la complessità si ha dove $Θ(n + k)$ dove k indica il numero di secchi, ma che può essere ignorato, di conseguenza $Θ(n)$ e $O(n^2)$ in quanto può accadere che tutti gli elementi finiscano nella stessa lista e sarà quindi necessario usare un altro algoritmo di ordinamento.

### Codice C
```C
#include <stdio.h>
#include <stdlib.h>

// Definizione di una struttura per i nodi della lista
struct Node {
    float data;
    struct Node* next;
};

// Funzione per inserire un nuovo nodo nella lista
void insert(struct Node** list, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *list;
    *list = newNode;
}

// Funzione per ordinare una lista utilizzando l'Insertion Sort, per mantenere il contesto generale non si riporterà il codice dell'algoritmo
void insertionSort(struct Node* list) {
    return;
}

// Funzione Bucket Sort
void bucketSort(float arr[], int n) {
    // Creare k secchi vuoti
    int k = 10; // Ad esempio, utilizziamo 10 secchi
    struct Node** buckets = (struct Node**)malloc(sizeof(struct Node*) * k);
    for (int i = 0; i < k; i++) {
        buckets[i] = NULL;
    }

    // Mettere gli elementi dell'array nei secchi appropriati
    for (int i = 0; i < n; i++) {
        int index = k * arr[i]; // Assuming arr[i] is in range [0, 1)
        insert(&buckets[index], arr[i]);
    }

    // Ordinare i singoli secchi
    for (int i = 0; i < k; i++) {
        insertionSort(buckets[i]);
    }

    // Concatenare tutti i secchi nell'array originale
    int index = 0;
    for (int i = 0; i < k; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    // Liberare la memoria dei secchi
    free(buckets);
}

int main() {
    // Esempio di utilizzo
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Array ordinato:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}
```
