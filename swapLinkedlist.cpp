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
Node* takeInputBetter()
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
Node* swap(Node* head,int i,int j)
{
	int low=min(i,j);
	int high=max(i,j);
	Node* temp=head;
	Node* prevLow=NULL;
	Node* nextHigh=NULL;
	Node* lowptr=NULL;
	Node* highptr=NULL;
	Node* nextLow=NULL;
	Node* prevHigh=NULL;
	int countLow=0;
	int countHigh=0;
	if(low==0)
	{
		if(high==1)
		{
			lowptr=temp;
			highptr=temp->next;
			nextHigh=highptr->next;
			lowptr->next=nextHigh;
			highptr->next=lowptr;
			return highptr;
		}
		else
		{
			lowptr=temp;
			nextLow=lowptr->next;
			while(temp!=NULL && countHigh<high-1)
			{
				temp=temp->next;
				countHigh++;
			}
			prevHigh=temp;
			temp=temp->next;
			highptr=temp;
			nextHigh=highptr->next;
			highptr->next=nextLow;
			prevHigh->next=lowptr;
			lowptr->next=nextHigh;
			return highptr;
		}
	}
	if(high-low==1) // if they are consecutive
	{
		while(temp!=NULL && countLow<low-1)
		{
			temp=temp->next;
			countLow++;
			countHigh++;
		}
		lowptr=temp->next;
		prevLow=temp;
		while(temp!=NULL && countHigh<high-1)
		{
			temp=temp->next;
			countHigh++;
		}
		temp=temp->next;
		highptr=temp;
		nextHigh=highptr->next;
		prevLow->next=highptr;
		lowptr->next=nextHigh;
		highptr->next=lowptr;
	}
	else
	{
		while(temp!=NULL && countLow<low-1)
		{
			temp=temp->next;
			countLow++;
			countHigh++;
		}
		prevLow=temp;
		lowptr=temp->next;
		nextLow=lowptr->next;
		while(temp!=NULL && countHigh<high-1)
		{
			temp=temp->next;
			countHigh++;
		}
		prevHigh=temp;
		temp=temp->next;
		highptr=temp;
		nextHigh=highptr->next;
		// Now swapping the node;
		prevLow->next=highptr;
		highptr->next=nextLow;
		prevHigh->next=lowptr;
		lowptr->next=nextHigh;
	}
	return head;
}
void print(Node* head)
{
	if(head==NULL)
	{
		return;
	}
	cout<<head->data<<" ";
	print(head->next);
}
int main()
{
	Node* head=takeInputBetter();
	int i,j;
	cin>>i>>j;
	head=swap(head,i,j);
	print(head);
	cout<<endl;
}
