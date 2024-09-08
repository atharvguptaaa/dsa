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

Node *reverseDLL(Node* head){
Node* temp=head;
Node* prev=NULL;
while(temp){
    prev=temp->back;        //swapping next and back
    temp->back=temp->next;
    temp->next=prev;

    temp=temp->back;
}
//at last prev stores second last element(temp->back): to get last one, move fwd(which is now back)
return prev->back;
}


int main()
{
     Node* head=new Node(3);
     head->next=new Node(5,nullptr,head);
     head->next->next=new Node(7,nullptr,head->next);
     head->next->next->next=new Node(9,nullptr,head->next->next);

     head=reverseDLL(head);

     Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
 return 0;
}