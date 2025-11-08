#include <iostream>
#include <string>
using namespace std;

struct node 
{
    int seatno;
    int status; 
    node *next, *prev;
};

node* a[11]; 

class list 
{
public:

    list() 
	{
        for (int i = 1; i <= 10; i++)
            a[i] = NULL;
    }

    void crt();
    void displayavailableseat();
    void bookedseat();
    void cancelseat();
};

void list::crt() 
{
    cout <<endl<< "Creating seats for 10 rows & each having 7 seats:"<<endl;
    for (int r = 1; r <= 10; r++) 
	{
        node *head = NULL, *tail = NULL;

        for (int s = 1; s <= 7; s++) 
		{
            node *nnode = new node;
            nnode->seatno = s;

            if (s % 2 == 0)
                nnode->status = 1; 
            else
                nnode->status = 0; 

            nnode->next = nnode->prev = NULL;

            if (head == NULL)
                head = tail = nnode;
            else {
                tail->next = nnode;
                nnode->prev = tail;
                tail = nnode;
            }
        }
        a[r] = head;
    }
    displayavailableseat();
}

void list::displayavailableseat() 
{
    cout <<endl<< "Available seats:"<<endl;
    for (int r = 1; r <= 10; r++) 
	{
        node *temp = a[r];
        cout << "Row " << r << ": ";
        while (temp != NULL) 
		{
            if (temp->status == 0)
                cout << temp->seatno << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void list::bookedseat() 
{
    cout <<endl<< "Booked seats:"<<endl;
    for (int r = 1; r <= 10; r++) 
	{
        node *temp = a[r];
        cout << "Row " << r << ": ";
        int match = 0;
        while (temp != NULL) 
		{
            if (temp->status == 1) 
			{
                cout << temp->seatno << " ";
                match = 1;
            }
            temp = temp->next;
        }
        if (!match)
            cout << "none";
        cout << endl;
    }
}


void list::cancelseat() 
{
    bookedseat();

    string p, ch;
    cout <<endl<< "Do you want to cancel seats?: "<<endl;
    cin >> p;

    if (p == "y") 
	{
        int row, seat;
        do 
		{
            cout <<endl<< "Enter row number: "<<endl;
            cin >> row;
            cout << "Enter seat number in row " << row << "  ";
            cin >> seat;

            node *temp = a[row];
            while (temp != NULL && temp->seatno != seat)
                temp = temp->next;

            if (temp == NULL) 
			{
                cout << "Invalid seat number!"<<endl;
            } else if (temp->status == 0) 
			{
                cout << "Seat is already available!"<<endl;
            } else 
			{
                temp->status = 0;
                cout << "congratulations Seat " << seat << " in row " << row << " has been cancelled."<<endl;
            }

            cout <<endl<< "Do you want to cancel more seats: ";
            cin >> ch;
        } while (ch == "y");

        displayavailableseat();
    }
}

int main() 
{
    cout << " Welcome to Cinemax Theater"<<endl;

    list l1;
    l1.crt();     
    l1.cancelseat();  

    cout <<endl<< "Thank you for visiting Cinemax!"<<endl;
}

