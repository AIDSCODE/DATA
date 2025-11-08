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
    void dltbegin();
    void dltlast();
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
void SLLPin::dltbegin() 
{
	
    if (head == NULL) return;

    temp = head;
    cout << endl << "You deleted president = " << temp->name;
    head = temp->next;
    delete temp;

    if (head == NULL) tail = NULL;

    dplay();
}

void SLLPin::dltlast() 
{
    if (head == NULL) return;

    if (head == tail) 
    {
        cout << endl << "You deleted secretary = " << tail->name;
        delete tail;
        head = tail = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != tail) 
        {
            temp = temp->next;
        }
        cout << endl << "You deleted secretary = " << tail->name;
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

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
    l1.dltbegin();
    l1.dltlast();
    l1.count();
    l1.dplay();
}
