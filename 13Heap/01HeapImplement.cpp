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
 
 return 0;
}