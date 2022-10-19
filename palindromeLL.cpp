#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		
		Node(int data)
		{
			this->data=data;
			next=NULL;
		}
};

void print(Node* head)
{
	if(head==NULL)
	{
		return;
	}
	cout<<head->data<<" ";
	print(head->next);
}

Node* reverseLL(Node* head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	Node* smallHead=reverseLL(head->next);
	Node* temp=head->next;
	temp->next=head;
	head->next=NULL;
	return smallHead;
}

Node* midPoint(Node* head)
{
	Node* slow=head;
	Node* fast=head->next;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
bool isPalindromeLL(Node* head)
{
	if(head==NULL)
	{
		return true;
	}
	Node* temp1=head;
	Node* mid=midPoint(head);
	Node* temp2=mid->next;
	mid->next=NULL;
	temp2=reverseLL(temp2);
	cout<<"Mid Node "<<mid->data<<endl;
	print(temp2);
	cout<<endl;
	while(temp1 !=NULL && temp2!=NULL)
	{
		if(temp1->data != temp2->data)
		{
			return false;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return true; // If all fine;
}

Node* takeInput()
{
	Node* head=NULL;
	Node* tail=NULL;
	int data;
	cin>>data;
	while(data!=-1)
	{
		Node* newNode=new Node(data);
		if(head==NULL)
		{
			head=newNode;
			tail=newNode;
		}
		else
		{
			tail->next=newNode;
			tail=newNode;
		}
		cin>>data;
	}
	return head;
}

int main()
{
	Node* head=takeInput();
	if(isPalindromeLL(head))
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
}
