#include <iostream>
#include <string>
using namespace std;

struct node 
{
    int prn;
    string name;
    node* next;
};

node *temp,*temp1,*temp2;

class SLLPin 
{
public:
    node *head,*tail,*nnode;

    SLLPin()  
    {
        head = tail = NULL;
    }

    void crt();
    void dplay();
    void insertAtBeginning();
    void insertAtEnd();
    void intermediate();
    void count();
};

void SLLPin::crt() 
{
    char ch;
    do 
    {
        nnode = new node;
        nnode->next = NULL;
        cout << endl << "Enter PRN number: ";
        cin >> nnode->prn;
        cout << "Enter name of user: ";
        cin >> nnode->name;

        if (head == NULL) 
        {
            head = tail = nnode;
        } 
        else 
        {
            tail->next = nnode;
            tail = nnode;
        }
        cout << "Do you want to continue (y/n): ";
        cin >> ch;
    } while(ch == 'y' || ch == 'Y');

    dplay();
}

void SLLPin::dplay() 
{
    temp = head;
    if (temp == NULL) 
    {
        cout << endl << "Club is empty!";
        return;
    }

    cout << endl << "Club Members:";
    while (temp != NULL) 
    {
        cout << endl << "PRN: " << temp->prn << "  Name: " << temp->name;
        temp = temp->next;
    }
    cout << endl;
}

void SLLPin::insertAtBeginning() 
{ 
    nnode = new node;
    nnode->next = NULL;
    cout << endl << "Enter president name: ";
    cin >> nnode->name;
    cout << "Enter PRN of president: ";
    cin >> nnode->prn;

    nnode->next = head;
    head = nnode;
    dplay();
}

void SLLPin::insertAtEnd() 
{
    nnode = new node;
    nnode->next = NULL;
    cout << endl << "Enter secretary name: ";
    cin >> nnode->name;
    cout << "Enter PRN of secretary: ";
    cin >> nnode->prn;

    if (tail != NULL)
    {
        tail->next = nnode;
        tail = nnode;
    }
    else
    {
        head = tail = nnode;
    }

    dplay();
}

void SLLPin::intermediate() 
{
    cout << endl << "Intermediate insertion";
    int key;
    cout << endl << "Enter the PRN of club member after which you want to insert: ";
    cin >> key;

    nnode = new node;
    nnode->next = NULL;
    cout << "Enter PRN number to insert: ";
    cin >> nnode->prn;
    cout << "Enter name of user: ";
    cin >> nnode->name;

    temp = head;
    while (temp != NULL && temp->prn != key) 
    {
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        cout << "PRN not found!";
        delete nnode;
        return;
    }

    nnode->next = temp->next;
    temp->next = nnode;
    if (temp == tail) tail = nnode;

    dplay();
}

void SLLPin::count() 
{
    int c = 0;
    temp = head;
    while (temp != NULL) 
    {
        c++;
        temp = temp->next;
    }
    cout << endl << "Total number of members: " << c << endl;
}

int main() 
{
    SLLPin l1;
    cout << endl << "Welcome to pinnacle club" << endl;
    l1.crt();
    l1.insertAtBeginning();
    l1.insertAtEnd();
    l1.intermediate();
    l1.count();
}
