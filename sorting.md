- [Insertion Sort](#insertion-sort)
- [Merge Sort](#merge-sort)
- [Heap Sort](#heap-sort)
- [Quick Sort](#quick-sort)
- [Counting Sort](#counting-sort)
- [Radix Sort](#radix-sort)
- [Bucket Sort](#bucket-sort)

## Insertion Sort
### Funzionamento
L'algoritmo considera che il primo elemento di un array sia già ordinato. Quindi, inizia dal secondo elemento:
1. Il secondo elemento viene confrontato con gli elementi precedenti (da destra a sinistra) fino a trovare la sua posizione corretta e viene inserito in quella posizione.
2. Si passa al terzo elemento e si ripete lo stesso processo, confrontandolo con tutti gli elementi precedenti finché non trova la sua posizione corretta.

### Pseudo Codice
```pseudo
insertionSort(array)
    per i da 1 a lunghezza(array) - 1
        chiave = array[i]
        j = i - 1
        
        mentre j >= 0 e array[j] > chiave
            array[j + 1] = array[j]
            j = j - 1
        
        array[j + 1] = chiave
```

### Complessità
$O(n^2)$

### Codice C
```C
#include <stdio.h>

void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int chiave = array[i];
        int j = i - 1;

        // Sposta gli elementi dell'array[0..i-1] che sono
        // maggiori della chiave di una posizione avanti rispetto alla loro posizione attuale
        while (j >= 0 && array[j] > chiave) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chiave;
    }
}
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
### [Funzionamento](https://youtu.be/Hoixgm4-P4M)
1. **Scelta del pivot**: Scegli un elemento dall'array come pivot. Esistono vari metodi per scegliere il pivot, come scegliere l'elemento centrale, l'elemento iniziale, l'elemento finale o un elemento casuale.
2. **Partizionamento**: Riordina l'array in modo che tutti gli elementi minori del pivot vengano prima di esso e tutti gli elementi maggiori vengano dopo di esso. Il pivot viene quindi posizionato nella sua posizione finale (quella a sinistra dei maggiori o a destra dei minori). Questa operazione è detta partizionamento.
3. **Ricorsione**: Applica ricorsivamente il quicksort ai sotto-array di elementi a sinistra e a destra del pivot.

### Pseudo Codice
```pseudo
quickSort(array, low, high):
    if low < high:
        // Trova la posizione del pivot
        pivot_index = partition(array, low, high)
        
        // Ordina ricorsivamente i sotto-array
        quickSort(array, low, pivot_index - 1)
        quickSort(array, pivot_index + 1, high)

partition(array, low, high):
    // Scegli il pivot (qui scegliamo il primo elemento)
    pivot = array[low]
    
    // Inizializza gli indici
    left = low + 1
    right = high
    
    // Partizionamento
    while true:
        // Trova un elemento maggiore o uguale al pivot da sinistra
        while left <= right and array[left] < pivot:
            left = left + 1
        
        // Trova un elemento minore o uguale al pivot da destra
        while left <= right and array[right] > pivot:
            right = right - 1
        
        // Se gli indici si incrociano, il partizionamento è completo
        if left > right:
            break
        else:
            // Scambia gli elementi trovati
            swap(array, left, right)
            left = left + 1
            right = right - 1
    
    // Metti il pivot nella sua posizione finale
    swap(array, low, right)
    return right

swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

```

### Complessità
Nel caso migliore è $\Theta(n\log n )$, nel peggiore $O(n^2)$

### Codice C
```C
// Funzione per scambiare due elementi
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funzione per partizionare l'array
int partition(int array[], int low, int high) {
    int pivot = array[low];
    int left = low + 1;
    int right = high;

    while (1) {
        // Trova un elemento maggiore o uguale al pivot da sinistra
        while (left <= right && array[left] < pivot) {
            left++;
        }

        // Trova un elemento minore o uguale al pivot da destra
        while (left <= right && array[right] > pivot) {
            right--;
        }

        // Se gli indici si incrociano, il partizionamento è completo
        if (left > right) {
            break;
        }

        // Scambia gli elementi trovati
        swap(&array[left], &array[right]);
        left++;
        right--;
    }

    // Metti il pivot nella sua posizione finale
    swap(&array[low], &array[right]);
    return right;
}

// Funzione principale di Quicksort
void quicksort(int array[], int low, int high) {
    if (low < high) {
        // Trova la posizione del pivot
        int pivot_index = partition(array, low, high);

        // Ordina ricorsivamente i sotto-array
        quicksort(array, low, pivot_index - 1);
        quicksort(array, pivot_index + 1, high);
    }
}
```

## Merge sort
### Funzionamento
Il merge sort è un algoritmo di ordinamento efficiente e stabile basato sul paradigma divide et impera.
1. Suddivide l'array iniziale in due metà uguali (o quasi uguali) ricorsivamente fino a ottenere sotto-array di dimensione 1.
2. Poiché gli array di dimensione 1 sono già ordinati, procede alla fase successiva.
3. Unisce i sotto-array ordinati per formare un array ordinato finale.
### Pseudo Codice
```pseudo
mergeSort(array, inizio, fine)
    se inizio < fine
        metà = (inizio + fine) / 2
        mergeSort(array, inizio, metà)
        mergeSort(array, metà + 1, fine)
        merge(array, inizio, metà, fine)

merge(array, inizio, metà, fine)
    n1 = metà - inizio + 1
    n2 = fine - metà
    sinistra = array temporaneo di dimensione n1
    destra = array temporaneo di dimensione n2
    
    per i da 0 a n1 - 1
        sinistra[i] = array[inizio + i]
    
    per j da 0 a n2 - 1
        destra[j] = array[metà + 1 + j]
    
    i = 0
    j = 0
    k = inizio
    
    mentre i < n1 e j < n2
        se sinistra[i] <= destra[j]
            array[k] = sinistra[i]
            i = i + 1
        altrimenti
            array[k] = destra[j]
            j = j + 1
        k = k + 1
    
    mentre i < n1
        array[k] = sinistra[i]
        i = i + 1
        k = k + 1
    
    mentre j < n2
        array[k] = destra[j]
        j = j + 1
        k = k + 1
```

### Complessità
$O(n\log(n))$

### Codice C
```C
#include <stdio.h>

// Funzione per unire due sottoarray
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Array temporanei
    int L[n1], R[n2];

    // Copia i dati negli array temporanei
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Unisci gli array temporanei
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia gli elementi restanti di L[], se ce ne sono
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia gli elementi restanti di R[], se ce ne sono
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Funzione principale del Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordina prima e seconda metà
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Unisci le metà ordinate
        merge(arr, l, m, r);
    }
}
```

## [Counting sort](https://youtu.be/EItdcGhSLf4)
### Funzionamento
Il Counting Sort è un algoritmo di ordinamento molto efficace per ordinare numeri interi entro un determinato intervallo. Funziona in questo modo:
1. **Determinare** il valore massimo nell'array da ordinare per conoscere l'intervallo dei valori.
2. **Creare un array di conteggio** (chiamato `countArray`) dove ogni indice rappresenta un valore nell'intervallo e ogni elemento memorizza il numero di occorrenze di quel valore nell'array originale.
3. **Popolare l'array di conteggio** scorrendo l'array originale e incrementando il valore nell'array di conteggio corrispondente a ciascun valore.
4. **Aggiornare l'array** di conteggio in modo che ogni elemento contenga la somma degli elementi precedenti, il che consente di determinare la posizione finale di ogni elemento.
5. **Costruire l'array ordinato** scorrendo l'array originale all'indietro e inserendo ogni elemento nella sua posizione finale determinata dall'array di conteggio.

### Pseudo Codice
```pseudo
CountingSort(array, n):
    // Passo 1: Determina il valore massimo nell'array
    max_val = trovaMax(array, n)

    // Passo 2: Crea l'array di conteggio (countArray)
    countArray = array di dimensione (max_val + 1) inizializzato a 0

    // Passo 3: Popola l'array di conteggio
    per i da 0 a n-1:
        countArray[array[i]]++

    // Passo 4: Aggiorna l'array di conteggio
    per i da 1 a max_val:
        countArray[i] += countArray[i - 1]

    // Passo 5: Costruisce l'array ordinato
    sortedArray = array di dimensione n
    per i da n-1 a 0:
        sortedArray[countArray[array[i]] - 1] = array[i]
        countArray[array[i]]--

    // Copia l'array ordinato nell'array originale
    per i da 0 a n-1:
        array[i] = sortedArray[i]

trovaMax(array, n):
    max = array[0]
    per i da 1 a n-1:
        se array[i] > max:
            max = array[i]
    ritorna max
```

### Complessità
1. **Determinazione del valore massimo**: questo richiede scorrere l'array una volta, quindi ha una complessità di $O(n)$.
2. **Creazione dell'array di conteggio**: la creazione dell'array di conteggio ha una complessità di $O(k)$, dove $k$ è il valore massimo nell'array.
3. **Popolazione dell'array di conteggio**: scorrere l'array originale ha una complessità di $O(n)$.
4. **Aggiornamento dell'array di conteggio**: questo passo richiede $O(k)$ operazioni.
5. **Costruzione dell'array ordinato**: questo passo richiede di scorrere l'array originale e costruire il nuovo array ordinato, con una complessità di $O(n)$.

In sintesi, la complessità temporale totale è $O(n+k)$, dove:
- $n$ dove è il numero di elementi nell'array
- $k$ è il valore massimo nell'array

### Codice C
```C
#include <stdio.h>
#include <stdlib.h>

// Funzione per trovare il valore massimo nell'array
int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Funzione per eseguire il Counting Sort
void counting_sort(int arr[], int n) {
    int max_val = find_max(arr, n);
    int* count_array = (int*)calloc(max_val + 1, sizeof(int));

    // Popolare l'array di conteggio
    for (int i = 0; i < n; i++) {
        count_array[arr[i]]++;
    }

    // Aggiornare l'array di conteggio
    for (int i = 1; i <= max_val; i++) {
        count_array[i] += count_array[i - 1];
    }

    // Costruire l'array ordinato
    int* sorted_array = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        sorted_array[count_array[arr[i]] - 1] = arr[i];
        count_array[arr[i]]--;
    }

    // Copiare l'array ordinato nell'array originale
    for (int i = 0; i < n; i++) {
        arr[i] = sorted_array[i];
    }

    // Liberare la memoria allocata
    free(count_array);
    free(sorted_array);
}
```
