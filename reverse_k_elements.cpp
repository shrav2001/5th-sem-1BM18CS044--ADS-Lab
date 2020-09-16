/*
16th seprtember 2020 - lab0
*/
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("memory could not be allocated\n");
		exit(0);
	}
}
NODE insert_end(NODE head,int item)
{
	NODE p,q;
	q=getnode();
	q->data=item;
	q->next=NULL;
	if(head==NULL)
		return q;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	return head;
	
}
NODE reverse(NODE head, int k)
{
  NODE curr=head,prev=NULL, next =NULL;
  int count=0;
  while(curr!=NULL && count<k)
  {
	  next = curr->next;
	  curr->next = prev;
	  prev = curr;
	  curr = next;
	  count++;
  }
  if(next!=NULL)
  {
	  head->next = reverse(next,k);
  }
  return prev;
}
int main()
{
    NODE head=NULL;
	int k,item,n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>item;
	    head=insert_end(head,item);
    }
    cin>>k;
    head = reverse(head,k);
	while(head!=NULL){
	    cout<<head->data<<" ";
	    head = head->next;
	}
    return 0;
}
