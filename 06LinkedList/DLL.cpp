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
};

Node *convertArrToDLL(vector<int>& arr){
    Node *head=new Node(arr[0],nullptr,nullptr);
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
     Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
 return 0;
}