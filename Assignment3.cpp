/*Problem Satement:Convert a given binary tree into threaded binary tree.Analyze time and space complexiety of given algorithm.

Name:Mayur Deshmukh
Class:SE-A
Roll No: 18
Assignment 3*/

#include<iostream>
#include<cstdlib>
using namespace std;

struct TBTtreenode
{
	int data;
	TBTtreenode *left,*right;
	int lthread,rthread;
};//end of structure

class TBT
{
	public:
			TBTtreenode *root,*head;
			TBT()//constructor
			{
				head=new TBTtreenode;
				head->left=head->right=head;
				head->lthread=head->rthread=1;
				root=NULL;
			}
			void create();
			void inorder();
};//end of class

void TBT::create()		//function to create binary search tree
{
	char ans;
	TBTtreenode *curr,*temp;
	do
	{
		curr=new TBTtreenode;
		curr->left=head;
		curr->right=head;
		curr->lthread=curr->rthread=1;
		cout<<"\n Enter Data :";
		cin>>curr->data;
		if(root==NULL)
		{
			root=curr;
			head->left=root;
			head->lthread=0;
		
		}
		else
		{
			temp=root;
			
				while(1)
				{
					 if(curr->data<temp->data)
					{
						if(temp->lthread==1)
						{
							curr->left=temp->left;
							curr->right=temp;
							temp->left=curr;
							temp->lthread=0;
							break;
							
						}
						else
						temp=temp->left;
			
					}
					else
					{
						if(temp->rthread==1)
						{
							curr->right=temp->right;
							curr->left=temp;
							temp->right=curr;
							temp->rthread=0;
							break;
							
						}
						else
						temp=temp->right;
						
					}//end of else
				}	
		}//else			
		cout<<"\n Add more Data:";
		cin>>ans;
	}while(ans=='y');//end of do
	
}//end of create

void TBT::inorder()
{
	TBTtreenode *curr=root;
	int f2=0;
	while(curr!=head)
	{
		if(curr->lthread==0 && f2==0)
			curr=curr->left;
		else
		{
			cout<<curr->data<<" ";
			f2=curr->rthread;
			curr=curr->right;
		}
	}//end of while

}//end of inorder			

int main()
{
	 	
	TBT t;
	int iCh;
	do
	{
		switch(iCh)
		{
			case 1://create
				t.create();
				break;
				
			case 2://display	
				cout<<"\n inorder";
				t.inorder();
				break;
				
			case 3:break;
		}		
	return 0;
}																	
