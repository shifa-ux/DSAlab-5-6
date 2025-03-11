#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* prev;
    Node* next;
};
void insertAtEnd(Node*& head,int data)
{
    Node* newNode=new Node;
	newNode->data=data;
	newNode->prev=nullptr;
	newNode->next=nullptr;
    if(!head)
	{
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next)
	temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void printList(Node* head)
{
    Node* temp=head;
    while(temp)
	{
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
void deleteAtBeginning(Node*& head)
{
    if(!head)
	return;
    Node* temp=head;
    head=head->next;
    if(head)
	head->prev=nullptr;
    delete temp;
}
void deleteAfterValue(Node*& head,int value)
{
    Node* temp=head;
    while(temp && temp->data!=value)
	{
        temp=temp->next;
    }
    if(temp && temp->next)
	{
        Node* delNode=temp->next;
        temp->next=delNode->next;
        if(delNode->next)
		delNode->next->prev=temp;
        delete delNode;
    }
}
int main()
{
    Node* head=nullptr;
    insertAtEnd(head,1);
    insertAtEnd(head,45);
    insertAtEnd(head,60);
    insertAtEnd(head,12);
    cout<<"Original List:"<<endl;
    printList(head);
    deleteAtBeginning(head);
    cout<<"After deleting first node:"<<endl;
    printList(head);
    deleteAfterValue(head,45);
    cout<<"After deleting node after 45:"<<endl;
    printList(head);
return 0;
}