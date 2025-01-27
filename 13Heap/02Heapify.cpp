#include <bits/stdc++.h>
using namespace std;

// Convert an array into a min-heap using heapify.
void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    //check for smallest in left child
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    //check for smallest in right child
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    //if smallest found, swap it with root 
    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest); //recursive call on the swapped child node
    }
}

vector<int> buildMinHeap(vector<int>& arr) {
    int n = arr.size();
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}

int main() {
    vector<int> arr = {54, 53, 55, 52, 50};
    vector<int> minHeap = buildMinHeap(arr);
    for (int i : minHeap) {
        cout << i << " ";
    }
    return 0;
}

//heapify tc: O(logn)
//buildHeap tc: O(n)