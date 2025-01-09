- [Insertion Sort](#insertion-sort)
- [Merge Sort](#merge-sort)
- [Heap Sort](#heap-sort)
- [Quick Sort](#quick-sort)
- [Counting Sort](#counting-sort)
- [Radix Sort](#radix-sort)
- [Bucket Sort](#bucket-sort)

## Insertion Sort
### Funzionamento
### Pseudo Codice
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

### Complessità


### Codice C
```C

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
```

## Heap sort
### Funzionamento
Un array $A[1..n]$ può essere interpretato come albero binario (**heap**), dove:
- $A[1]$ è la radice
- $A[2i]$ e $A[2i+1]$ sono i figli di $A[i]$
-  $A[floor(i / 2)]$ è il padre di $A[i]$

La procedura di trasformazione di un array in uno heap viene definita `heapify`.

#### Proprietà dello *heap*
- **Max-Heap**: per ogni nodo i diverso dalla radice: $A[parent(i)] ≥ A[i]$. *ordinamento crescente*
- **Min-Heap**: per ogni nodo i diverso dalla radice: $A[parent(i)] ≤ A[i]$. *ordinamento decrescente*

Modifiche all’interno dell’array possono provocare la violazione della proprietà: `max-heapify` (e `min-heapify`) viene usata per ripristinare la proprietà.

#### Procedura di ordinamento
L'Heap Sort utilizza due fasi principali

##### Costruzione del Max Heap
Inizialmente, l'intero array viene trasformato in un Max Heap. Questa fase richiede la chiamata ripetuta della funzione max-heapify a partire dagli ultimi nodi interni fino alla radice.

##### Ordinamento del Max Heap
Una volta costruito il Max Heap, si procede a ordinare l'array. Si scambia l'elemento alla radice (il più grande) con l'ultimo elemento dell'heap. Questo riduce la dimensione dell'heap di uno.

Si applica `max-heapify` alla nuova radice per ripristinare la proprietà del Max Heap.

Questo processo si ripete fino a quando tutti gli elementi sono stati estratti e l'array è ordinato.

### Pseudo Codice
```pseudo
HeapSort(A, n):
    // Step 1: Costruire un max heap
    BuildMaxHeap(A, n)

    // Step 2: Estrarre un elemento per volta dall'heap
    for i = n - 1 down to 1 do:
        swap A[0] with A[i]   // Sposta l'elemento massimo corrente alla fine
        MaxHeapify(A, i, 0)   // Chiama MaxHeapify sull'heap ridotto

BuildMaxHeap(A, n):
    // Costruire un max heap
    for i = n/2 - 1 down to 0 do:
        MaxHeapify(A, n, i)

MaxHeapify(A, n, i):
    largest = i              // Inizializza largest come radice
    left = 2 * i + 1         // Sinistro = 2*i + 1
    right = 2 * i + 2        // Destro = 2*i + 2

    // Se il figlio sinistro è più grande della radice
    if left < n and A[left] > A[largest]:
        largest = left

    // Se il figlio destro è più grande della radice
    if right < n and A[right] > A[largest]:
        largest = right

    // Se largest non è la radice
    if largest != i:
        swap A[i] with A[largest]
        MaxHeapify(A, n, largest) // Ricorsivamente heapify il sottoalbero interessato
```
### Complessità
Ogni chiamata di `max-heapify` (o `min-heapify`) costa $O(\log(n))$, ci sono $O(n)$ chiamate, di conseguenza $O(n\log(n))$.

### Codice C
```C
// Funzione per mantenere la proprietà del max heap
void MaxHeapify(int arr[], int n, int i) {
    int largest = i; // Inizializza largest come radice
    int left = 2 * i + 1; // Sinistro = 2*i + 1
    int right = 2 * i + 2; // Destro = 2*i + 2

    // Se il figlio sinistro è più grande della radice
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se il figlio destro è più grande della radice
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se largest non è la radice
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Ricorsivamente heapify il sottoalbero
        MaxHeapify(arr, n, largest);
    }
}

// Funzione per costruire un max heap
void BuildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, n, i);
}

// Funzione di ordinamento Heapsort
void HeapSort(int arr[], int n) {
    // Step 1: Costruire un max heap
    BuildMaxHeap(arr, n);

    // Step 2: Estrarre un elemento per volta dall'heap
    for (int i = n - 1; i > 0; i--) {
        // Scambia la radice con l'ultimo elemento
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chiama MaxHeapify sull'heap ridotto
        MaxHeapify(arr, i, 0);
    }
}
```

## Radix sort
### Funzionamento
Assumiamo che i valori degli elementi dell’array siano interi rappresentabili con al più $d$ cifre in una certa base $b$.

Per ordinare l’array si usa d volte un algoritmo di ordinamento stabile (es., CountingSort) per ordinare l’array rispetto a ciascuna delle d cifre partendo dalla meno significativa.

### Pseudo Codice
```pseudo
RadixSort(A, d)
    for i = 1 to d do
        // Usa un algoritmo di ordinamento stabile per ordinare l'array A sugli i-esimi cifre
        CountingSort(A, i)
```

### Complessità
La complessità temporale dell'algoritmo di Radix Sort dipende dalla base di numerazione utilizzata e dall'algoritmo di ordinamento stabile impiegato (ad esempio, Counting Sort) per ogni cifra.

La complessità temporale di Radix Sort è $O(d(n+k))$, dove:
- $n$ è il numero di elementi nell'array
- $d$ è il numero di cifre (o posizioni) massime negli elementi
- $k$ è il valore massimo che una cifra può assumere (ad esempio, 10 per le cifre decimali)

### Codice C
```C
void radixSort(int arr[], int n) {
    int max = getMax(arr, n); // Trova il valore massimo nell'array

    // Esegui Counting Sort per ciascuna cifra del valore massimo
    for (int digitPlace = 1; max / digitPlace > 0; digitPlace *= 10)
        countingSort(arr, n, digitPlace);
}
```

## Quick sort
### Funzionamento


### Pseudo Codice
```pseudo

```

### Complessità


### Codice C
```C

```


## Merge sort
### Funzionamento


### Pseudo Codice
```pseudo

```

### Complessità


### Codice C
```C

```

## Counting sort
### Funzionamento

### Pseudo Codice
```pseudo

```

### Complessità


### Codice C
```C

```
