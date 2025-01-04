# Code con priorità
Nelle code con priorità, ogni elemento ha una "priorità" associata, e gli elementi con alta priorità vengono serviti prima di quelli con bassa priorità.

Gli heap sono utilizzati per implementare efficientemente le code con priorità. 

### Funzionamento delle code con priorità usando gli heap

#### Inserimento
Quando un nuovo elemento viene inserito nella coda, lo si aggiunge alla fine dell'heap e si applica la procedura di `heapify` per mantenere la proprietà del max heap (o min heap).

```pseudo
Max-Heap-Insert(A, x):
    heap-size[A] = heap-size[A] + 1
    A[heap-size[A]] = -∞
    Heap-IncreaseKey(A, heap-size[A], x)
```

#### Estrazione dell'elemento con massima/minima priorità
Questo corrisponde all'estrazione della radice del heap. Dopo aver estratto la radice, l'ultimo elemento dell'heap viene spostato alla radice e si applica la procedura di heapify per ripristinare la proprietà dell'heap.

```pseudo
Heap-Maximum(A):
    return A[1]
```

```pseudo
Heap-ExtractMax(A):
    if heap-size[A] < 1
        error "heap underflow"
    max = A[1]
    A[1] = A[heap-size[A]]
    heap-size[A] = heap-size[A] - 1
    MaxHeapify(A, 1)
    return max
```

#### Modifica della priorità
Se la priorità di un elemento cambia, si può aumentare o diminuire la chiave dell'elemento e successivamente applicare la procedura di `heapify` per mantenere la proprietà dell'heap.

```pseudo
Heap-IncreaseKey(A, i, key):
    if key < A[i]
        error "new key is smaller than current key"
    A[i] = key
    while i > 1 and A[parent(i)] < A[i] do
        swap A[i] with A[parent(i)]
        i = parent(i)
```
