#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;
    
    //constructor
    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int v){
        size++;
        int index=size;
        arr[index]=v;

 // Heapify-up: Restore the max-heap property
        while(index>1){
            int parent=index/2; //find parent's index
            if(arr[parent]<arr[index]){  // If parent is smaller than the current node
                swap(arr[parent],arr[index]);  // Swap the parent and current node
                index=parent; // to ensure the max-heap property is maintained at all levels
            }
            else{
                return;
            }
        }
    }

// Deletes the root (maximum element) of the heap
    void del(){
        if(size==0){
            return;
        }

        arr[1]=arr[size]; //swap last elmt with root
        size--;

        int i=1; //start with root node

     // Heapify-down: Restore the max-heap property
        while(i<=size){
            int left=2*i;
            int right=2*i+1;

            // Check if the left child exists and is greater than the current node
            if(left<=size && arr[i]<arr[left]){
                swap(arr[i],arr[left]);
                i=left;
            }

            // Check if the right child exists and is greater than the current node
            else if(right<=size && arr[i]<arr[right]){
                swap(arr[i],arr[right]);
                i=right;
            }
            else{
                return; // If neither child is larger, the heap property is satisfied
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(int arr[], int n, int i){
    int largest=i;
    int left=2*largest;
    int right=2*largest+1;
        if(left<=n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<=n && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    
}

int main()
{
 heap h;
 h.insert(5);
 h.insert(1);
 h.insert(7);
 h.insert(2);
 h.insert(6);
 h.print();
 h.del();
 h.print();
 h.del();
 h.print();
 
 int arr[100]={-1,54,53,55,52,50};
 int n=5;
 for(int i=n/2;i>0;i--){
 heapify(arr,n,i);
 }

 for (int i = 1; i <= n; i++)
 {
 cout<<arr[i]<<" ";
 }
 
 return 0;
}