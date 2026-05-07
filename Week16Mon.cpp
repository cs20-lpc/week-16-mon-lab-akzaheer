#include <iostream>
#include "MinHeap.hpp"
using namespace std;

// Use a MinHeap to sort ascending
template <typename T>
void heapsort(vector<T>& arr){
    MinHeap<T> h;

    for (int i = 0; i < arr.size(); i++)
        h.insert(arr[i]);          // build heap from array

    for (int i = 0; i < arr.size(); i++)
        arr[i] = h.removeRoot();   // pull min out each time, fills array sorted
}

int main() {
    vector<int> arr = {5, 1, 9, 3, 7, 4};

    heapsort(arr);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
