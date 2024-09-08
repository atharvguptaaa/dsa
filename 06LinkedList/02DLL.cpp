#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *back;

    Node(int data1,Node *next1, Node *back1){
        data=data1;
        next=next1;
        back=back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back=nullptr;
    }
};

Node* deleteHead(Node *head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* prev=head;
    head=head->next;

    prev->next=nullptr;
    head->back=nullptr;

    delete prev;
    return head;

}

Node* deleteTail(Node *head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* tail=head;
    
    while(tail->next){
        tail=tail->next;
    }
    Node* newTail=tail->back;
    newTail->next=nullptr;
    tail->back=nullptr;
    delete tail;
    return head;
}

Node* deleteKthElement(Node* head, int k){
    if(head==NULL) return head;
    int count=1;
    Node *temp=head;
    while(temp){
        if(count==k) break;
        count++;
        temp=temp->next;
    }
    if(temp->back==nullptr&&temp->next==nullptr) {
        delete temp;
        return NULL;
        }
    else if(temp->back==nullptr){
       return deleteHead(head);
    }
    else if(temp->next==nullptr){
       return deleteTail(head);
    }
    //else
        Node* prev=temp->back;
        Node* front=temp->next;
        
        prev->next=front;
        front->back=prev;

        temp->next=nullptr;
        temp->back=nullptr;

        delete temp;
        return head;
   
}

Node* insertHead(Node* head, int val){
    Node* newHead= new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}

Node* insertBeforeKth(Node* head, int k, int val){
    if(k==1) return insertHead(head,val);
    Node* temp=head;
    int count=1;
    while(temp){
        if(count==k) break;
        temp=temp->next;
        count++;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;

}



Node *convertArrToDLL(vector<int>& arr){
    Node *head=new Node(arr[0]);
    Node *prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

int main()
{
  vector<int> arr = {2, 5, 19, 8, 3, 6, 70, 32};
 
    Node *head = convertArrToDLL(arr);
    head=insertBeforeKth(head,6,36);
    head=deleteKthElement(head,4); //deletes 8
    head=deleteHead(head);
    head=deleteTail(head);
    head=insertHead(head,100);

     Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
 return 0;
}