//Given a singly linked list, swap the list items in pairs (reconnect the pointers, not simply swap the values). For example: 
//Before: A->B->C->D 
//After: B->A->D->C
#include<iostream>
using namespace std;

struct Node
{
	char data;
	Node *next;
};

Node* createLinkedList()
{
	Node* head=NULL;
	for(char c='A';c<='J';c++)
	{
		Node* node=new Node();
		node->data=c;
		node->next=NULL;
		if(head==NULL)
		{
			head=node;
		}
		else
		{
			Node *temp=head;
			while(temp->next)
				temp=temp->next;
			temp->next=node;
		}
	}
	return head;
}

Node* printLinkedList(Node* head)
{
	Node* temp=head;
	while(temp)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL\n";
}

Node* swapPairs(Node* head)
{
	if(!head || !head->next)
	{
		return head;
	}
	
	Node* temp1=head;
	Node* temp2=temp1->next;
	head->next->next=swapPairs(head->next->next);
	if(temp1==head)
	{
		head=temp2;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
	temp1=temp1->next;
	
	return head;
}
int main()
{
	Node* head=createLinkedList();
	printLinkedList(head);
	head=swapPairs(head);
	printLinkedList(head);
	return 0;
}


