#include<iostream>
using namespace std;

int Calculator(int ,int , char );
int main()
{
	int first,second;
	char op;
	cout<<"Enter first operand:";
	cin>>first;
	cout<<"Enter second operand :";
	cin>>second;
	cout<<"Enter operator (+,-,*,/):";
	cin>>op;
	int result = Calculator(first,second,op);
	cout<<"The result is : "<<result;
	
}
int Calculator(int first,int second, char ope)
{
	if(ope == '+')
	{
		return(first+second);
	}
	else if(ope == '-')
	{
		return(first-second);
	}
	else if(ope == '*')
	{
		return(first*second);
	}
	else if(ope == '/')
	{
		if(second!=0)
		{
			return(first/second);
		}
		else
		{
			cout<<"Not Possible!\n";
			exit(0);
		}
	}
	else{
		cout<<"Invalid Operator!!\n";
		exit(0);
	}
}
