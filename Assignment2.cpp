/*Problem Statement:For a given expression eg.a-b*c-d/e+f construct inorder sequence and traverse it using postorder traversal (non-recursive)change a tree so that the roles of left and right pointers are swapped at every node.

Name:Mayur Deshmukh
Class:SE-A
Roll No: 18
*/
//header files 

#include<iostream>
#include"template_stack.cpp
using namespace std;

struct Treenode
{
	char data;
	struct Treenode *left,*right;
};//end of structure

class binarytree
{
	public:
		Treenode *root;
		public:
			binarytree()
			{
				root=NULL;	
			}
			void creat(char[]);
			void inorderNonRec();
			void postNonRec();
			void preNonRec();
			void inorderRec(Treenode *);
			void postRec(Treenode *);
			void preRec(Treenode *);
			void swap(Treenode*);
};//end of class

void binarytree::creat(char strpost[20])
{
	char cCh;
	stack<Treenode*>s;
	Treenode *curr;
	cout<<"\n\nPOSTFIX EXPRESION : "<<strpost;
	for(int i=0;strpost[i]!='\0';i++)
	{
		cCh=strpost[i];
		curr=new Treenode;
		curr->data=cCh;
		curr->left=NULL;
		curr->right=NULL;
		if(cCh>='a' && cCh<='z')
		{
			s.push(curr);	
		}
		else
		{
			curr->right=s.pop();
			curr->left=s.pop();
			s.push(curr);
		}
	}
	root=s.pop();
	
}//end of create

void binarytree::inorderRec(Treenode *root1)
{
	if(root1!=NULL)
	{
		inorderRec(root1->left);
		cout<<root1->data;
		inorderRec(root1->right);
	}	
}//end of inorderrec

void binarytree::postRec(Treenode *root1)
{
	if(root1!=NULL)
	{
		postRec(root1->left);
		postRec(root1->right);
		cout<<root1->data;
		
	}	
}//end of postrec

void binarytree::preRec(Treenode *root1)
{
	if(root1!=NULL)
	{
		cout<<root1->data;
		preRec(root1->left);
		preRec(root1->right);
	
	}	
}//end of prerec

void binarytree::inorderNonRec()
{
	stack<Treenode*>s;
	
        Treenode *curr=root;
	while(1)
	{
		while(curr!=NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		if(!s.IsEmpty())
		{
			curr=s.pop();
			cout<<curr->data;
			curr=curr->right;
		}
		else
		{
		     break;
		}
	}
	
}//end of inordernonrec

void binarytree::preNonRec()
{
	stack <Treenode*>s;
	
        Treenode *curr=root;
	while(1)
	{
		while(curr!=NULL)
		{
			s.push(curr);
			cout<<curr->data;
			curr=curr->left;
		}
		if(!s.IsEmpty())
		{
			curr=s.pop();
			curr=curr->right;
		}
		else
		{
		break;
		}
	}
}//end of prenonrec

void binarytree::postNonRec()
{
char ch;
	stack<char>cSt;
	stack<Treenode*>s;
	Treenode *curr=root;
	do
	{
		while(curr!=NULL)
		{
			s.push(curr);
			cSt.push('l');
			curr=curr->left;
		}
		if(!s.IsEmpty())
		{
		ch=cSt.pop();
		curr=s.pop();
		if(ch=='l')
		{
		s.push(curr);
		cSt.push('r');
		curr=curr->right;
		}
		else
		{
		cout<<curr->data;
		curr=NULL;
	}
	}else
	break;
	}while(1);
}//end of postnonrec

void swap1(Treenode *curr)
{
	Treenode *temp;
	temp=curr->left;
	curr->left=curr->right;
	curr->right=temp;
}//end of swap1

void binarytree::swap(Treenode *curr)
{
	if(curr!=NULL)
	{
		swap1(curr);
		swap(curr->left);
		swap(curr->right);
	}
}//end of swap

int main()
{
	int iCh;
	char strpost[20],ans;
	binarytree b;
	Treenode *curr2;
	cout<<"\n\nENTER POSTFIX EXPREESION	:	";
	cin>>strpost;
	b.creat(strpost);
	cout<<"\n\n\n";
	do
	{
	cout<<"\n\nENTER CHOICE\n\n1.RECURSIVE INORDER\n2.RECURSIVE POSTORDER\n3.RECURSIVE PREORDER\n4.NON-RECURSIVE INORDER\n5.NON-RECURSIVE POSTORDER\n6.NON-RECURSIVE PREORDER\n7.SWAPP TREE\n";
	cin>>iCh;
	switch(iCh)
	{
		case 1:b.inorderRec(b.root);
		break;
		case 2:b.postRec(b.root);
		break;
		case 3:b.preRec(b.root);
		break;
		case 4:b.inorderNonRec();
		break;
		case 5:b.postNonRec();
		break;
		case 6:b.preNonRec();
		break;
		case 7:b.swap(b.root);
				cout<<"\n\nTREE AFTER SWAPPING\n";
				b.inorderRec(b.root);
				break;

	}
	cout<<"\n\nWANT TO CONTINUE";
	cin>>ans;
	}while(ans=='y');
	
	return 0;
	
}
