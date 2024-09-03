#include <bits/stdc++.h>
using namespace std;

class Node
{
public: // Public access specifier, members declared here can be accessed from outside the class.
    int data;
    Node *next; // Node* is  used to create pointers that can point to Node objects.

public:
    Node(int data1, Node *next1)
    { // Constructor to initialize an object of type(class) Node
        data = data1;
        next = next1;
    }

public:
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

int main()
{
    vector<int> arr = {2, 5, 19, 8, 3};
    // Node* y= new Node(arr[0]);
    // cout<<y->data;
    Node *head = convertArrToLL(arr);

    Node *theNode = findNode(head, 8);
    deleteNode(theNode);

    head=removeHead(head);
    head=removeTail(head);
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}