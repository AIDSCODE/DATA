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
    void count();
    void concatenation(SLLPin &L2);  
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

void SLLPin::concatenation(SLLPin &L2) 
{
    if (L2.head == NULL) return; 
    if (head == NULL) 
    {
        head = L2.head;
        tail = L2.tail;
    } 
    else 
    {
        tail->next = L2.head;
        tail = L2.tail;
    }
}

int main() 
{
    SLLPin l1;
    cout << endl << "Welcome to club 1" << endl;
    l1.crt();

    // second club
    SLLPin l2;
    cout << endl << "Welcome to club 2" << endl;
    l2.crt();

    // concatenation
    cout << endl << "Concatenating club 2 into club 1..." << endl;
    l1.concatenation(l2);

    l1.count();
    l1.dplay();
}
