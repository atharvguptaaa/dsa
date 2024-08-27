#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertArrToLL(vector<int> &arr){
    Node* head= new Node(arr[0]);  //first node object(never tamper head)
    Node* mover=head; //moves through all the node objects assigning pointer values 
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp=new Node(arr[i]); //subsequent node objects
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int main(){
    vector<int> arr={2,5,19,8,3};
    // Node* y= new Node(arr[0]);
    // cout<<y->data;
    Node* head=convertArrToLL(arr);
    // cout<<head->next;

    Node* temp= head;
    while(temp){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}