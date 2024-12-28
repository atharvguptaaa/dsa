#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this-> data=d;
        this-> left=NULL;
        this-> right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter element to the left"<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter element to the right"<<endl;
    root->right=buildTree(root->right);

    return root;
}

void buildFromLevelOrder(node* &root){
queue<node*> q;
cout<<"enter data for root"<<endl;
int data;
cin>>data;
root=new node(data);
q.push(root);

while(!q.empty()){
    node* cur=q.front();
    q.pop();
    cout<<"enter left of "<<cur->data<<endl;
    int leftData;
    cin>>leftData;
    if(leftData!=-1){
        cur->left=new node(leftData);
        q.push(cur->left);
    }

    cout<<"enter right of "<<cur->data<<endl;
    int rightData;
    cin>>rightData;
    if(rightData!=-1){
        cur->right=new node(rightData);
        q.push(cur->right);
    }
}
}


void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        q.pop(); 

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
 node* root=NULL;
//  root=buildTree(root);
buildFromLevelOrder(root);

 cout<<"Level-Order Traversal is -"<<endl;
 levelOrderTraversal(root);
 cout<<endl;

 cout<<"preorder Traversal is -"<<endl;
 preorder(root);
 cout<<endl;
 
 cout<<"Inorder Traversal is -"<<endl;
 inorder(root);
 cout<<endl;
 
 cout<<"postorder Traversal is -"<<endl;
 postorder(root);
 return 0;
}
