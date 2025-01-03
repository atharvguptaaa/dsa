#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;
    
    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int v){
        size++;
        int index=size;
        arr[index]=v;

        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void del(){
        if(size==0){
            return;
        }

        arr[1]=arr[size];
        size--;

        int i=1;
        while(i<=size){
            int left=2*i;
            int right=2*i+1;
            if(left<=size && arr[i]<arr[left]){
                swap(arr[i],arr[left]);
                i=left;
            }
            else if(right<=size && arr[i]<arr[right]){
                swap(arr[i],arr[right]);
                i=right;
            }
            else{
                return;
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
        if(left<n && arr[left]>largest){
            largest=left;
        }
        if(right<n && arr[right]>largest){
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