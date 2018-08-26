/*Problem Statement:Write a program on excetion handling in java:Read array of marks and throw exception for array out of bound  and user defined exception for marks less than zero or greater than 100.

Name:Mayur Deshmukh
Class:SE-A
Roll No: 18
*/

//header files 

import java.util.*;

public class exceptionhandling{

	public static void main(String[] args) {
	Scanner input=new Scanner(System.in);
	int a[]=new int[20];
	int n;
	
	System.out.println("Enter the number of elements in array");
	n=input.nextInt();
	while(n>20)
	{
		try
		{
			a[n]=19;
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("\n Array Index Out of range");
			System.out.println("\n Enter number of elemnts:");
			n=input.nextInt();	
			
		}
	}
	{
		
		System.out.println("\n Enter array elements:");
		for(int i=0;i<n;i++)
		{
			a[i]=input.nextInt();
		}
		System.out.println("\n Elements of array are");
		for(int i=0;i<n;i++)
		{
			System.out.println(a[i]+"\t");
		}
	
	}
	try 
	{
            	// "abcd" is not a number
		int num = Integer.parseInt ("12") ;
		System.out.println("\n Number is:");
 		System.out.println(num);
        } 	
	catch(NumberFormatException e) 
	{
		System.out.println("\n Input should be integer value");		
		System.out.println("\n Number format exception");
        }
	
}
}

		
	
		
