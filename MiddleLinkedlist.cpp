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
			this->next=NULL;
		}
};
Node* takeInputBetter()
{
	int data;
	cin>>data;
	Node* head=NULL;
	Node* tail=NULL;
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
			tail=newNode; // Or tail=tail->next -- Same thing;
		}
		cin>>data;
	}
	return head;
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
int main()
{
	Node* head=takeInputBetter();
	Node* mid=midPoint(head);
	if(mid!=NULL)
	{
		cout<<mid->data<<endl;
	}
}
