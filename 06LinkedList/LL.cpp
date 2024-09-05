#include <bits/stdc++.h>
using namespace std;

class Node
{
public: // Public access specifier, members declared here can be accessed from outside the class.
    int data;
    Node *next; // Node* is  used to create pointers that can point to Node objects.

    Node(int data1, Node *next1)
    { // Constructor to initialize an object of type(class) Node
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]); // first node object(never tamper head)
    Node *mover = head;            // iterates all the node objects assigning pointer values
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]); // subsequent node objects
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *findNode(Node *head, int val)
{
    Node *theNode;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
        {
            return temp;
        }
        temp = temp->next;
    }
    return 0;
}

Node *removeHead(Node *head)
{
    if (head == NULL)
        return head;
    // Node *temp = head;
    // head = temp->next;
    // delete temp;
    head=head->next;
    return head;
}

Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    
    return head;
}

void deleteNode(Node *node)
{
    *node = *node->next;
}

Node* deleteKthElement(Node *head, int k){
    if(head==NULL) return head;
    Node* temp=head;
    Node* prev=NULL;
    int count=1;
    while(temp){
        if(k==1){
            head=head->next;
            free(temp);
            return head;
        }
        if(count==k){
            prev->next=prev->next->next;
            free(temp);
            return head;
        }
    
    count++;
    prev=temp;
    temp=temp->next;
    }
    return head;
}

Node* deleteElement(Node *head, int element){
    if(head==NULL) return head;
    Node* temp=head;
    Node* prev=NULL;
    while(temp){
        if(head->data==element){
            head=head->next;
            free(temp);
            return head;
        }
        if(temp->data==element){
            prev->next=prev->next->next;
            free(temp);
            return head;
        }
    
    prev=temp;
    temp=temp->next;
    }
    return head;
}

//insertion funcs
Node *insertHead(Node *head, int val){
    Node *temp=new Node(val,head);
    return temp;
}

Node *insertTail(Node *head, int val){
    Node* temp=head;
    if(temp==NULL) return new Node(val,nullptr);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new Node(val,nullptr);
    return head;
}

Node* insertElementAtK(Node *head, int k, int val){
    if(head==NULL) return new Node(val,nullptr);

    if(k==1){
            return new Node(val,head);
        }

    Node* temp=head;
    int count=1;

    while(temp){
        if(count==k-1){
            temp->next=new Node(val,temp->next);
            return head;
        }
    
    count++;
    temp=temp->next;
    }

    if(count<k) return head; //incase k is out of bounds

    return head;
}

int main()
{
    vector<int> arr = {2, 5, 19, 8, 3, 6, 70, 32};
    // Node* y= new Node(arr[0]);
    // cout<<y->data;
    Node *head = convertArrToLL(arr);

    head=deleteKthElement(head,3);//deletes 19 on third place
    head=deleteElement(head,6);//deletes 6

    Node *theNode = findNode(head, 8); //finds node of 8
    deleteNode(theNode); //deletes 8

    head=removeHead(head); //deletes 2
    head=removeTail(head); //deletes 32

    cout<<"after deletion:"<<endl;
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    //insertion
    head=insertElementAtK(head,3,50);
    head=insertHead(head,100);
    head=insertTail(head,200);

    cout<<endl<<"after insertion:"<<endl;
    Node *temp2 = head;
    while (temp2)
    {  
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
}