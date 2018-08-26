/*Problem Statement:Beginning with an empty binary search tree ,construct a binary search tree by inserting the values in order given After constructing a binary tree
i)insert a new node 
ii)Find number of nodes in longest path
iii.)Minimum data found in tree
iV)Search a value

Name:Mayur Deshmukh
Class:SE-A
Roll No: 18
*/
//header files 

#include<iostream>
#include<cstdlib>
using namespace std;

struct treenode
{
	int data;
	treenode *left,*right;

};//end of structure

class BST
{
	public:
			treenode *root;
			BST()//constructor
			{
				root=NULL;
			}
			void create();
			void displaytree(treenode *pT,int level);
			int search(int);
			void del(int);
			treenode *min();
			treenode *max();
			void inorder(treenode*);
			void print_inorder();
			void preorder(treenode*);
			void print_preorder();
			
};//end of class

void BST::create()		//function to create binary search tree
{
	char ans;
	treenode *curr,*temp;
	do
	{
		curr=new treenode;
		curr->left=NULL;
		curr->right=NULL;
		cout<<"\n Enter Data :";
		cin>>curr->data;
		if(root==NULL)
		{
			root=curr;
		}
		else
		{
			temp=root;
			
				while(1)
				{
					 if(curr->data<temp->data)
					{
						if(temp->left==NULL)
						{
							temp->left=curr;
							cout<<"\n\n NODE ADDED TO LEFT\n";
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
							cout<<"\n NODE ADDED TO RIGHT\n";
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

void BST::displaytree(treenode *pT,int level)	//function to display tree
{
	int i;
	if(pT!=NULL)
	{
		displaytree(pT->right,level+1);
		cout<<endl;
		if(pT==root)
		cout<<"Root->";
		else
		{
			for(i=0;i<level;i++)
			cout<<"           ";
		}//end of for
		cout<<pT->data;
		displaytree(pT->left,level+1);
	}		
}//end of displaytree		

int BST::search(int x)			//function to search data	
{
	int f=0;	
	treenode *temp=root;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			f=1;
			break;
		}
		else if(temp->data<x)
		{
			temp=temp->right;
			
		}
		else if(temp->data>x)
		{
			temp=temp->left;
		}
	}//end of while
	return f;
}//end of search

treenode* BST::min()		//function to find minimum data
{
	treenode *curr;
	curr=root;
	while(curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr;
}//end of min

treenode* BST::max()		//function to find maximum data
{
	treenode *curr;
	curr=root;
	while(curr->right!=NULL)
	{
		curr=curr->right;
	}
	return curr;
}//end of max

void BST::inorder(treenode* p)
{
	if(p!=NULL)
	{
		if(p->left)
		inorder(p->left);
		cout<<" "<<p->data<<" ";
		if(p->right)
		inorder(p->right);
	}
	else
	return;
}

void BST::print_inorder()
{
	inorder(root);
}

void BST::preorder(treenode* p)
{
	if(p!=NULL)
	{
		cout<<" "<<p->data<<" ";
		if(p->left)
		preorder(p->left);
		if(p->right)
		preorder(p->right);
	}
	else
	return;
}

void BST::print_preorder()
{
	preorder(root);
}

void 	BST::del(int x1)
{
	treenode *temp=root,*p_node=temp;
	while(temp!=NULL)
	{
		if(temp->data==x1)
			break;
		else if(temp->data<x1)
		{
			p_node=temp;
			temp=temp->right;
		}
		else if(temp->data>x1)
		{
			p_node=temp;
			temp=temp->left;
		}
	}
	if(temp->left==NULL && temp->right==NULL)
	{
		if(p_node->left==temp)
		p_node->left==NULL;
		else if(p_node->right==temp)
		p_node->right=NULL;
	}
	else if(temp->left==NULL && temp->right!=NULL)
	{
		if(p_node->left==temp)
		p_node->left==temp->right;
		else if(p_node->right==temp)
		p_node->right=temp->right;
	}
	else if(temp->left!=NULL && temp->right==NULL)
	{
		if(p_node->left==temp)
		p_node->left==temp->left;
		else if(p_node->right==temp)
		p_node->right=temp->left;
	}
	else
	{
		treenode *in_node=temp->right;
		treenode *inp_node=temp;
		
		while(in_node->left!=NULL)
		{
			inp_node=in_node;
			in_node=in_node->left;
		}
		temp->data=in_node->data;
		if(in_node->left==NULL)
		inp_node->right=NULL;
		else
		inp_node->left=NULL;	
	}
}//end of del		
										

int main()
{
	treenode *Min,*Max,*root;	
	BST b;
	int x,f,iCh,flag=0,x1;
	do
	{
		
		cout<<"\n****************************************\n";
		cout<<"		    LIST 			   ";
		cout<<"\n****************************************\n";
		cout<<"1.CREATE TREE\n2.DISPLAY TREE\n3.SEARCH DATA\n4.DELETE\n5.MINIMUM DATA\n6.MAXIMUM DATA\n7.INORDER\n8.PREORDER\n9.EXIT\n";
		cout<<"\n Enter choice:";
		cin>>iCh;
		switch(iCh)
		{
			case 1://create node
				b.create();
				flag=1;
				break;
			
			case 2://display tree
				if(flag==0)
				{
					cout<<"\n No Tree Created Yet To Display"; 
				}
				else
				{
					cout<<"\n-------------------------------\n";
					cout<<"\n Binary Search Tree:";
					cout<<"\n-------------------------------\n";
					b.displaytree(b.root,1);	
				}	
				break;
				
			case 3://search
				cout<<"\n Enter data to be searched :";
				cin>>x;
				f=b.search(x);
				if(f==1)
				cout<<"\n DATA FOUND";
				else
				cout<<"\n DATA NOT FOUND";
				break;
				
			case 4://delete
				cout<<"\n Enter the data to be deleted:";
				cin>>x1;
				f=b.search(x1);
				if(f==1)
				{
					cout<<"\n DATA FOUND AND DELETED";
					b.del(x1);
					cout<<"\n BINARY SEARCH TREE AFTER DELETION";
					b.displaytree(b.root,1);
				}
				else
				cout<<"\n DATA NOT FOUND";
				break;		
				
			case 5://minimum data		
				Min=b.min();
				cout<<"\nMINIMUM DATA :"<<Min->data;
				break;
			
			case 6://maximum data
				Max=b.max();
				cout<<"\nMAXIMUM DATA :"<<Max->data;
				break;
			
			case 7://inorder traversal
				cout<<"\n INORDER TRAVERSAL:";
				b.print_inorder();
				break;
						
			case 8://preorder traversal
				cout<<"\n PREORDER TRAVERSAL:";
				b.print_preorder();
				break;
				
			case 9://exit
				exit(0);	
		}//end of switch
	}while(iCh!=9);//end of while				
	return 0;
}																	
