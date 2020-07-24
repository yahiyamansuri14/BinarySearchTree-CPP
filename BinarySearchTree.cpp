#include <iostream>
using namespace std;
 struct Node{
    Node *left;
    int data;
    Node *right;
 }*root=NULL;

  void insert(int key){
    Node *temp;
    temp=root;
    Node *r=NULL,*newnode;
    if(root==NULL){
        newnode=new Node;
        newnode->data=key;
        newnode->left=newnode->right=NULL;
        root=newnode;
        return;
    }
    while(temp!=NULL){
        r=temp;
        if(key<temp->data)
            temp=temp->left;
        else if(key>temp->data)
                temp=temp->right;
        else
                return;
    }
    newnode=new Node;
    newnode->data=key;
    newnode->left=newnode->right=NULL;
    if(key<r->data)
        r->left=newnode;
    else
        r->right=newnode;
}
  void inorderTravarsal(struct Node *temp){
    if(temp!=NULL){
        inorderTravarsal(temp->left);
        //cout<<temp->data<<"\t";
        cout<<"Address is:-\t"<<(int)temp<<"\tvalue is :-"<<temp->data<<endl;
        inorderTravarsal(temp->right);
    }
  }
  Node * searchBST(int key){
        Node *temp=root;
        while(temp!=NULL){
            if(key==temp->data)
                return temp;
            else if(key<temp->data)
                    temp=temp->left;
                else
                    temp=temp->right;
        }
        return NULL;

  };

int main()
{
    insert(10);
    insert(5);
    insert(20);
    insert(32);
    insert(1);
    insert(12);
    insert(14);
    inorderTravarsal(root);
    Node *result=searchBST(5);
    if(result!=NULL)
        cout<<"\nKey found at\t"<<(int)result;
    else
        cout<<"\nKey is not found\n";
    return 0;
}
