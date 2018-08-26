/*  Problem Satement:A Dictionary stores keyword and its meaning.Provide facility for adding new keywords,deleting keywords,updating values of any entry .Provide facility to disply whole data sorted in ascending/desending order.Also find how many maximum comparison may requre for finding any keyword .Use Binary search tree for implementation

Name:Mayur Deshmukh
Class:SE-A
Roll No: 18
*/

//header files

#include<iostream>
#include<string.h>
using namespace std;

struct node
{
	char data[20],meaning[30];
	node *left,*right;
};//node structure

class BT
{
	public:
	 node *root;
		public:
			BT()
			{
				root=NULL;
			}
			void creat();
			int search(char []);
			void display(node *);
			void delet(char []);
			void modify(char[] );
			int comparison(char []);
};//end of class

void BT::creat()
{
	char ans;
	node *curr,*temp,*parent;
	do
	{
		curr=new node;
		curr->left=NULL;
		curr->right=NULL;
		cout<<"\n\nENTER WORD : ";
		cin>>curr->data;
		cout<<"\n\nENTER MEANING : ";
		cin.ignore();
		cin.getline(curr->meaning,25);
		if(root==NULL)
		{
			root=curr;
		}
		else
		{
			temp=root;	
			while(1)
			{
				if(strcmp(curr->data,temp->data)==-1)
				{
					if(temp->left==NULL)
					{
						temp->left=curr;
						break;
					}
					else
					temp=temp->left;
				}
				else
				{
					if(temp->right==NULL)
					{
						temp->right=curr;
						break;
					}
					else
					temp=temp->right;
				}
			}//end of while
		}//end of else
		cout<<"\n\nDO YOU WANT TO ENTER MORE";
		cin>>ans;
	}while(ans=='y');//end of do-while
}

void BT::display(node *root)
{
	if(root!=NULL)
	{
		display(root->left);
		cout<<root->data<<" : "<<root->meaning<<"\n";
		display(root->right);
	}	
}//end of display
int BT::search(char num[20])
{
	int found=0;
	node *temp=root;
	while(temp!=NULL)
	{
		if(strcmp(temp->data,num)==0)
		{
			found=1;
			cout<<temp->data<<" : "<<temp->meaning<<"\n";
			break;
		}
		else if(strcmp(temp->data,num)==-1)
		{
			temp=temp->right;
		}
		else if(strcmp(temp->data,num)==1)
		{
			temp=temp->left;
		}
	}//end of while
	return found;
}//end of search
void  BT::modify(char num[20])
{
	int found=0;
	node *temp=root;
	while(temp!=NULL)
	{
		if(strcmp(temp->data,num)==0)
		{
			found=1;
			cout<<temp->data<<" : "<<temp->meaning<<"\n";
			cout<<"\n\nENTER MODIFY WORD : ";
			cin>>temp->data;
			cout<<"\n\nENTER MODIFY MEANING : ";
			cin.ignore();
			cin.getline(temp->meaning,25);
			break;
		}
		else if(strcmp(temp->data,num)==-1)
		{
			temp=temp->right;
		}
		else if(strcmp(temp->data,num)==1)
		{
			temp=temp->left;
		}
	}//end of while
}
void BT::delet(char word[20])
{
	char copy[20];
	node *temp=root,*parentNode=root;
	while(temp!=NULL)
	{
		if(strcmp(temp->data,word)==0)
			break;
		else if(strcmp(temp->data,word)==-1)
		{
			parentNode=temp;
			temp=temp->right;
		}
		else if(strcmp(temp->data,word)==1)
		{
				parentNode=temp;
				temp=temp->left;
		}
	}//end of while
	if(temp->left==NULL && temp->right==NULL)
	{
		if(temp==root)     //if only one node in tree = root node
			root=NULL;
		else
		{
			if(parentNode->left==temp)
			parentNode->left=NULL;
			else if(parentNode->right==temp)
			parentNode->right=NULL;
		}
	}
	else if(temp->left==NULL && temp->right!=NULL)
	{
		if(temp==root)
			root=root->right;
		else
		{
			if(parentNode->left==temp)
			parentNode->left=temp->right;
			else if(parentNode->right==temp)
			parentNode->right=temp->right;	
		}
		
	}
	else if(temp->left!=NULL && temp->right==NULL)
	{
		if(temp==root)
			root=root->left;
		else
		{
			if(parentNode->left==temp)
			parentNode->left=temp->left;
			else if(parentNode->right==temp)
			parentNode->right=temp->left;		
		}
		
	}
	else
	{
		node *inorderNode=temp->right,*inorderParent=temp;
		while(inorderNode->left!=NULL)
		{
			inorderParent=inorderNode;
			inorderNode=inorderNode->left;
		}
		strcpy(temp->data,inorderNode->data);
		strcpy(temp->meaning,inorderNode->meaning);
		if(inorderNode->left==NULL && inorderNode->right==NULL)
			{
				if(inorderParent->left==inorderNode)                 
				inorderParent->left=NULL;	
				else if(inorderParent->right==inorderNode)          
				inorderParent->right=NULL;
			}
		else if(inorderNode->left==NULL && inorderNode->right!=NULL)
		{
			if(inorderParent->left==inorderNode)
			inorderParent->left=inorderNode->right; 
			else
			inorderParent->right=inorderNode->right;
		}
	}
	delete temp;
}//end of delete
int BT::comparison(char num[20])
{
	int found=0;
	node *temp=root;
	while(temp!=NULL)
	{
		if(strcmp(temp->data,num)==0)
		{
			found++;;
			cout<<temp->data<<" : "<<temp->meaning<<"\n";
			break;
		}
		else if(strcmp(temp->data,num)==-1)
		{
			found++;
			temp=temp->right;
		}
		else if(strcmp(temp->data,num)==1)
		{
			found++;
			temp=temp->left;
		}
	}//end of while
	return found;
}
int main()
{
	node *retun;
	int  found,iCh;
	char ans,word[20];
	BT b;
	do
	{
		cout<<"\n\n\n\nENTER YOUR CHOICE\n1.CREAT TREE\n2.DISPLY TREE\n3.SEARCH NODE\n4.DELETE NODE\n5.MODIFY DATA\nNUMBER OF COMPARISION REQUIRED\n";
		cin>>iCh;
		switch(iCh)
		{
			case 1: b.creat();
					break;
			case 2: b.display(b.root);
					break;
			case 3: cout<<"\n\nENTER WORD WANT TO SEARCH";
					cin>>word;
					found=b.search(word);
					if(found==1)
					cout<<"\n\n' YES FOUND NODE '";
					else
					cout<<"\n\n'NOT FOUND NODE '";
					break;
			case 4: cout<<"\n\nENTER WORD WANT TO DELETE";
					cin>>word;
					found=b.search(word);
					if(found==1)
					{
						cout<<"\n\n' YES FOUND NODE '";
						b.delet(word);
						cout<<"\n\nFTER DELETION NODE TREE IS\n\t";
						b.display(b.root);
					}
					else
					cout<<"\n\n'NOT FOUND NODE '";
					break;
			case 5:	cout<<"\n\nENTER WORD WANT TO MODIFY";
					cin>>word;
					b.modify(word);
					break;
			case 6:	cout<<"\n\nENTER WORD WANT TO SEARCH";
					cin>>word;
					found=b.comparison(word);
					cout<<"\n\n' NUMBER OF COMPARISION  : '"<<found;
					break;
					
		}
	}while(iCh<7);
	return 0;
}

