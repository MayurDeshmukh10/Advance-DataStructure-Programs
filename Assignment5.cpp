/*Problem Satement:There are flight paths between cities.If there is a flight between city A and B then there is an edge between the cities.The cost of edge can be the time that flight takes to reach city B from A,or the amount of fuel used for the journey.represent this as a graph.The node can be represented by airport name or name of city.Use adjacency list representation of graph or use adjacency matrix representation of graph .Justify the storage representation used.

Name:Mayur Deshmukh
Class:SE-A
Roll No: 18
*/

//header files

#include<iostream>
#include <fstream>
#include<string.h>
#define max 10
using namespace std;

struct city
{
	char name[20];
	char fuel[10];
};//end of structure

class graph
{
	city mat[max][max];
	int n;
	public:
		graph()
		{
			for(int i=0;i<max;i++)
				for(int j=0;j<max;j++)
				{
					strcpy(mat[i][j].fuel,"\0");
					strcpy(mat[i][j].name,"\0");
				}
					
					
		}
	void read();
	void display();
	void dfs(char[]);
    	void search_path();
};//end of class

void graph::read()
{
	char ans2,ans1,source[20],desti[20];
	int i,j,flag1=0,flag2=0;
	ifstream f1("input58.txt");
	cout<<"\nEnter the number of CITIES you want\n";
	f1>>n;
	for( i=1;i<=n;i++)
	{
		cout<<"\n\nENTER CITY NAMES";
		f1>>mat[i][0].name;
		strcpy(mat[0][i].name,mat[i][0].name);
	}
	do
	{
		cout<<"\nENTER START CITY NAME AND DESTINATION CITY NAME which have direct path";
		f1>>source;
		f1>>desti;
		for(i=1;i<=n;i++)
		{
			if(strcmp(source,mat[i][0].name)==0)
			{
				
				flag1=1;
				for(j=1;j<=n;j++)
				{
					if(strcmp(desti,mat[0][j].name)==0)
					{
						cout<<"\n\nENTER TIME REQURED TO REACH from "<<source<<" to "<<desti;
						f1>>mat[i][j].name;
						strcpy(mat[j][i].name,mat[i][j].name);
						cout<<"\n\nENTER FUEL REQURED TO REACH from "<<source<<" to "<<desti;
						f1>>mat[i][j].fuel;
						strcpy(mat[j][i].fuel,mat[i][j].fuel);
						flag2=1;
						break;
					}
				}
				break;
			}
		}
		if(flag1==0)
		cout<<"\n\nSORRY CITY IS NOT PRESENT IN DATA : "<<source;
		if(flag2==0 && flag1==1)
		cout<<"\n\nSORRY CITY IS NOT PRESENT IN DATA : "<<desti;
		cout<<"\n\nWANT TO CONTINUE";
		f1>>ans2;
	}while(ans2=='y' || ans2=='Y');
}//end of read

void graph::display()
{
	
	cout<<"\n\n";
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{ 
			cout<<"\t"<<mat[j][i].name;
			if(i!=0 && j!=0)
			cout<<" "<<mat[j][i].fuel;
		}//end of for
		cout<<"\n";
	}//end of for
}//end of display

void graph::search_path()
{
	char source[20],desti[20];
	int i,flag1=0,flag2=0,j;
		cout<<"\n\n\nENTER START CITY NAME AND DESTINATION CITY NAME : ";
		cin>>source>>desti;
		for(i=1;i<=n;i++)
		{
			if(strcmp(source,mat[i][0].name)==0)
			{
				
				flag1=1;
				for(j=1;j<=n;j++)
				{
					if(strcmp(desti,mat[0][j].name)==0)
					{
						if(mat[i][j].fuel!=0 &&i!=j)
						cout<<"\n\n\n\n TIME REQURED TO REACH from "<<source<<" to "<<desti<<" is : "<<mat[i][j].name<<" and fuel is : "<<mat[i][j].fuel;
						else
						cout<<"\n\nSORRY PATH IS NOT PRESENT / YOU ARE ALREADY ON DESTINATION POINT";
						flag2=1;
						break;
					}
					
				}
				break;
			}
		}
		if(flag1==0)
		cout<<"\n\nSORRY CITY IS NOT PRESENT IN DATA : "<<source;
		else if(flag2==0)
		cout<<"\n\nSORRY CITY IS NOT PRESENT IN DATA : "<<desti;
}
int main()
{
	graph g;
	int ch;
	char ans;
	do
	{
		cout<<"\n\nENTER CHOICE 1.CREAT GRAPH\n2.DISPLAY GRAPH\n3.SEARCH DIRECT PATH\n";
		cin>>ch;
		switch(ch)
		{
			case 1:	g.read();
					break;
			case 2:	cout << "\n	ADJACENCY MATRIX IS  " << "\n";
					g.display();
					break;
			case 3:	g.search_path();
					break;
			default: cout<<"\nENTER VALID CHOICE";
					break;
		
		}
		cout<<"\nWANT TO CONTINUE ?";
		cin>>ans;
	}while(ans=='y'||ans=='Y');   
}	
