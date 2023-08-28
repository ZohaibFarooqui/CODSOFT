#include <iostream>
#include <cstdlib>
using namespace std;

void Menu();
void Exit();
void Game();
int main()
{
	Menu();
}

void Menu()
{
	int choice;
	men:
	cout<<"Press\n 1. to start the game\n 2. to exit\n";
	cin>>choice;
	system("cls");
	switch(choice)
	{
		case 1:
			Game();
			break;
		case 2:
			Exit();
			break;
		default:
			cout<<"Invalid Choice!\n Please enter a valid choice\n";
			goto men;
	}

}
void Exit()
{
	cout<<"Thank you for playing!";
	exit(0);
}
void Game()
{
	int a =rand() %10;
	cout<<"Random number has been generated!\n";
	x:
	cout<<"Enter a number in the range of 0-9\n";
	int num;
	cin>>num;
	if(num > a*2)
	{
		cout<<"Number is Too High!\n";
		goto x;
	}
	
	else if(num < a/2)
	{
		cout<<"Number is Too Low!\n";
		goto x;	
	}
	else if(num > a)
	{
		cout<<"Number is High!\n";
		goto x;
	}
	
	else if(num < a)
	{
		cout<<"Number is Low!\n";
		goto x;	
	}
	else if(num == a)
	{
		cout<<"Congratulations You have guessed it correct!\n";
		yorn:
		cout<<"Do you want to play again?(yes or no)\n";
		string choice;
		cin>> choice;
		if(choice == "yes"|| choice == "Yes" || choice == "YES")
		{
			Menu();
		}
		else if( choice == "no" || choice == "No" || choice == "NO")
		{
			Exit();
		}
		else
		{
			cout<<"Invalid Choice!\n Please enter a valid choice\n";
			goto yorn;
		}
		
	}
}

