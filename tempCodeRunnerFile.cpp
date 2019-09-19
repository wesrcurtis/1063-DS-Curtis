//Name: Josh Cupp
//Program 1
//Data Structures T-Th 11-12:20
//9-17-2019
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LinkedList {//Linked List class

private:

	struct Employee {//Sruct for Employee
		string emp_id;
		string first_name;
		string last_name;
		string gender;
		string email;
		double hourly_pay;
		Employee *Next;
		string key;

		Employee() {//Default contructor for Employee
			emp_id = "";
			first_name = "";
			last_name = "";
			gender = "";
			email = "";
			hourly_pay = 0.0;
			Next = NULL;

		}
		//Parameterized constuctor for the stuct Employee
		Employee(string id, string first, string last, string sex, string mail, double pay) {
			emp_id = id;
			first_name = first;
			last_name = last;
			gender = sex;
			email = mail;
			hourly_pay = pay;
			Next = NULL;

		}
	};

	int size;     //Name: Josh Cupp  

	Employee* Head;


public:

	LinkedList() {//Default constructor for class
		Head = NULL;
		size = 0;
	}

	//Function: void push(string id, string first, string last, string sex, string mail, double pay)
	//
	//Description: Adds an Employee to the front of the list and pushes the
	//				other nodes down.
	//
	//Parameters: Takes in all of the variables that make up the employee 
	//				struct.
	//
	void push(string id, string first, string last, string sex, string mail, double pay)
	{
		Employee* Temp = new Employee(id, first, last, sex, mail, pay);//creates new node
		size++;


		if (Head == NULL) {//if head is Null then head is assigned to temp
			Head = Temp;
		}
		else {
			Temp->Next = Head;
			Head = Temp;
		}
	}

	//Function: void pop()
	//
	//Decription: Removes an item from the front of the list.
	//				It does not take in any parameters.
	//
	void pop()
	{
		if (Head == NULL)
		{
			cout << "List Empty" << endl;
			system("pause");
			system("CLS");
		}
		else                                   //Name: Josh Cupp//
		{
			Employee *Temp = Head;
			Head = Head->Next;
			free(Temp);
			size--;
			cout << "Popped one off the list" << endl;
			system("pause");
			system("CLS");
		}
	}

	//Function: bool find(string email)
	//
	//Description: Based on the email that was sent in by the user, this
	//				function searches the list to see if an email matches.
	//
	//Parameters: Takes in a string email from the user.
	//
	//Returns: True or False based on whether it found a match from the list.
	bool find(string email)
	{
		Employee *Temp = Head;
		while (Temp != NULL)
		{
			if (Temp == NULL) {
				// Email was never foud
				return false;
			}
			if (Temp->email == email) {
				// email was found
				return true;
			}
			else {
				// going to next node
				Temp = Temp->Next;
			}
		}
	}
	//Function: void print()
	//
	//Description: Prints out the entire list.
	//				Takes in nothing.
	//
	void print()
	{
		Employee* Temp = Head;//Making a temp employee point to head
		cout << "Printing Entire list" << endl;           //Name: Josh Cupp
		system("pause");
		system("CLS");
		while (Temp != NULL) {
			cout << Temp->emp_id << ", " << Temp->first_name << ", " << Temp->last_name << ", " << Temp->email << ", " << Temp->gender << ", " << Temp->hourly_pay;
			cout << endl;
			if (Temp->Next) {
				cout << "->";
			}
			Temp = Temp->Next;
		}
		cout << endl << endl;
	}

	//Function: bool Delete(string email)
	//
	//Description: Searches list for an email that the user sends in and
	//				deletes that email.
	//
	//Parameters: Takes in a string email
	//
	//Returns: Returns a bool varialble(true or false) based on whether a
	//			string email has been found.
	bool Delete(string email)
	{
		Employee *Temp = Head;
		Employee *TempTrailer = Head;
		while (Temp != NULL)
		{
			if (Temp == NULL) {
				// Email was never found
				cout << "Cannot Delete due to Email not being found" << endl;
				system("pause");
				system("CLS");
				return false;
			}
			if (Temp->email == email) {
				// email was found
				cout << "Deleting Email" << endl;
				system("pause");
				system("CLS");
				TempTrailer->Next = Temp->Next;

				free(Temp);//delete Temp
				size--;
				return true;
			}
			else {                                      //Name: Josh Cupp
				// going to next node
				TempTrailer = Temp;
				Temp = Temp->Next;
			}
		}
		return false;
	}

	//Function: void substringMatch
	//
	//Decription:Searches for partial matches of a string and prints those 
	//				matches to the output file.
	//
	//Parameters:Takes in ofstream object by refrence
	//
	//Output:Prints the emails that were matched by the substrings to the 
	//			screen
	void substringMatch(ofstream &outputFile)
	{
		
		
		Employee *Temp = Head; //Temp variable
		string substring = "salon"; //string that we are searching for

		int substringCount = 0;//Count incrementation

		while (Temp != NULL)
		{
			string emailString = Temp->email;
			if (emailString.find(substring) != std::string::npos)//compares strings
			{
				substringCount++;
				
				outputFile << emailString << endl;//outputing emails
			}
			Temp = Temp->Next;//going to next node

		}
		outputFile << "Found: " << substringCount << " instances of " << substring << endl;
		
	}
	//Funtion: void printId
	//
	//Description: prints out the frist 30 Employee Ids to an output file
	//
	//Parameters: Takes in ofstream object by refrence so the it can connect
	//				to the output file             
	//
	//Name: Josh Cupp//
	//
	//output:outputs employee IDs to the output file
	void printId(ofstream &outputFile)
	{
		

		Employee* Temp = Head;
		int count = 0;
		while (count < 30)//print only the first 30 nodes in list
		{
		
			outputFile << Temp->emp_id;
			
			outputFile << endl;
			Temp = Temp->Next;//going to next node
			count++; // increment count
		}
		outputFile << endl << endl;
		

		

	}
};


void FindFunction(LinkedList x);
void DeleteFunction(LinkedList &x);


int main() {
	

	LinkedList EmpList;//linked list object for employees

	//initializing employee variables
	string empid, first, last, email, gender;
	double pay;

	ifstream fin("employees.dat");
	ofstream outputFile;
	outputFile.open("output.txt");
	
	bool menu = 1;//control for menu

	while (!fin.eof()) {//stops at end of file

		fin >> empid >> first >> last >> gender >> email >> pay;//reading from list //Name:Josh Cupp//

		EmpList.push(empid, first, last, gender, email, pay);
		
	}
	fin.clear();
	fin.seekg(0);
	
	while (menu == true)//Menu for methods. Repeats until user quits
	{
		int userChoice;
		cout << "\nMenu of Operations:\n";
		cout << "    1 - Find Employee" << endl;
		cout << "    2 - Delete Employee" << endl;
		cout << "    3 - Push Employee" << endl;
		cout << "    4 - Pop Employee" << endl;
		cout << "    5 - Quit" << endl;
		cin >> userChoice;
		switch (userChoice)//switch calls the functions based on the users choice in the menu
		{
		case 1:
			FindFunction(EmpList);
			break;
		case 2:
			DeleteFunction(EmpList);
			break;
		case 3:
			EmpList.push(empid, first, last, gender, email, pay);
			break;
		case 4:
			EmpList.pop();
			break;
		case 5:
			cout << "Quitting menu" << endl;
			menu = 0;
			break;
		}

	}
	
	EmpList.printId(outputFile);// printing 30 Ids

	EmpList.substringMatch(outputFile);//matches substrings based on emails

	outputFile.close();
	system("pause");
	return 0;
}
//Name:Josh Cupp//
//Funtion: void FindFunction
//
//Description: Asks user for an email and then calls the find() function 
//				which searches for the email
//
//Parameters: Takes in a linked list object
//
//OutPut: If an email is found it will output the name of the email to the
//			the scree. If an email is not found then it will output "email 
//			has not been found" to the screen.
void FindFunction(LinkedList x) {

	cout << "What email are you trying to find? " << endl;
	cout << endl << endl;
	string findEmail;
	cin >> findEmail;
	cout << endl << endl;

	cout << "Looking for " << findEmail << "...." << endl;
	cout << endl << endl;
	system("pause");
	system("CLS");


	if (x.find(findEmail) == true)
	{
		cout << "Email [" << findEmail << "]" << endl;
		cout << "Has been Found" << endl;
		system("pause");
		system("CLS");
	}
	else {
		cout << "Email [" << findEmail << "]" << endl;
		cout << "Has NOT been found" << endl;
		system("pause");
		system("CLS");
	}


}
//Function: void Delete Fucntion              //Name:Josh Cupp//
//
//Description: Asks the user to pick from the list what email that they wish
//				to delete
//
//Parameters: Takes in a linked list object that is passed by reference
//
//Output: couts the deleted email to the screen
void DeleteFunction(LinkedList &x) {

	cout << "What email are you trying to Delete? " << endl;
	
	string deleteEmail;
	cin >> deleteEmail;
	cout << endl << endl;

	cout << "Looking for " << deleteEmail << "...." << endl;
	cout << endl << endl;
	system("pause");
	system("CLS");

	if (x.Delete(deleteEmail) == true)
	{
		cout << "Email [" << deleteEmail << "]" << endl;
		cout << "Has been Found and Deleted" << endl;
		system("pause");
		system("CLS");
	}

	else
	{
		cout << "Email [" << deleteEmail << "]" << endl;
		cout << "Has NOT been found" << endl;
		system("pause");
		system("CLS");
	}

	//Name: Josh Cupp//
}