/*
Wesley Curtis
1063 DS&ADT
P01
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Wesley Curtis
Employee struct:
Initializes variables and default constructor/constructor.
*/

struct Employee{
    
    string emp_ID; 
    string f_Name;
    string l_Name;
    string sex;
    string email;
    double wage;
    Employee *Next;

    Employee(){
        emp_ID = "";
        f_Name = "";
        l_Name = "";
        sex = "";
        email = "";
        wage = 0.0;
    }

    Employee(string id, string first, string last, string gender, string mail, double pay){
        emp_ID = id;
        f_Name = first;
        l_Name = last;
        sex = gender;
        email = mail;
        wage = pay * 1.0;
    }
};

/*
Wesley Curtis
EmployeeList class:
contains push and pop functions, find function, and print function

push(): pushes current employee struct to the back of the list
pop(): pops current employee struct from the back of the list
find(): searches all properties of structs via node to find certain criteria
print(): simply prints out all properties of first 30 Employees, in a clean format
deleteItem(): deletes nodes once not in use anymore
*/
class EmployeeList{
private:
    Employee* Head;
public:
    EmployeeList(){
        Head = NULL;
    }
    // push(): pushes current employee struct to the back of the list
    void push(Employee e){
        Employee* Temp = new Employee(e);

        if(Head == NULL){
            Head = Temp;
            Temp -> Next = NULL;
        }else{
            Temp -> Next = Head;
            Head = Temp;
        }  
    }
    // pop(): pops current employee struct from the back of the list
    void pop(Employee e){
        Employee* Temp = new Employee(e);
        if(Head == NULL){
            Head = Temp;
        }
        else {
            Employee* Temp2 = Head;
            while(Temp2 -> Next != NULL){
                Temp2 = Temp2 -> Next;
            }

            Temp2->Next = Temp;
        }
    }
    // find(): searches all properties of structs via node to find certain criteria
    bool find(string data){
        Employee* Temp = Head;
        bool found = false;

        while(Temp != NULL){
            if(!found){
                if(Temp -> emp_ID == data){
                    found = true;
                }
                if(Temp -> f_Name == data){
                    found = true;
                }
                if(Temp -> l_Name == data){
                    found = true;
                }
                if(Temp -> sex == data){
                    found = true;
                }
                if(Temp -> email == data){
                    found = true;
                }
            }
            Temp = Temp -> Next;
        }
        return found;
    }
    bool find(double data){
        Employee* Temp = Head;
        bool found = false;

        while(Temp != NULL){
            if(!found){
                if(Temp -> wage == data){
                    found = true;
                }
            }
            Temp = Temp -> Next;
        }
        return found;
    }
    // print(): simply prints out all properties of first 30 Employees, in a clean format
    void print(){
        Employee* Temp = Head;
        int x = 1;
        while(Temp != NULL){
            cout << "  Employee #" << x++ << "\n";
            cout << "ID: \t" << Temp -> emp_ID << "\n";
            cout << "Name: \t" << Temp -> f_Name << " " << Temp->l_Name << "\n";
            cout << "Gender: " << Temp -> sex << "\n";
            cout << "E-mail: " << Temp -> email << "\n";
            cout << "Wage: \t" << Temp -> wage << "\n\n";

            if (x > 30)
            {
              break;
            }

            Temp = Temp->Next;

        }
    }
    // deleteItem(): deletes nodes once not in use anymore
    void deleteItem(string data){
        Employee* Temp = Head;

        while(Temp != NULL){
            if(Temp -> emp_ID == data){
                Temp -> emp_ID = "NULL";
            }
            if(Temp -> f_Name == data){
                Temp -> f_Name = "NULL";
            }
            if(Temp -> l_Name == data){
                Temp -> l_Name = "NULL";
            }
            if(Temp -> sex == data){
                Temp -> sex = "NULL";
            }
            if(Temp -> email == data){
                Temp -> email = "NULL";
            }
            Temp = Temp -> Next;
        }
    }
    void deleteItem(double data){
        Employee* Temp = Head;
        while(Temp != NULL){
            if(Temp -> wage == data){
                Temp -> wage = 0;
            }
            Temp = Temp -> Next;
        }
    }
};
/*
Wesley Curtis
main method:
reads in "employees.txt" to structs, prints
*/
int main(){
    EmployeeList EmpList;
    string empid;
    string first;
    string last;
    string email;
    string sex;
    double pay;

    ifstream inFile("employees.txt");

    while(!inFile.eof()){
        inFile >> empid >> first >> last >> email >> sex >> pay;
        Employee e(empid, first, last, email, sex, pay);
        EmpList.push(e);
    }

    EmpList.print();
    return 0;
}
// Wesley Curtis