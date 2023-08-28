#include<iostream>
#include<fstream>
#include <sstream> 
using namespace std;

int main()
{
	int choice;
	int i =0;
	menu:
	cout<<"\t\tWELCOME TO TODO LIST\nPress\n 1. To add a task in TODO LIST\n 2. To LOAD contents from a TODO list\n 3. To Delete the Task\n 4. To Mark a task as completed\n 5. To see completed TAsks\n 0. to EXIT\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				system("cls");
				ofstream TODO("TODO_List.txt",ios::app);
				cout<<"Enter the task\n";
				string task;
				cin.ignore();
				getline(cin,task);
				TODO<<task<<endl;
				i++;
				TODO.close();
				goto menu;
				break;
			}
		case 2:
			{
				system("cls");
				string str;
				ifstream LOAD("TODO_List.txt");
				while(getline(LOAD, str))
				cout<<str<<endl;
				LOAD.close();
				goto menu;
				break;
			}
		case 3:
			{
				system("cls");
				ifstream DELETE("TODO_List.txt");
		    
		    if (!DELETE.is_open()) {
		        cout << "Error opening the file!" << endl;
		        return 1;
		    }
		
		    string dataToDelete;
		    cout << "Enter the task you want to delete :";
		    cin >> dataToDelete;
		
	
		    stringstream buffer;
		    buffer << DELETE.rdbuf();
		    DELETE.close();
		
		 
		    string fileContent = buffer.str();
		    size_t pos = fileContent.find(dataToDelete);
		    if (pos != string::npos) {
		        fileContent.erase(pos, dataToDelete.length());
		        
		        size_t nextPos = fileContent.find_first_not_of(" \t\n\r");
		        while (nextPos != string::npos) {
		            fileContent.replace(pos, nextPos - pos, " ");
		            nextPos = fileContent.find_first_not_of(" \t\n\r", pos + 1);
		        }
		
	        ofstream outputFile("TODO_List.txt"); 
	        if (outputFile.is_open()) {
	            outputFile << fileContent; 
	            outputFile.close();
	            cout << "Data deleted from the file." << endl;
		        	} else {
		            cout << "Error writing to the file!" << endl;
		            return 1;
		        }
		    } else {
		        cout << "Data not found in the file." << endl;
		    }
			goto menu;
		}
		case 4:
			{
				system("cls");
				ifstream DELETE("TODO_List.txt"); 
		    
		    if (!DELETE.is_open()) {
		        cout << "Error opening the file!" << endl;
		        return 1;
		    }
		
		    string dataToDelete;
		    cout << "Enter the data you want to mark as completed: ";
		    cin >> dataToDelete;
		
		   
		    stringstream buffer;
		    buffer << DELETE.rdbuf();
		    DELETE.close();
		
		    
		    string fileContent = buffer.str();
		    size_t pos = fileContent.find(dataToDelete);
		    if (pos != string::npos) {
		        fileContent.erase(pos, dataToDelete.length());
		    
		        size_t nextPos = fileContent.find_first_not_of(" \t\n\r");
		        while (nextPos != string::npos) {
		            fileContent.replace(pos, nextPos - pos, " ");
		            nextPos = fileContent.find_first_not_of(" \t\n\r", pos + 1);
		        }
		
	        ofstream outputFile("Completed_List.txt"); 
	        if (outputFile.is_open()) {
	            outputFile << fileContent; 
	            outputFile.close();
	            cout << "Data deleted from the file." << endl;
		        	} else {
		            cout << "Error writing to the file!" << endl;
		            return 1;
		        }
		    } else {
		        cout << "Data not found in the file." << endl;
		    }
			goto menu;
			}
		case 5:
			{
				system("cls");
				string str;
				ifstream CLOAD("Completed_List.txt");
				while(getline(CLOAD, str))
				cout<<str<<endl;
				CLOAD.close();
				goto menu;
				break;
			}
		case 0:
			{
				exit(0);
			}
		default:
			{
				system("cls");
				cout<<"Invalid Input\n";
				goto menu;
			}
	}
}
