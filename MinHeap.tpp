template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    while (i > 0 && data[i] < data[parent(i)]){     // while current is smaller than parent
        swap(data[i], data[parent(i)]);            // swap with parent
        i = parent(i);                             // move up
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int small = i;       // assume current is smallest
    int l = left(i);
    int r = right(i);

    if (l < size() && data[l] < data[small]) small = l; // left child smaller?
    if (r < size() && data[r] < data[small]) small = r; // right child smaller?

    if (small != i){                // if a child was smaller
        swap(data[i], data[small]);  // swap down
        siftDown(small);             // keep going
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);        // add to end of array
    siftUp(data.size() - 1);      // fix heap by bubbling up
}

template <typename T>
T MinHeap<T>::removeRoot() {
    // TODO: Implement removing the root element.
    T rootValue = data[0];        // save min value

    swap(data[0], data.back());   // put last element at root
    data.pop_back();              // remove last

    siftDown(0);                  // fix heap from root down

    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
    siftUp(index);   // might need to go up

    siftDown(index); // or might need to go down
}
