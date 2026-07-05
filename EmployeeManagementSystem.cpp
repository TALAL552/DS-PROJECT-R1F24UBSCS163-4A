#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id;
    string name;
    string department;
    float salary;
    Node* next;
};

Node* head = NULL;

void addEmployee()
{
    Node* temp = new Node;

    cout << "\nEnter Employee ID: ";
    cin >> temp->id;
    cin.ignore();

    cout << "Enter Employee Name: ";
    getline(cin, temp->name);

    cout << "Enter Department: ";
    getline(cin, temp->department);

    cout << "Enter Salary: ";
    cin >> temp->salary;

    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Node* ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }

    cout << "\nEmployee Added Successfully!\n";
}

void displayEmployees()
{
    if(head == NULL)
    {
        cout << "\nNo Employees Found!\n";
        return;
    }

    Node* ptr = head;

    cout << "\n===== Employee Records =====\n";

    while(ptr != NULL)
    {
        cout << "ID: " << ptr->id << endl;
        cout << "Name: " << ptr->name << endl;
        cout << "Department: " << ptr->department << endl;
        cout << "Salary: " << ptr->salary << endl;
        cout << "---------------------------\n";

        ptr = ptr->next;
    }
}

void searchEmployee()
{
    if(head == NULL)
    {
        cout << "\nNo Employees Found!\n";
        return;
    }

    int id;
    cout << "\nEnter Employee ID to Search: ";
    cin >> id;

    Node* ptr = head;

    while(ptr != NULL)
    {
        if(ptr->id == id)
        {
            cout << "\nEmployee Found!\n";
            cout << "ID: " << ptr->id << endl;
            cout << "Name: " << ptr->name << endl;
            cout << "Department: " << ptr->department << endl;
            cout << "Salary: " << ptr->salary << endl;
            return;
        }
        ptr = ptr->next;
    }

    cout << "\nEmployee Not Found!\n";
}

void deleteEmployee()
{
    if(head == NULL)
    {
        cout << "\nNo Employees Found!\n";
        return;
    }

    int id;
    cout << "\nEnter Employee ID to Delete: ";
    cin >> id;

    Node* current = head;
    Node* previous = NULL;

    while(current != NULL && current->id != id)
    {
        previous = current;
        current = current->next;
    }

    if(current == NULL)
    {
        cout << "\nEmployee Not Found!\n";
        return;
    }

    if(previous == NULL)
        head = current->next;
    else
        previous->next = current->next;

    delete current;

    cout << "\nEmployee Deleted Successfully!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\n Employee Management System";
        cout << "\n==============================";
        cout << "\n1. Add Employee";
        cout << "\n2. Display Employees";
        cout << "\n3. Search Employee";
        cout << "\n4. Delete Employee";
        cout << "\n5. Exit";
        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                cout << "\nThank You!\n";
                break;
            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
